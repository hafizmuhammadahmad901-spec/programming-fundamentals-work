#include <iostream>
using namespace std;


string fire(char grid[5][5], string coord) {
    
    int row = coord[0] - 'A';  
    int col = coord[1] - '1';  

    if (grid[row][col] == '*')
        return "BOOM";
    else
        return "splash";
}

int main() {

    
    char grid[5][5] = {
        {'.', '*', '.', '.', '.'},
        {'.', '*', '.', '*', '.'},
        {'.', '.', '.', '*', '.'},
        {'*', '*', '.', '.', '.'},
        {'.', '.', '.', '*', '*'}
    };

    string coord;

    cout << "Enter coordinate (e.g., A1, B3): ";
    cin >> coord;

    cout << fire(grid, coord);

    return 0;
}