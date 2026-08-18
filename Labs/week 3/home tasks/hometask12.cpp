#include <iostream>
using namespace std;

int main() {

    int n, w, h;
     cout<<"ENTER SQUARE METER YOU WANT TO PAINT:";
     cin >> n;
	 cout<<"ENTER WIDTH OF WALL:";
    cin >> w;
	cout<<"ENTER HEIGHT OF WALL:";
    cin >> h;

   
    int wallArea = w * h;

    
    int walls = n / wallArea;

    
    cout << walls << endl;

    return 0;
}