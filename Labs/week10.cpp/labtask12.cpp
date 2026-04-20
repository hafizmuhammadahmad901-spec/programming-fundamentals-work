#include <iostream>
using namespace std;
string isEven(int num){
    int sum = 0;
    int temp = num;
    while(temp>0) {
        sum = sum + (temp%10);
        temp = temp%10;
        if(sum%2==0){
            return "Even";
        }
        else{
            return "Odd";
        }
    }
}
int main() {
    int userinput;
    cout<<"ENTER A NUMBER :";
    cin>>userinput;
    string result = isEven(userinput);
    cout<<userinput<<" is "<<result<<endl;  

    return 0;
}