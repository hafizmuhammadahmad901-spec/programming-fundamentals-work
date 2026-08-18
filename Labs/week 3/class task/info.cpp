#include<iostream>
using namespace std;
main() {
string name;
float matric;
float fsc;
float ecat;
cout<<"enter your matric marks :";
cin>>matric;
cout<<"enter your fsc marks :";
cin>>fsc;
cout<<"enter your ecat marks :";
cin>>ecat;

float a, b, c, agg;
a = (matric/1100*100)*0.1;
b = (fsc/555 * 100)*0.4;
c = (ecat/400*100)*0.5;
agg = a + b + c;
cout<<"your aggregate is :"<<agg;
}

