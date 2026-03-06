#include<iostream>
using namespace std;
int main() {
    int money;
    int salary_per_month = 10000;
    int money_required = 50000;
    int extra_money = 5000;
    int months_required =  money_required/extra_money;
    cout << "ENTER THE AMOUNT OF MONEY YOU HAVE: ";
    cin >> money;
    if(money==extra_money){
        cout<<"you can buy a laptop:";
    }
    if(money<extra_money){
        cout<<"you will require " << months_required << " months to buy a laptop.";
    }
   
    return 0;
}