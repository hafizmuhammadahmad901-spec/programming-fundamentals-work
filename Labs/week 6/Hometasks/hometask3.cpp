#include <iostream>

using namespace std;


void findMinMax(int arr[], int n) {
  
    int smallest = arr[0];
    int largest = arr[0];

    
    for (int i = 1; i < n; i++) {
        
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
        
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    
    cout << "\n----------------------------" << endl;
    cout << "Smallest Number: " << smallest << endl;
    cout << "Largest Number: " << largest << endl;
    cout << "----------------------------" << endl;
}

int main() {
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    
    if (n <= 0) {
        cout << "Invalid array size." << endl;
        return 1;
    }

    int numbers[n];

    
    cout << "Enter " << n << " numbers:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Element " << (i + 1) << ": ";
        cin >> numbers[i];
    }

    
    findMinMax(numbers, n);

    return 0;
}