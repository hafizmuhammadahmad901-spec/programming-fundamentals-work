#include <iostream>
using namespace std;

int main() {

    int age;
    double washingMachinePrice;
    int toyPrice;
    cout<<"ENTER YOUR AGE :"<<endl;
    cin >> age;
    cout<<"ENTER WASHING MACHINE PRICE :"<<endl;
    cin >> washingMachinePrice;
    cout<<"ENTER TOYS PRICE"<<endl;
    cin >> toyPrice;

    int toys = 0;
    double money = 0;
    int evenMoney = 10;

    for(int i = 1; i <= age; i++) {

        if(i % 2 == 0) { 
            money += evenMoney;
            money -= 1;          
            evenMoney += 10;     
        }
        else {
            toys++;              
        }
    }

    money =money + toys * toyPrice;    

    if(money >= washingMachinePrice) {
        cout << "Yes! " << money - washingMachinePrice << endl;
    }
    else {
        cout << "No! " << washingMachinePrice - money << endl;
    }

    return 0;
}