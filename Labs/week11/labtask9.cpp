#include <iostream>
using namespace std;

int countIdenticalRows(int arr[][3], int rows) {
    int count = 0;

    // Compare each pair of rows
    for (int i = 0; i < rows; i++) {
        for (int j = i + 1; j < rows; j++) {

            // Check if all 3 elements are equal
            if (arr[i][0] == arr[j][0] &&
                arr[i][1] == arr[j][1] &&
                arr[i][2] == arr[j][2]) {
                
                count++;
            }
        }
    }

    return count;
}

int main() {

    int arr[5][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {1, 2, 3},  // identical to row 0
        {7, 8, 9},
        {4, 5, 6}   // identical to row 1
    };

    int rows = 5;

    cout << "Total identical row pairs: "
         << countIdenticalRows(arr, rows);

    return 0;
}