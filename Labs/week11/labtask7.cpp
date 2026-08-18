#include <iostream>
using namespace std;


bool checkGoal(char field[7][16]) {

    
    for (int j = 6; j <= 9; j++) {
        if (field[0][j] == '0') {
            return true;
        }
    }

    return false;
}

int main() {

    char field[7][16] = {0};

    
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 16; j++) {
            field[i][j] = '.';
        }
    }

    
    field[0][7] = '0';  

    
    cout << "Field:\n";
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 16; j++) {
            cout << field[i][j] << " ";
        }
        cout << endl;
    }

   
    if (checkGoal(field))
        cout << "\nGOAL! 🎯";
    else
        cout << "\nMISS ❌";

    return 0;
}