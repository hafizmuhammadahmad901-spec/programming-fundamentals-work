#include <iostream>
#include <string>

using namespace std;

int main() {
    
    string productNames[4] = {"Apple", "Banana", "Orange", "Mango"};
    double prices[4] = {0.5, 0.3, 0.8, 1.2};
    int quantity[4] = {50, 100, 30, 20};

    cout << "--- Shop Inventory Report ---" << endl;

    
    for (int i = 0; i < 4; i++) {
       
        double totalValue = prices[i] * quantity[i];

        
        cout << productNames[i] << ": $" << prices[i] 
             << ", " << quantity[i] << " in stock, "
             << "Total value: $" << totalValue << endl;
    }

    return 0;
}