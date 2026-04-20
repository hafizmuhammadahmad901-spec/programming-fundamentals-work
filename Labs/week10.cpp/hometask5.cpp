#include <iostream>

using namespace std;

float calculateSalary(float base, int score, int experience) 
{
    float bonusPercentage = 0.0;

    if (score >= 90) 
    {
        bonusPercentage = 0.20;
    }
    else if (score >= 75 && score <= 89) 
    {
        bonusPercentage = 0.10;
    }
    else 
    {
        bonusPercentage = 0.05;
    }

    if (experience >= 5) 
    {
        bonusPercentage = bonusPercentage + 0.05;
    }

    float totalBonusAmount = base * bonusPercentage;
    float finalSalary = base + totalBonusAmount;

    return finalSalary;
}

int main() 
{
    float baseSalary;
    int performanceScore, yearsOfExperience;

    cout << "Enter Base Salary: ";
    cin >> baseSalary;
    cout << "Enter Performance Score (0-100): ";
    cin >> performanceScore;
    cout << "Enter Years of Experience: ";
    cin >> yearsOfExperience;

    float result = calculateSalary(baseSalary, performanceScore, yearsOfExperience);

    cout << "Final Salary: $" << result << endl;

    return 0;
}