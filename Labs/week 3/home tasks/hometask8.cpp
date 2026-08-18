#include<iostream>
using namespace std;
int main() {
double veg_price;
double fruit_price;
int veg_kg;
int fruit_kg;

cout<<"ENTER VEGETABLE PRICE PER KG:";
cin>>veg_price;
cout<<"ENTER FRUIT PRICE PER KG:";
cin>>fruit_price;
cout<<"ENTER WEIGHT OF VEGETABLE:";
cin>>veg_kg;
cout<<"ENTER WEIGHT OF FRUITS:";
cin>>fruit_kg;

double total_coins = (veg_price * veg_kg) + (fruit_price * fruit_kg);
double rupees = total_coins/1.94;
cout<<"rupees are = " <<rupees;
}
