#include <iostream>
using namespace std;
int main() {
    int x = 10;
    int *ptr = &x;
    cout<<"value of x"<<x<<endl;
    cout<<"address of x"<<&x<<endl;
    cout<<"value at pointer ptr"<<*ptr<<endl;

    return 0;
}