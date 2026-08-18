#include <iostream>
using namespace std;


bool isSymmetrical(int num) {
    
    int original = num;
    int reverse = 0;
    int remainder;

    
    while (num != 0) {
        remainder = num % 10;          
        reverse = reverse * 10 + remainder; 
        num = num / 10;               
    }


    if (original == reverse) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int userInput;

    cout << "Enter a 3-digit number: ";
    cin >> userInput;

    
   
        if (isSymmetrical(userInput)) {
            cout << userInput << " is symmetrical! (True)" << endl;
        } else {
            cout << userInput << " is NOT symmetrical. (False)" << endl;
        }
    

    return 0;
}