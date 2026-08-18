from fastapi import FastAPI

from app.routes import health
from app.routes import report

from app.database import Base
from app.database import engine


# Create database tables
Base.metadata.create_all(bind=engine)


# Create FastAPI app
app = FastAPI(
    title="Visibility Report API",
    description="Generates a mini AI visibility report for a local business",
    version="0.1.0"
)


# Add health routes
app.include_router(health.router)


# Add report routes
app.include_router(report.router)


# Add all reports routes
app.include_router(report.reports_router)


# Home page
@app.get("/")
def root():

    return {
        "message": "Visibility Report API is running"
    }