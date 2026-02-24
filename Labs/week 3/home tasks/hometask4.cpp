#include<iostream>
using namespace std;
int main() {
	int i;
	int p;
	int count;
	cout<<"ENTER IMPOSTER COUNT:";
	cin>>i;
	cout<<"ENTER PLAYER COUNT:";
	cin>>p;
	count = 100 * i/p;
	cout<<"IMPOSTER PERCENTAGE IS:"<<count<<"%";
}
	