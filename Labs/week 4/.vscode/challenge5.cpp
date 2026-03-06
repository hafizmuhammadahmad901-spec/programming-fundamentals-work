#include<iostream>
using namespace std;
int main() {
    int money;
    cout<<"ENTER THE AMOUNT OF MONEY YOU HAVE TO PAY:";
    cin>>money;
    if (money<=5000){
        cout<<"YOU'll GET 5% DISCOUNT";
        int discounted_bill = money - (money*0.05);
        cout<<"YOUR BILL AFTER DISCOUNT IS :"<<discounted_bill;
        
    }
    if(money>5000){
        cout<<"YOU'LL GET 10% DISCOUNT";
        int discounted_bill = money - (money*0.10);
        cout<<"YOUR BILL AFTER DISCOUNT IS :"<<discounted_bill;

    }

    

    

}
