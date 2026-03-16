#include<iostream>
using namespace std;
int main() {
    int length;
    cout << "ENTER LENGTH OF A FIBONACCI SERIES YOU WANT TO PRINT : " << endl;
    cin >> length;
   
    int n1 = 0, n2 = 1;
   
    for(int i = 0; i < length; i++) {
        cout << n1 << " ";
        int next = n1 + n2;
        n1 = n2;
        n2 = next;
    }
    cout <<"LENGTH OF FIBONACCI SERIES IS :"<< length <<endl;
    return 0;
}