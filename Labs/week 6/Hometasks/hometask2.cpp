#include <iostream>

using namespace std;

int main() {
    int n;
    int evenCount = 0;

    
    cout << "Enter the number of elements: ";
    cin >> n;

    
    int numbers[n];

    
    cout << "Enter " << n << " numbers:" << endl;
    for (int i = 0; i < i < n; i++) {
        cout << "Element " << (i + 1) << ": ";
        cin >> numbers[i];
    }

    
    for (int i = 0; i < n; i++) {
        if (numbers[i] % 2 == 0) {
            evenCount++; 
        }
    }

    
    cout << "\n----------------------------" << endl;
    cout << "Total even numbers: " << evenCount << endl;
    cout << "----------------------------" << endl;

    return 0;
}