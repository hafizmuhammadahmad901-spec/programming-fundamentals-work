#include<iostream>
using namespace std;
int main() {
	int vi;
	int a;
	int t;
	int vf;
	cout<<"ENTER INITIAL VELOCITY: ";
	cin>>vi;
	cout<<"ENTER ACCELRATION :";
	cin>>a;
	cout<<"ENTER TIME :";
	cin>>t;
		vf = vi + a*t;
		cout<<"final velocity wiil be:"<<vf<<"ms^-1";
}
	
	