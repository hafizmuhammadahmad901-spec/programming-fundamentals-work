#include <iostream>
using namespace std;
int main() {
    int y = 20;
    int &ref = y;
    cout<<"original value of y"<<y<<endl;
    ref = 30;
    cout<<"value of y after changing through reference"<<y<<endl;



    return 0;
}