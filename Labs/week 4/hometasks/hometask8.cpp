#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    string ones[] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    string teens[] = {"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
    string tens[] = {"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};

    if(n < 10)
        cout << ones[n];

    if(n >= 10)
        if(n < 20)
            cout << teens[n % 10];

    if(n >= 20)
        if(n < 100){
            cout << tens[n / 10];
            if(n % 10 > 0)
                cout << " " << ones[n % 10];
        }

    if(n == 100)
        cout << "one hundred";

    
}