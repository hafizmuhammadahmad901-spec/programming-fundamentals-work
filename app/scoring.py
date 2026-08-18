"""
Day 2: Core visibility scoring logic.
Currently using mock data.
"""


def get_mock_business_data(business_name, location):

    name_length = len(business_name)

    if name_length < 5:
        data = {
            "has_hours": True,
            "has_category": True,
            "has_description": False,
            "has_phone": False,
            "average_rating": 3.5,
            "review_count": 5,
            "photo_count": 3,
            "competitor_rating": 4.5
        }

    elif name_length < 10:
        data = {
            "has_hours": True,
            "has_category": True,
            "has_description": True,
            "has_phone": True,
            "average_rating": 4.2,
            "review_count": 15,
            "photo_count": 7,
            "competitor_rating": 4.4
        }

    else:
        data = {
            "has_hours": True,
            "has_category": True,
            "has_description": True,
            "has_phone": True,
            "average_rating": 4.7,
            "review_count": 30,
            "photo_count": 12,
            "competitor_rating": 4.5
        }

    return data


def generate_report(business_name, location):

    data = get_mock_business_data(business_name, location)

    score = 0
    gaps = []
    recommendations = []


    if data["has_hours"] == True:
        score = score + 6
    else:
        gaps.append("Business hours are missing")
        recommendations.append("Add business hours")

    if data["has_category"] == True:
        score = score + 6
    else:
        gaps.append("Business category is missing")
        recommendations.append("Add business category")

    if data["has_description"] == True:
        score = score + 6
    else:
        gaps.append("Business description is missing")
        recommendations.append("Add business description")

    if data["has_phone"] == True:
        score = score + 7
    else:
        gaps.append("Phone number is missing")
        recommendations.append("Add phone number")



    if data["average_rating"] >= 4.5:
        score = score + 20

    elif data["average_rating"] >= 4.0:
        score = score + 16

    elif data["average_rating"] >= 3.5:
        score = score + 12

    else:
        score = score + 5
        gaps.append("Average rating is low")
        recommendations.append("Improve customer ratings")

    if data["review_count"] >= 20:
        score = score + 5

    elif data["review_count"] >= 10:
        score = score + 3

    else:
        score = score + 1
        gaps.append("Not enough reviews")
        recommendations.append("Ask customers for more reviews")



    if data["photo_count"] >= 10:
        score = score + 25

    elif data["photo_count"] >= 5:
        score = score + 15
        gaps.append("More photos are needed")
        recommendations.append("Upload more business photos")

    else:
        score = score + 5
        gaps.append("Not enough photos")
        recommendations.append("Upload at least 10 business photos")


    if data["average_rating"] >= data["competitor_rating"]:
        score = score + 25

    else:
        score = score + 15
        gaps.append("Competitor rating is higher")
        recommendations.append("Improve rating to compete with competitors")


    if score >= 80:
        evaluation = "Excellent"

    elif score >= 50:
        evaluation = "Good"

    else:
        evaluation = "Needs Improvement"

 

    lost_score = 100 - score
    leak_amount = lost_score * 15

    estimated_leak = "$" + str(leak_amount) + "/month potential lost visibility"


    return {
        "business_name": business_name,
        "location": location,
        "visibility_score": score,
        "evaluation": evaluation,
        "gaps": gaps,
        "recommendations": recommendations,
        "estimated_leak": estimated_leak
    }