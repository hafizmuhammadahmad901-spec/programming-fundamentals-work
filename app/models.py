from sqlalchemy import Column, Integer, String, JSON, DateTime
from sqlalchemy.sql import func

from app.database import Base


class Report(Base):

    __tablename__ = "reports"

    id = Column(Integer, primary_key=True)

    business_name = Column(String, nullable=False)

    location = Column(String, nullable=False)

    visibility_score = Column(Integer, nullable=False)

    evaluation = Column(String, nullable=False)

    gaps = Column(JSON, nullable=False)

    recommendations = Column(JSON, nullable=False)

    estimated_leak = Column(String, nullable=False)

    created_at = Column(
        DateTime(timezone=True),
        server_default=func.now()
    )