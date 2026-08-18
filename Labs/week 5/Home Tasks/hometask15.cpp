#include<iostream>
using namespace std;
int main() {
    int number;
    int count = 0;
    cout<<"ENTER A NUMBER :"<<endl;
    cin>>number;
    while(number>=0) {
        number = number/10;
        count++;

    }
    cout<<"THE NUMBER OF DIGITS WILL BE :"<<count<<endl;
    return 0;
}