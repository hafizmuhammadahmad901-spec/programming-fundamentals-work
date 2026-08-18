#include<iostream>
using namespace std;
int add(int num1,int num2){
    return num1 + num2;



   
}
int main() {
    int number1;
    int number2;
    
    cout<<"ENTER A NUMBER"<<endl;
    cin>>number1;
    cout<<"ENTER A NUMBER2"<<endl;
    cin>>number2;
     int sum = add(number1,number2);
     cout<<sum<<endl;

     return 0;


    }
