"""
Health check endpoint — confirms the server is alive.
"""

from fastapi import APIRouter

router = APIRouter(prefix="/api", tags=["health"])


@router.get("/health")
def health_check():
    return {"status": "ok"}
