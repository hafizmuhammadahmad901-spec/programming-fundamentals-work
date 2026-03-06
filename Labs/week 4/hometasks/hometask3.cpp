#include<iostream>
using namespace std;
int main() {
    int temperature1;
    int temperature2;
    int city1;
    int city2;
    int difference;
    
    cout<<"ENTER TEMPERATURE OF 1ST CITY :";
    cin>>temperature1;
    cout<<"ENTER TEMPERATURE OF 2ND CITY :";
    cin>>temperature2;
    difference = temperature1 - temperature2;
    if(difference >10) {
        cout<<"THE DIFFERENCE ID TOO BIG"<<endl;

    }
    else{
        cout<<"PROGRAM ENDS HERE"<<endl;
    }



     
    
}