#include <iostream>

using namespace std;

int main() {
    string moviename;
    double adultprice, childprice;
    int adultsold, childsold;
    double donationPercent;

    cout << "ENTER MOVIE NAME: ";
    cin>>moviename;

    cout << "ENTER ADULT TICKET PRICE: ";
    cin >> adultprice;

    cout << "ENTER CHILD TICKET PRICE: ";
    cin >> childprice;

    cout << "ENTER ADULT TICKETS SOLD: ";
    cin >> adultsold;

    cout << "ENTER CHILD TICKETS SOLD: ";
    cin >> childsold;

    cout << "ENTER DONATION PERCENTAGE FOR CHARITY (%): ";
    cin >> donationPercent;

    double totalamount = (adultsold * adultprice) + (childsold * childprice);
    double donationamount = totalamount * (donationPercent / 100);
    double remainingamount = totalamount - donationamount;

    cout << "\n---------------- MOVIE SALES SUMMARY ----------------\n";
    cout << "Movie Name: " << moviename << endl;
    
    cout << "Total Amount Earned: $" << totalamount << endl;
    cout << "Donation to Charity: $" << donationamount << endl;
    cout << "Remaining Amount: $" << remainingamount << endl;

    return 0;
}