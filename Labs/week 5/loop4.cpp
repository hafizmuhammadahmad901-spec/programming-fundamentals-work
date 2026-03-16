#include<iostream>
using namespace std;
int main(){
    int sum = 0;
    int num;
    
    cout<<"Enter the five numbers: ";
    
    
    for(int i = 1; i <=5; i = i+=1)
    {
        cout<<"ENTER NUMBER "<<i<<": ";
        cin>>num;
        sum = sum + num;
    }
    cout<<"The sum of the five numbers is: "<<sum<<endl;
    return 0;

}


