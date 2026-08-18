# Mini AI Visibility Report Generator

A small FastAPI backend that generates a "visibility score" report for a local
business — inspired by Foundrly's AI Visibility Report tool. Built as a
1-week beginner learning project.

Given a business name and location, it scores the business across 4 areas
(Google Business Profile completeness, review sentiment, photo coverage,
competitor ranking), lists the gaps found, and saves the report to a database
so it can be looked up later.

> **Note:** Business data is currently generated from mock/simulated values
> (see `app/scoring.py` → `get_mock_business_data()`). It is structured to be
> a drop-in replacement for a real Google Places API call later — the rest of
> the app (scoring, database, endpoints) will not need to change.

---

## Tech Stack

- **FastAPI** — web framework
- **SQLAlchemy** — ORM / database layer
- **SQLite** — database (single file, no server needed)
- **Pydantic** — request validation
- **pytest** — automated testing

---

## Project Structure

```
visibility-report/
├── requirements.txt
├── test_main.py            # automated tests
└── app/
    ├── main.py              # app entrypoint, registers routers
    ├── database.py           # DB engine/session setup
    ├── models.py              # SQLAlchemy Report table model
    ├── scoring.py              # core scoring logic (mock data for now)
    └── routes/
        ├── health.py            # GET /api/health
        └── report.py             # report generate/get/list endpoints
```

---

## Setup

```bash
# 1. Create and activate a virtual environment
python -m venv venv
source venv/bin/activate        # Windows: venv\Scripts\activate

# 2. Install dependencies
pip install -r requirements.txt

# 3. Run the server
uvicorn app.main:app --reload
```

The API will be running at `http://127.0.0.1:8000`.
Interactive docs (Swagger UI): `http://127.0.0.1:8000/docs`

A `visibility.db` SQLite file will be created automatically in the project
folder the first time the app runs.

---

## Endpoints

| Method | Endpoint | Description |
|---|---|---|
| GET | `/api/health` | Health check — confirms the server is running |
| POST | `/api/report/generate` | Generate a new visibility report and save it |
| GET | `/api/report/{report_id}` | Fetch a previously saved report by its ID |
| GET | `/api/reports?limit=20` | List the most recent reports (newest first) |

### Example: Generate a report

**Request**
```
POST /api/report/generate
Content-Type: application/json

{
  "business_name": "Cafe Aroma",
  "location": "Lahore"
}
```

**Response**
```json
{
  "business_name": "Cafe Aroma",
  "visibility_score": 71,
  "breakdown": {
    "gbp_completeness": 19,
    "review_sentiment": 21,
    "photo_coverage": 8,
    "competitor_rank": 23
  },
  "gaps": [
    "Business description is missing",
    "Only 3 photos uploaded — aim for 10+",
    "Rating (4.2) is below competitor average (4.6)"
  ],
  "recommendations": [
    "Fix: Business description is missing",
    "Fix: Only 3 photos uploaded — aim for 10+",
    "Fix: Rating (4.2) is below competitor average (4.6)"
  ],
  "estimated_leak": "$435/month potential lost visibility",
  "id": 1,
  "created_at": "2026-08-16T09:28:18"
}
```

### Example: Fetch a saved report

```
GET /api/report/1
```

### Example: List recent reports

```
GET /api/reports?limit=10
```

### Validation

- `business_name` and `location` cannot be empty or whitespace-only
  (returns `422 Unprocessable Entity` with an explanation).
- Requesting a `report_id` that doesn't exist returns `404 Not Found`.
- `limit` on the list endpoint must be between 1 and 100
  (returns `400 Bad Request` otherwise).

---

## Running Tests

```bash
pytest test_main.py -v
```

All 9 automated tests cover: health check, valid report generation, input
validation (empty/missing fields), fetching a report by ID, 404 handling for
missing reports, listing reports, and invalid `limit` values.

---

## Scoring Logic (how the 100-point score is built)

| Component | Max Points | Based on |
|---|---|---|
| GBP Completeness | 25 | Hours, category, description, phone number present |
| Review Sentiment | 25 | Average rating (out of 5) + review count |
| Photo Coverage | 25 | Number of photos (10+ = full marks) |
| Competitor Rank | 25 | Your rating vs. competitor average rating |

---

## Possible Next Steps

- Replace mock data in `scoring.py` with a real Google Places API call
- Add authentication so each user only sees their own reports
- Add a simple frontend form to submit a business name and view the report
