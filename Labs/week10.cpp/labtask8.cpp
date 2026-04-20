#include<iostream>
using namespace std;


float root_find(float val1,float val2,float val3){
float result = (val2 * val2) - 4  * (val1 * val3);
return result;


}
int main(){
    int n1;
    int n2;
    int n3;
    cout<<"ENTER A NNUMBER 1 :"<<endl;
    cin>>n1;
    cout<<"ENTER A NUMBER 2 :"<<endl;
    cin>>n2;
    cout<<"ENTER A NUMBER 3 "<<endl;
    cin>>n3;
    float result = root_find(n1,n2,n3);
    cout<<"result will be "<<result<<endl;


}



