#include<iostream>
using namespace std;
int main() {
    int table;
    int multiple;
    int number;
    cout << "Enter the number you want to find the multiplication table of: ";
    cin >> number;
    for(table = 1; table <= 10; table++) {
        multiple = number * table;
        cout << number << " x " << table << " = " << multiple << endl;
    }
    return 0;

    
}