#include <iostream>
using namespace std;

void  modifyWithPointers(int *ptr){
    *ptr = 50;

}
void modifyWithReference(int &ref){
    ref = 60;
}
int main() {
    int a = 10, b = 20;
    modifyWithPointers(&a);
    modifyWithReference(b);
    cout<<"value of a after modification with pointer"<<a<<endl;
    cout<<"value of b after modification with reference"<<b<<endl;
    
    
    return 0;
}