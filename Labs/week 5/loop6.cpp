#include<iostream>
using namespace std;
int main() {
    int table = 5;
    int multiple;
   
    
    for(int num = 1; num <= 10; num = num + 1)
    {
        cout<<"TABLE OF "<<table<<endl;
        multiple = table * num;
        cout<<table<<" * "<<num<<" = "<<multiple<<endl;
    }
}