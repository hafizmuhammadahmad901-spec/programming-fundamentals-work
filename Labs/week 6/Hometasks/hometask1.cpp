#include <iostream>

using namespace std;

int main() {
    int n;
    int sum = 0;

    
    cout << "Enter the number of elements: ";
    cin >> n;

    
    int numbers[n];

    
    cout << "Enter " << n << " numbers:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Element " << (i + 1) << ": ";
        cin >> numbers[i];
    }

    
    for (int i = 0; i < n; i++) {
        sum = sum + numbers[i]; 
    }

    cout << "\n----------------------------" << endl;
    cout << "The total sum is: " << sum << endl;
    cout << "----------------------------" << endl;

    return 0;
}