#include<iostream>
using namespace std;
int main() {
    int n;
    int rows;
    int columns;
    for(rows = 1; rows <= 5; rows++) {
        for(columns = 1; columns <= rows; columns++) {
            cout << "* ";
        }
        cout << endl;
    }
    for(rows = 5; rows >= 1; rows--) {
        for(columns = 1; columns <= rows; columns++) {
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}
    
    