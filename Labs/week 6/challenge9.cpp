#include <iostream>
using namespace std;

int main(){
    double total_due;
    int coins[4];  

    cout << "Enter number of quarters, dimes, nickels, pennies:\n";
    for(int i = 0; i < 4; i++)
    {
        cin >> coins[i];
    }

    cout << "Enter total due amount: ";
    cin >> total_due;

    
    double total = 0;
    total += coins[0] * 0.25;  
    total += coins[1] * 0.10;  
    total += coins[2] * 0.05;  
    total += coins[3] * 0.01;  
    
    if(total >= total_due)
        cout << "true (You can pay)";
    else
        cout << "false (Not enough money)";

    return 0;
}

