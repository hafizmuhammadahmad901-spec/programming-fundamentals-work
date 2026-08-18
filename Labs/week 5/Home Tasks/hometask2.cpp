#include<iostream>
using namespace std;
int main() {
    int sum = 0;
    int num = 0;
    while(num >= 0){
    sum = sum  + num;
    cout<<"Enter a number: "<<endl;
    cin>>num;
    cout<<"The sum of the numbers is: "<<sum<<endl;
}
}