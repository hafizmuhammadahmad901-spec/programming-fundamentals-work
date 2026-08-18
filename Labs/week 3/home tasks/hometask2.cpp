#include <iostream>
using namespace std;
int main() {
	int minutes;
	int frames;
	int total;
	cout<<"ENTER NUMBER OF MINUTES :";
	cin>>minutes;
	cout<<"ENTER NUMBER OF FRAMES PER SECOND:";
	cin>>frames;
	int seconds = minutes * 60;
	total = seconds * frames;
	cout<<"total number of frames"<<total<<"frames";
}
	
	