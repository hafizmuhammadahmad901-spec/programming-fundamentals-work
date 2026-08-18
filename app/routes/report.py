from fastapi import APIRouter, Depends, HTTPException
from sqlalchemy.orm import Session

from app.scoring import generate_report
from app.database import get_db
from app.models import Report


# Router for single report operations
router = APIRouter(
    prefix="/api/report",
    tags=["report"]
)


# Router for all reports
reports_router = APIRouter(
    prefix="/api/reports",
    tags=["report"]
)


# --------------------------------
# CREATE A NEW REPORT
# --------------------------------
@router.post("/generate")
def create_report(
    business_name: str,
    location: str,
    db: Session = Depends(get_db)
):

    # Check business name
    if business_name.strip() == "":
        raise HTTPException(
            status_code=400,
            detail="Business name cannot be empty"
        )

    # Check location
    if location.strip() == "":
        raise HTTPException(
            status_code=400,
            detail="Location cannot be empty"
        )

    # Generate report using scoring.py
    result = generate_report(
        business_name,
        location
    )

    # Create database object
    db_report = Report(
        business_name=result["business_name"],
        location=result["location"],
        visibility_score=result["visibility_score"],
        evaluation=result["evaluation"],
        gaps=result["gaps"],
        recommendations=result["recommendations"],
        estimated_leak=result["estimated_leak"]
    )

    # Save to database
    db.add(db_report)
    db.commit()
    db.refresh(db_report)

    # Add database information to result
    result["id"] = db_report.id
    result["created_at"] = db_report.created_at

    return result


# --------------------------------
# GET ONE REPORT BY ID
# --------------------------------
@router.get("/{report_id}")
def get_report(
    report_id: int,
    db: Session = Depends(get_db)
):

    # Find report
    db_report = db.query(Report).filter(
        Report.id == report_id
    ).first()

    # If report does not exist
    if db_report is None:
        raise HTTPException(
            status_code=404,
            detail="Report not found"
        )

    # Return report
    return {
        "id": db_report.id,
        "business_name": db_report.business_name,
        "location": db_report.location,
        "visibility_score": db_report.visibility_score,
        "evaluation": db_report.evaluation,
        "gaps": db_report.gaps,
        "recommendations": db_report.recommendations,
        "estimated_leak": db_report.estimated_leak,
        "created_at": db_report.created_at
    }


# --------------------------------
# GET ALL REPORTS
# --------------------------------
@reports_router.get("")
def list_reports(
    limit: int = 20,
    db: Session = Depends(get_db)
):

    # Check limit
    if limit < 1 or limit > 100:
        raise HTTPException(
            status_code=400,
            detail="Limit must be between 1 and 100"
        )

    # Get reports from database
    reports = db.query(Report).all()

    # Reverse list so newest reports appear first
    reports.reverse()

    # Limit the number of reports
    reports = reports[:limit]

    # Create empty list
    report_list = []

    # Add reports one by one
    for report in reports:

        single_report = {
            "id": report.id,
            "business_name": report.business_name,
            "location": report.location,
            "visibility_score": report.visibility_score,
            "evaluation": report.evaluation,
            "created_at": report.created_at
        }

        report_list.append(single_report)

    return report_list