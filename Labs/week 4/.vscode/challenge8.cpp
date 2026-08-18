#include <iostream>
using namespace std;

int main() {
    char ch;
    cout << "ENTER THE CHARACTER: ";
    cin >> ch;

    
    if (ch >= '0') {
        if (ch <= '9') {
            cout << "The character is a digit" << endl;
            
        }
    }

   
    if (ch == 'a') { cout << "The character is a vowel" << endl; return 0; }
    if (ch == 'e') { cout << "The character is a vowel" << endl; return 0; }
    if (ch == 'i') { cout << "The character is a vowel" << endl; return 0; }
    if (ch == 'o') { cout << "The character is a vowel" << endl; return 0; }
    if (ch == 'u') { cout << "The character is a vowel" << endl; return 0; }
    if (ch == 'A') { cout << "The character is a vowel" << endl; return 0; }
    if (ch == 'E') { cout << "The character is a vowel" << endl; return 0; }
    if (ch == 'I') { cout << "The character is a vowel" << endl; return 0; }
    if (ch == 'O') { cout << "The character is a vowel" << endl; return 0; }
    if (ch == 'U') { cout << "The character is a vowel" << endl; return 0; }

    
    if (ch >= 'a') {
        if (ch <= 'z') {
            cout << "The character is a consonant" << endl;
            
        }
    }
    
    if (ch >= 'A') {
        if (ch <= 'Z') {
            cout << "The character is a consonant" << endl;
           
        }
    }

    
    cout << "The character is a special character" << endl;

  
}