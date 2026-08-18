#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of resistors: ";
    cin >> n;

    float resistance[100];
    float total = 0;

    
    cout << "Enter resistance values (in ohms):\n";
    for(int i = 0; i < n; i++)
    {
        
        cin >> resistance[i];
        total = total + resistance[i];
    }

    
    cout << "Total Resistance (RT) = " << total << " ohms";

    return 0;
}