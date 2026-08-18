#include <iostream>
#include <string>

using namespace std;

int main() {
   
    string flightNumber[3] = {"PK301", "EK502", "QR743"};
    string destination[3] = {"Karachi", "Dubai", "Doha"};
    int seatsAvailable[3] = {15, 0, 42};

    cout << "=== Airline Flight Tracking System ===" << endl;
    cout << "Flight No. | Destination | Seats Available | Status" << endl;
    cout << "---------------------------------------------------" << endl;

   
    for (int i = 0; i < 3; i++) {
        cout << flightNumber[i] << "      | " 
             << destination[i] << "       | " 
             << seatsAvailable[i] << "              | ";

        
        if (seatsAvailable[i] > 0) {
            cout << "Available" << endl;
        } else {
            cout << "Full" << endl;
        }
    }

    return 0;
}