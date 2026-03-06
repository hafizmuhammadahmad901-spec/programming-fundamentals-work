#include<iostream>
using namespace std;
int main() {
    
    int speed;
    cout<<"ENTER SPEED OF VEHICLE :";
    cin>>speed;

   
    if(speed>100) {
        cout<<"Halt.... You will be charged for over speeding."<<endl;
    }
    if(speed<=100) {
        cout<<"Perfect! You are doing good. Keep it up."<<endl;

    }
    

    return 0;
}
