#include <iostream>

using namespace std;

float calculateBalance(float balance, int years) 
{
    float interestRate = 0.0;

    if (balance < 10000) 
    {
        interestRate = 0.05;
    }
    else if (balance >= 10000 && balance <= 50000) 
    {
        interestRate = 0.07;
    }
    else 
    {
        interestRate = 0.10;
    }

    if (years >= 3) 
    {
        interestRate = interestRate + 0.02;
    }

    float interestAmount = balance * interestRate;
    float updatedBalance = balance + interestAmount;

    return updatedBalance;
}

int main() 
{
    float currentBalance;
    int accountYears;

    cout << "Enter current balance: ";
    cin >> currentBalance;
    cout << "Enter number of years the account has been active: ";
    cin >> accountYears;

    float finalAmount = calculateBalance(currentBalance, accountYears);

    cout << "Your updated balance after interest is: " << finalAmount << endl;

    return 0;
}