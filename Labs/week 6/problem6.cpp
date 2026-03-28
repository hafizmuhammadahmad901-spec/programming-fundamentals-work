#include <iostream>
#include <string>

using namespace std;

int main() {
    
    const string CORRECT_USER = "admin";
    const string CORRECT_PASS = "1234";
    const int MAX_CAPACITY = 3;

    
    string loginHistory[3]; 
    string studentNames[MAX_CAPACITY];
    int studentAges[MAX_CAPACITY];
    string courses[MAX_CAPACITY];

    
    int studentCount = 0;
    int courseCount = 0;
    bool loggedIn = false;

    
    cout << "=== University Management System Login ===" << endl;
    
    for (int i = 0; i < 3; i++) {
        string inputUser, inputPass;
        cout << "\nAttempt " << (i + 1) << " of 3" << endl;
        cout << "Enter Username: ";
        cin >> inputUser;
        cout << "Enter Password: ";
        cin >> inputPass;

        
        loginHistory[i] = inputUser;

        
        if (inputUser == CORRECT_USER && inputPass == CORRECT_PASS) {
            cout << "\nLogin Successful!" << endl;
            loggedIn = true;
            break; 
        } else {
            cout << "Invalid Credentials.";
            if (i < 2) cout << " Try again.";
            else cout << "\nMaximum attempts reached. Access Denied.";
        }
    }

    
    if (loggedIn) {
        int choice = 0;

        
        while (choice != 5) {
            
            cout << "\n---------- Main Menu ----------" << endl;
            cout << "1 -> Add Student" << endl;
            cout << "2 -> View Students" << endl;
            cout << "3 -> Add Course" << endl;
            cout << "4 -> View Courses" << endl;
            cout << "5 -> Exit" << endl;
            cout << "-------------------------------" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            
            if (choice == 1) {
                if (studentCount < MAX_CAPACITY) {
                    cout << "Enter Student Name: "<<endl;
                    cin.ignore();
                    getline(cin, courses[courseCount]);

                   
                    cout << "Enter Student Age: ";
                    cin >> studentAges[studentCount];
                    studentCount++;
                    cout << "Student added successfully!" << endl;
                } else {
                    cout << "Error: Student limit (3) reached!" << endl;
                }
            }
            
            else if (choice == 2) {
                cout << "\n--- Student List ---" << endl;
                if (studentCount == 0) {
                    cout << "No students registered yet." << endl;
                } else {
                    for (int i = 0; i < studentCount; i++) {
                        cout << i + 1 << ". Name: " << studentNames[i] 
                             << " | Age: " << studentAges[i] << endl;
                    }
                }
            }
           
            else if (choice == 3) {
                if (courseCount < MAX_CAPACITY) {
                    cout << "Enter Course Name: ";
                    cin.ignore();
                    getline(cin, courses[courseCount]);
                    courseCount++;
                    cout << "Course added successfully!" << endl;
                } else {
                    cout << "Error: Course limit (3) reached!" << endl;
                }
            }
            
            else if (choice == 4) {
                cout << "\n--- Course List ---" << endl;
                if (courseCount == 0) {
                    cout << "No courses available." << endl;
                } else {
                    for (int i = 0; i < courseCount; i++) {
                        cout << i + 1 << ". " << courses[i] << endl;
                    }
                }
            }
            
            else if (choice == 5) {
                cout << "Exiting system. Goodbye!" << endl;
            }
            else {
                
                if (!(choice >= 1 && choice <= 5)) {
                    cout << "Invalid choice! Please select 1-5." << endl;
                }
            }
        }
    }

    return 0;
}