#include<iostream>
using namespace std;
int main() {
    int speed;
    cout<<"ENTER SPEED OF VEHICLE:";
    cin>>speed;
    if(speed<10) {
        cout<<"SPEED IS VERY SLOW:";

    }
    if(speed>=10 && speed<=50) {
        cout<<"SPEED IS AVERAGE:";

    }
    if(speed>50 && speed<=150) {
         cout<<"SPEED IS FAST:";

    }
    if(speed>150 && speed<=1000) {
         cout<<"SPEED IS ULTRA FAST:";
       

    }

    
}