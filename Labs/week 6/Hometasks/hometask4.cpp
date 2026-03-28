#include <iostream>


using namespace std;

int main() {
   
    string students[5];

    
    cout << "Enter the names of 5 students:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Student " << (i + 1) << ": ";
        
       
        if (i == 0) cin.ignore(); 
        getline(cin, students[i]);
    }

    
    cout << "\n--- List of Students ---" << endl;
    for (int i = 0; i < 5; i++) {
        cout << (i + 1) << ". " << students[i] << endl;
    }

    return 0;
}