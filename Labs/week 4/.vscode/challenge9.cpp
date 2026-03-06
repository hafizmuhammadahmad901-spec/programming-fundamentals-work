#include<iostream>
using namespace std;
int main() {
    string brodher1_name;
    int age1;
    int age2;
    int age3;
     cout<<"ENTER THE AGE OF BROTHER 1:";

     cin>>age1;
     cout<<"ENTER AGE OF 2ND BROTHER";
        cin>>age2;
        cout<<"ENTER AGE OF 3RD BROTHER";
        cin>>age3;
     
    
    string brodher2_name;
    string brodher3_name;
    cout<<"ENTER THE NAME OF FIRST BROTHER :";
    cin>>brodher1_name;
    cout<<"ENTER THE NAME OF SECOND BROTHER :";
    cin>>brodher2_name;
    cout<<"ENTER THE NAME OF THIRD BROTHER :";
    cin>>brodher3_name;
    if(age1<age2 && age1<age3){

        cout<<brodher1_name<<" is the younger brother";
    }
    else if(age2<age1 && age2<age3){
        cout<<brodher2_name<<" is the younger brother";
    }
    else if(age3<age1 && age3<age2){
        cout<<brodher3_name<<" is the younger brother";
    }
    else{
        cout<<"ALL THE BROTHERS ARE OF SAME AGE";
    }
}
