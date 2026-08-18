#include<iostream>
using namespace std;
int num;
float mul(float a){
    float result = num * 5;
    return result;
}
int main() {
    float number;
    cout<<"ENTER A NUMBER"<<endl;
    cin>>number;
    float result;
    result = mul(number);
    cout<<"RESULT WILL BE "<<number * 5<<endl;
}