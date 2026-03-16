#include <iostream>
using namespace std;

int main() {

    double money;
    int year;
    cout<<"ENTER TOTAL MONEY YOU HAVE"<<endl;
    cin >> money;
    cout<<"ENTER YEAR"<<endl;
    cin >> year;

    int age = 18;
    double spent = 0;

    for(int i = 1800; i <= year; i++) {

        if(i % 2 == 0) {
            spent += 12000;
        }
        else {
            spent += 12000 + 50 * age;
        }

        age++;
    }

    if(money >= spent) {
        int remaining = money - spent;
        cout << "Yes! He will live a carefree life and will have " << remaining << " dollars left." << endl;
    }
    else {
        int money_for_survival = spent - money;
        cout << "He will need " <<money_for_survival << " dollars to survive." << endl;
    }

    return 0;
}