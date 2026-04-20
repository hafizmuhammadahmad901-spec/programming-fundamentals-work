#include <iostream>
#include <iomanip> 

using namespace std;


void calculateFutureTime(int h, int m) {
    
    m = m + 15;

    
    if (m >= 60) {
        m = m - 60;
        h = h + 1;
    }

    
    if (h >= 24) {
        h = 0;
    }

    
    cout << "Time Travel Destination: ";
    
    
    if (h < 10) cout << "0" << h;
    else cout << h;

    cout << ":";

    
    if (m < 10) cout << "0" << m;
    else cout << m;
    
    cout << endl;
}

int main() {
    int hours, minutes;

    cout << "--- Magical Time Travel Device ---" << endl;
    cout << "Enter current hour (0-23): ";
    cin >> hours;
    cout << "Enter current minutes (0-59): ";
    cin >> minutes;

    
    if (hours < 0 || hours > 23 || minutes < 0 || minutes > 59) {
        cout << "[Error] Invalid time entered!" << endl;
    } else {
        calculateFutureTime(hours, minutes);
    }

    return 0;
}