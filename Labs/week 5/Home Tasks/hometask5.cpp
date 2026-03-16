#include<iostream>
using namespace std;
int main() {
    int sum = 0;
    int num  = 0;
    while(num<=100){
        sum = sum + num;
        num = num + 1;
        cout<<"The sum of the numbers is: "<<sum<<endl;
    }
    return 0;
}