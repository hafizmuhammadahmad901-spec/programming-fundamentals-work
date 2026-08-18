#
    #include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    int count = 0;
    char searchLetter;

    
    cout << "Enter the number of customers: ";
    cin >> n;

    
    string customers[n];

    
    cout << "Enter " << n << " customer names:" << endl;
    cin.ignore(); 
    for (int i = 0; i < n; i++) {
        cout << "Customer " << (i + 1) << ": ";
        getline(cin, customers[i]);
    }

    
    cout << "\nEnter a letter to count: ";
    cin >> searchLetter;

    
    for (int i = 0; i < n; i++) {
        
        if (customers[i][0] == toupper(searchLetter) || customers[i][0] == tolower(searchLetter)) {
            count++;
        }
    }

    
    cout << "\n--------------------------------------" << endl;
    cout << "Total names starting with '" << searchLetter << "': " << count << endl;
    cout << "--------------------------------------" << endl;

    return 0;
}

