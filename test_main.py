from fastapi.testclient import TestClient

from app.main import app


# Create test client
client = TestClient(app)


# -----------------------------
# TEST HEALTH API
# -----------------------------
def test_health():

    response = client.get("/api/health")

    assert response.status_code == 200

    assert response.json()["status"] == "ok"


# -----------------------------
# TEST GENERATE REPORT
# -----------------------------
def test_generate_report():

    response = client.post(
        "/api/report/generate?business_name=Test Cafe&location=Lahore"
    )

    assert response.status_code == 200

    data = response.json()

    assert data["business_name"] == "Test Cafe"

    assert "visibility_score" in data

    assert "id" in data


# -----------------------------
# TEST EMPTY BUSINESS NAME
# -----------------------------
def test_empty_business_name():

    response = client.post(
        "/api/report/generate?business_name=&location=Lahore"
    )

    assert response.status_code == 400


# -----------------------------
# TEST EMPTY LOCATION
# -----------------------------
def test_empty_location():

    response = client.post(
        "/api/report/generate?business_name=Test Cafe&location="
    )

    assert response.status_code == 400


# -----------------------------
# TEST GET REPORT BY ID
# -----------------------------
def test_get_report():

    # First create a report
    response = client.post(
        "/api/report/generate?business_name=Test Cafe&location=Lahore"
    )

    data = response.json()

    report_id = data["id"]

    # Now get the same report
    response = client.get(
        f"/api/report/{report_id}"
    )

    assert response.status_code == 200

    data = response.json()

    assert data["business_name"] == "Test Cafe"


# -----------------------------
# TEST REPORT NOT FOUND
# -----------------------------
def test_report_not_found():

    response = client.get(
        "/api/report/999999"
    )

    assert response.status_code == 404


# -----------------------------
# TEST GET ALL REPORTS
# -----------------------------
def test_all_reports():

    response = client.get(
        "/api/reports"
    )

    assert response.status_code == 200

    data = response.json()

    assert len(data) > 0


# -----------------------------
# TEST INVALID LIMIT
# -----------------------------
def test_invalid_limit():

    response = client.get(
        "/api/reports?limit=0"
    )

    assert response.status_code == 400