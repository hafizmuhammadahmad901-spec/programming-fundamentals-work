#include<iostream>
using namespace std;
int main() {
   string flower;
   string red_roses;
   string white_roses;
   string tulips;
   cout<<"ENTER THE NUMBER OF RED ROSES :";
    cin>>red_roses;
    cout<<"ENTER THE NUMBER OF WHITE ROSES :";
    cin>>white_roses;
    cout<<"ENTER THE NUMBER OF TULIPS :";
    cin>>tulips;
    float price_of_red_roses = 2.50 * stoi(red_roses);
    float price_of_white_roses = 4.10 * stoi(white_roses);
    float price_of_tulips = 2.00 * stoi(tulips);
    int total_flowers = stoi(red_roses) + stoi(white_roses) + stoi(tulips);
    float total_price = price_of_red_roses + price_of_white_roses + price_of_tulips;
    float discounted_price;
    int discount= total_price * 20 / 100;
    discounted_price = total_price - (total_price*20)/100;
    int original_price = total_price - discount;
    cout<<"TOTAL NUMBER OF FLOWERS :"<<total_flowers<<endl;

    if(total_price>200){
         cout<<"YOU'LL GET A 20% DISCOUNT ON YOUR PURCHASE: $"<<discounted_price<<endl;
         cout<<"ORIGINAL PRICE: $"<<original_price<<endl;
         cout<<"price after discount: $"<<discounted_price<<endl;   
         cout<<"TOTAL PRICE: $"<<total_price<<endl;

    }
    else{
        cout<<"NO DISCOUNT APPLIED. TOTAL PRICE: $"<<total_price<<endl;
    }
    
    
    return 0;
}
