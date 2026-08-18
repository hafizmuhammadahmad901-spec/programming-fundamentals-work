#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter how many numbers: ";
    cin >> n;

    int arr[100];

   
    cout << "Enter " << n << " numbers:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    
    int max = arr[0];

    
    for(int i = 1; i < n; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }

    cout << "Largest number = " << max;

    return 0;
}