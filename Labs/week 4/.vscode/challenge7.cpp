#include<iostream>
using namespace std;
int main() {
    char ch ;
    int num1;
    int num2;
    cout<<"ENTER FIRST NUMBER:";
    cin>>num1;
    cout<<"ENTER SECOND NUMBER";
    cin>>num2;
    cout<<"ENTER THE OPERATOR (+, -, *, /) :";
    cin>>ch;
    if(ch=='+') {
        cout<<"subtraction is =  "<<num1-num2;


    }
     if(ch=='-') {
        cout<<"addition is =  "<<num1+num2;
    }
    if(ch=='*') {
        cout<<"division is =  "<<num1/num2;
    }
    if(ch=='/') {
        cout<<"multiplication is =  "<<num1*num2;
    }
    else{
        cout<<"invalid character";
    }


    
 



}