#include <iostream>
#include <string>

using namespace std;

int main() {
    
    const int MAX_BOOKS = 5;
    string bookNames[MAX_BOOKS];
    bool isAvailable[MAX_BOOKS]; 
    
    int bookCount = 0;
    int choice = 0;

    
    for(int i = 0; i < MAX_BOOKS; i++) {
        isAvailable[i] = true;
    }

    
    while (choice != 5) {
        cout << "\n========== Library Menu ==========" << endl;
        cout << "1. Add Books" << endl;
        cout << "2. View Books" << endl;
        cout << "3. Borrow Books" << endl;
        cout << "4. Return Books" << endl; 
        cout << "5. Exit" << endl;
        cout << "==================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        
        if (choice == 1) {
            if (bookCount < MAX_BOOKS) {
                cout << "Enter Book Name: ";
                cin.ignore(); 
                getline(cin, bookNames[bookCount]);
                isAvailable[bookCount] = true;
                bookCount++;
                cout << "Book added successfully!" << endl;
            } else {
                cout << "Library is full! Cannot add more books." << endl;
            }
        }
       
        else if (choice == 2) {
            cout << "\n--- Library Inventory ---" << endl;
            if (bookCount == 0) {
                cout << "The library is currently empty." << endl;
            } else {
                for (int i = 0; i < bookCount; i++) {
                    cout << i + 1 << ". " << bookNames[i];
                    if (isAvailable[i]) {
                        cout << " [Available]" << endl;
                    } else {
                        cout << " [Borrowed]" << endl;
                    }
                }
            }
        }
        
        else if (choice == 3) {
            int bookNum;
            cout << "Enter the book number to borrow: ";
            cin >> bookNum;

            
            if (bookNum > 0 && bookNum <= bookCount) {
                if (isAvailable[bookNum - 1]) {
                    isAvailable[bookNum - 1] = false;
                    cout << "You have successfully borrowed: " << bookNames[bookNum - 1] << endl;
                } else {
                    cout << "Sorry, this book is already borrowed." << endl;
                }
            } else {
                cout << "Invalid book number!" << endl;
            }
        }

        else if (choice == 4) {
            int bookNum;
            cout << "Enter the book number to return: ";
            cin >> bookNum;

            if (bookNum > 0 && bookNum <= bookCount) {
                if (!isAvailable[bookNum - 1]) {
                    isAvailable[bookNum - 1] = true;
                    cout << "Thank you for returning: " << bookNames[bookNum - 1] << endl;
                } else {
                    cout << "This book was never borrowed." << endl;
                }
            } else {
                cout << "Invalid book number!" << endl;
            }
        }
        
        else if (choice == 5) {
            cout << "Exiting Library System. Goodbye!" << endl;
        }
        else {
            cout << "Invalid selection! Please try again." << endl;
        }
    }

    return 0;
}