#include <iostream>

using namespace std;

int main() {
    
    int n;
    int number;
    int p1 = 0, p2 = 0, p3 = 0, p4 = 0, p5 = 0;

    cout << "Enter how many numbers: ";
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cout << "Enter number: ";
        cin >> number;

        if(number < 200) {
            p1++;
        }
        else if(number >= 200 && number <= 399) {
            p2++;
        }
        else if(number >= 400 && number <= 599) {
            p3++;
        }
        else if(number >= 600 && number <= 799) {
            p4++;
        }
        else {
            p5++;
        }
    }

    
    cout << "p1 percentage: " << (p1 * 100.0 / n) << "%" << endl;
    cout << "p2 percentage: " << (p2 * 100.0 / n) << "%" << endl;
    cout << "p3 percentage: " << (p3 * 100.0 / n) << "%" << endl;
    cout << "p4 percentage: " << (p4 * 100.0 / n) << "%" << endl;
    cout << "p5 percentage: " << (p5 * 100.0 / n) << "%" << endl;

    return 0;
}