#include<iostream>
using namespace std;
int main() {
    int numbers[5];
    for(int count = 0; count<5; count= count + 1){
        cout<<"ENTER NUMBER :"<<endl;
        cin>>numbers[count];



    }
    cout<<"THE FIRST ELEMENT IN ARRAY IS:"<<numbers[0]<<endl;
    cout<<"THE LAST ELEMENT IN ARRAY IS :"<<numbers[4]<<endl;
    return 0;
}