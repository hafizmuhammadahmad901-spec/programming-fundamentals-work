#include<iostream>
using namespace std;
int main() {

    int n1 =0, n2 = 1, next;
    cout<<n1<<" "<<n2<<" ";
    for(int i = 0; i <=30; i++)
    {
        next = n1 + n2;
        cout<<next<<" ";
        n1 = n2;
        n2 = next;
    }
    return 0;
}