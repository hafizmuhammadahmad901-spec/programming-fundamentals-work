#include <iostream>
using namespace std;
main() {
	float charge;
	float time;
	float current;
	cout<<"ENTER VALUE OF CHARGE :";
	cin>>charge;
	cout<<"ENTER VALUE OF TIME :"<<endl;
	cin>>time;
	current = charge/time;
	cout<<"current ki value ha :" <<current<<"amperes";
}