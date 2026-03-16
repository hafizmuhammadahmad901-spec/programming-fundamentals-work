#include<iostream>
using namespace std;
int main() {
    int sum = 0;
    int num;

    cout << "ENTER A NUMBER :" << endl;
    cin >> num;

    
    
    while (num > 0) {
        int digit = num % 10;
        sum += digit;
        num /= 10;
    }

    cout << "SUM OF DIGITS WILL BE : " << sum << endl;
    return 0;
}