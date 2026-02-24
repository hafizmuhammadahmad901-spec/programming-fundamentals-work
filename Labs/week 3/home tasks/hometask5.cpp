#include<iostream>
using namespace std;
int main() {
	string name;
	int target;
	int loss;
	cout<<"ENTER PATIENTS NAME:";
	cin>>name;
	cout<<"ENTER TARGET WEIGHT LOSS:";
	cin>>target;
	loss = target * 15;
	cout<<"you will lose--------kgs in days:"<<loss<<"days";
}