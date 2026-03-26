#include<iostream>
using namespace std;

int main() {
    int correctPIN = 1234;
    int pin;
    int choice;
    int balance = 1000;
    int amount;
    bool login = false;

    // PIN attempts
    for(int i = 0; i < 3; i++){
        cout << "ENTER ATM PIN: ";
        cin >> pin;

        if(pin == correctPIN){
            login = true;
            cout << "LOGIN SUCCESSFUL\n";
            break;
        }
        else{
            cout << "INCORRECT PIN\n";
        }
    }

    if(login == true){
        while(true){
            cout << "\n====== ATM MENU ======\n";
            cout << "1. CHECK BALANCE\n";
            cout << "2. DEPOSIT MONEY\n";
            cout << "3. WITHDRAW MONEY\n";
            cout << "4. EXIT\n";
            cout << "ENTER YOUR CHOICE: ";
            cin >> choice;

            if(choice == 1){
                cout << "CURRENT BALANCE: " << balance << endl;
            }
            else if(choice == 2){
                cout << "ENTER AMOUNT TO DEPOSIT: ";
                cin >> amount;
                balance += amount;
                cout << "UPDATED BALANCE: " << balance << endl;
            }
            else if(choice == 3){
                cout << "ENTER AMOUNT TO WITHDRAW: ";
                cin >> amount;

                if(amount <= balance && amount > 0){
                    balance -= amount;
                    cout << "REMAINING BALANCE: " << balance << endl;
                }
                else{
                    cout << "INSUFFICIENT BALANCE\n";
                }
            }
            else if(choice == 4){
                cout << "THANK YOU FOR USING ATM\n";
                break;
            }
            else{
                cout << "INVALID CHOICE\n";
            }
        }
    }
    else{
        cout << "TOO MANY INCORRECT ATTEMPTS. ACCESS DENIED\n";
    }

    return 0;
}