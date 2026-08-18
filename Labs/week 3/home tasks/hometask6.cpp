#include<iostream>
using namespace std;
int main() {
	int weight;
	int cost;
	int area;
	cout<<"ENTER THE WEIGHT OF FERTILIZER IN BAGS:";
	cin>>weight;
	cout<<"ENTER THE COST  OF BAG:";
	cin>>cost;
	cout<<"ENTER AREA PER SQUARE FOOT:";
	cin>>area;
	
	int priceperpound = cost/weight;
	int costpersquarefoot = cost/area;
	cout<<"PRICE PER POUND IS:"<<priceperpound<<"$"<<endl;
	cout<<"PRICE PER SQUARE FOOT IS:"<<costpersquarefoot<<"$";
}