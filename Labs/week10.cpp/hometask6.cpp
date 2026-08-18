#include <iostream>

using namespace std;

bool isStrong(int num) 
{
    int originalNum = num;
    int sum = 0;

    
    while (num > 0) 
    {
        int digit = num % 10;
        
        
        int factorial = 1;
        for (int i = 1; i <= digit; i++) 
        {
            factorial = factorial * i;
        }

        sum = sum + factorial;
        num = num / 10;
    }

    
    if (sum == originalNum) 
    {
        return true;
    }
    else 
    {
        return false;
    }
}

int main() 
{
    int userInput;

    cout << "Enter a number to check if it is a Strong Number: ";
    cin >> userInput;

    if (isStrong(userInput)) 
    {
        cout << userInput << " is a Strong Number!" << endl;
    }
    else 
    {
        cout << userInput << " is NOT a Strong Number." << endl;
    }

    return 0;
}
