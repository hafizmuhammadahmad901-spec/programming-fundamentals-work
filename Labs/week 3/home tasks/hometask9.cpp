#include <iostream>
using namespace std;
int main() {
int num,a,b,c,d,sum,product;
cout<<"ENTER A FOUR DIGIT NUMBER:";
cin>>num;

a = num%10,num/=10;
b = num%10,num/=10;
c  = num%10,num/=10;
d  = num%10,num/=10;

sum = a + b + c + d;
product = a * b * c * d;
cout<<"sum is ="<< sum<<"product is =:"<<product;
}