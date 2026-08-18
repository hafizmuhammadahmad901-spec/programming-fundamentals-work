#include <iostream>
using namespace std;

void largestColumnFirst(int M[][5], int rows) {

    int maxSum = -999999;
    int maxCol = 0;

    
    for (int j = 0; j < 5; j++) {
        int sum = 0;

        for (int i = 0; i < rows; i++) {
            sum += M[i][j];
        }

        if (sum > maxSum) {
            maxSum = sum;
            maxCol = j;
        }
    }

    
    for (int i = 0; i < rows; i++) {
        int temp = M[i][0];
        M[i][0] = M[i][maxCol];
        M[i][maxCol] = temp;
    }
}


void printMatrix(int M[][5], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 5; j++) {
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {

    int rows = 4;

    int M[4][5] = {
        {1, 2, 3, 4, 5},
        {5, 4, 3, 2, 1},
        {2, 2, 2, 2, 2},
        {9, 1, 1, 1, 1}
    };

    cout << "Original Matrix:\n";
    printMatrix(M, rows);

    largestColumnFirst(M, rows);

    cout << "\nAfter largestColumnFirst:\n";
    printMatrix(M, rows);

    return 0;
}