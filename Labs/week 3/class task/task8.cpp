#include<iostream>
using namespace std;
main() { 
int voltage;
int current;
int power;
cout<<"enter voltage in volts :";
cin>>voltage;
cout<<"enter time in seconds :";
cin>>current;
power = voltage*current;
cout<<"power in watts is :"<<power<<"watts";
}