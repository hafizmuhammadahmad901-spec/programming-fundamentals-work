#include<iostream>
using namespace std;
main () {
	float megabyte;
	float bit;
	cout<<"enter value in megabytes :";
	cin>>megabyte;
	bit = megabyte * 8388608 ;
	cout<<"value in bits is"<<bit;
}