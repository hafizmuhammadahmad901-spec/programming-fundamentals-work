#include <iostream>
using namespace std;

void printGrid(char grid[][5], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 5; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

void moveDown(char grid[][5], int rows, int &row, int col, bool isBlackHole) {

    grid[row][col] = '.';

    if (row == rows - 1) {
        if (isBlackHole)
            row = 0;          // teleport
        else
            row = rows - 1;   // stay
    } else {
        row++;
    }

    grid[row][col] = '*';
}

int main() {

    const int rows = 5;
    char grid[rows][5];

    // Initialize grid
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < 5; j++)
            grid[i][j] = '.';

    int row = 4;   // start at last row
    int col = 2;

    grid[row][col] = '*';

    bool isBlackHole = true;   // change to false to test

    cout << "Before Move:\n";
    printGrid(grid, rows);

    moveDown(grid, rows, row, col, isBlackHole);

    cout << "\nAfter Move:\n";
    printGrid(grid, rows);

    return 0;
}