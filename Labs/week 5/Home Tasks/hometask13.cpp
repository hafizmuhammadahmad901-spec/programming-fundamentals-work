#include<iostream>
using namespace std;
int main() {
    int table;
    int multiple;
    int number;
    cout<<"ENTER NUMBER TO PRINT ITS TABLE :"<<endl;
        cin>>number;
    for(int table = 1; table<=10; table = table + 1) {
       
        multiple = number * table;
        cout<<number<<"x"<<table<<"="<<multiple<<endl;
}
return 0;

    }
    
