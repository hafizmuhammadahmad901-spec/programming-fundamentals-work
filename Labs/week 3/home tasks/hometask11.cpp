#include<iostream>
using namespace std;
int main() {
int age;
int moves;
cout<<"ENTER THE AGE OF A PERSON:";
cin>>age;
cout<<"ENTER NUMBER OF MOVES THEY HAVE DONE";
cin>>moves;
int houses;
houses = moves + 1;
double average;
average = age/houses;
cout<<"average houses they move"<<average;
}
