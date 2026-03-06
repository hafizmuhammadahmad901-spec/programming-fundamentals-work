#include<iostream>
#include<string>
using namespace std;
int main() {
    int ticket_price;
    string country_name = "Ireland";
    int discounted_price;
    cout<<"ENTER THE PRICE OF TICKET :";
    cin>>ticket_price;
    
    cout<<"ENTER THE NAME OF COUNTRY :";
    cin>>country_name;
    if(country_name=="Ireland"){
        discounted_price = ticket_price - (ticket_price*10)/100;
        cout<<"YOU'LL GET A 10% DISCOUNT ON YOUR PURCHASE"<<(ticket_price*10)/100;
        cout<<"THE DISCOUNT AMOUNT IS : "<<discounted_price;
    }
    else{
        discounted_price = ticket_price - (ticket_price*5)/100;
        cout<<"YOU'll get a 5% DISCOUNT ON YOUR PURCHASE"<<(ticket_price*5)/100<<endl;
        cout<<"THE DISCOUNT AMOUNT IS : "<<discounted_price;
    }
    

}