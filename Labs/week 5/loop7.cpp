#include<iostream>
using namespace std;
int main() {
    int n;
    int num;
    int factorial = 1;
    cout<<"Enter a number: ";
    cin>>n;
    for(num = 1; num<=n; num++)
    {
        factorial = factorial * num;
    }
    cout<<"Factorial of "<<n<<" is: "<<factorial<<endl;
    return 0;
}