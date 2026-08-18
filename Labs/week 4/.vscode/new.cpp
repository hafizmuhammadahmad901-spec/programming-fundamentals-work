#include<iostream>
using namespace std;
int main()
{
    string hardcore = "1234";
    string userpass;
    cout<<"ENTER THE PASSWORD :";
    cin>>userpass;
    if(userpass==hardcore){
        cout<<"ACCESS GRANTED";
    }
    else{
        cout<<"ACCESS DENIED";
    }
    return 0;
}