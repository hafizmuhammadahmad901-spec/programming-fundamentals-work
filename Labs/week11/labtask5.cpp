#include <iostream>
using namespace std;

int main() {
    int matrix[3][3];

    
    cout << "Enter elements of 3x3 matrix:";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> matrix[i][j];
        }
    }

    bool isIdentity = true;

    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            if (i == j) {
                
                if (matrix[i][j] != 1) {
                    isIdentity = false;
                }
            } else {
                
                if (matrix[i][j] != 0) {
                    isIdentity = false;
                }
            }
        }
    }

   
    if (isIdentity)
        cout << "\nIt is an Identity Matrix.";
    else
        cout << "\nIt is NOT an Identity Matrix.";

    return 0;
}