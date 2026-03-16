#include<iostream>
using namespace std;
int main(){
    int n;
    int sum = 0;
    cout<<"Enter the number: ";
    for(int i = 1; ; i = i + 1)
    {
        cout<<"ENTER A POSITIVE NUMBER: ";
        cin>>n;
        if (n < 0) break;
        sum += n;
    }
    cout<<"SUM OF POSITIVE NUMBERS IS: "<<sum<<endl;
    return 0;
}
