#include<iostream>
using namespace std;
int main() {
    int num;
    int digits;
    int frequency;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Enter the digit you want to find the frequency of: ";
    cin >> digits;
    frequency = 0;
    while(num > 0) {
        int lastDigit = num % 10;
        if(lastDigit == digits) {
            frequency++;
        }
        num = num / 10;
    }
    cout << "The frequency of digit " << digits << " in the number " << num << " is: " << frequency << endl;
    return 0;
}