#include <iostream>
using namespace std;


void printSum(int arr[][3], int rows) {
    int sum = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 3; j++) {
            sum += arr[i][j];
        }
    }

    cout << "Sum of all elements = " << sum << endl;
}

int main() {
    int rows;

    cout << "Enter number of rows: ";
    cin >> rows;

    int matrix[rows][3];   

    
    cout << "Enter elements of matrix: ";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> matrix[i][j];
        }
    }

    
    printSum(matrix, rows);

    return 0;
}