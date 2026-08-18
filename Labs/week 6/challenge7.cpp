#include <iostream>
using namespace std;

int main()
{
    int first[2];     
    int n;

    
    cout << "Enter 2 elements for first array:\n";
    for(int i = 0; i < 2; i++)
    {
        cin >> first[i];
    }

    
    cout << "Enter size of second array: ";
    cin >> n;

    int second[100];

    cout << "Enter elements of second array:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> second[i];
    }

   
    int result[102];

    
    result[0] = first[0];

    
    for(int i = 0; i < n; i++)
    {
        result[i + 1] = second[i];
    }

    
    result[n + 1] = first[1];

    
    cout << "Resulting array:\n";
    for(int i = 0; i < n + 2; i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}