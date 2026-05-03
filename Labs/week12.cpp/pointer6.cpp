#include <iostream>
using namespace std;
 int swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
 }


int main() {
    int y = 20;
    int x = 10;
    swap(x, y);




    return 0;
}
 