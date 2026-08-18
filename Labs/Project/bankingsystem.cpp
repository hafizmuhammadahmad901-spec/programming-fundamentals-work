#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

 
// ===== GLOBAL 1D ARRAYS =====
int accountID[100];
string customerName[100];
string pin[100];
double balance[100];
double loanBalance[100];
double taxPaid[100];
bool isActive[100];int accountCount = 0;
 
int transactionID[500];
int txnAccountID[500];
string txnType[500];
double txnAmount[500];
string txnDate[500];
int transactionCount = 0;
 
// ===== MAIN FUNCTION =====
int main() {
    int mainChoice = 0;
    bool systemRunning = true;
 
    while (systemRunning) {
        // ===== MAIN BANKING SYSTEM HEADER =====
        cout << "\n";
        cout << "#################################################################################" << endl;
        cout << "#                                                                               #" << endl;
        cout << "#                  *** WELCOME TO BANKING SYSTEM ***                            #" << endl;
        cout << "#                                                                               #" << endl;
        cout << "#################################################################################" << endl;
        cout << "\n";
        cout << "                          1. ADMIN LOGIN" << endl;
        cout << "                          2. CUSTOMER LOGIN" << endl;
        cout << "                          3. EXIT SYSTEM" << endl;
        cout << "\n";
        cout << "==========================================" << endl;
        cout << "ENTER YOUR CHOICE: ";
        cin >> mainChoice;
 
        // ===== ADMIN LOGIN =====
        if (mainChoice == 1) {
            cout << "\n";
            cout << "#################################################################################" << endl;
            cout << "#                                                                               #" << endl;
            cout << "#                        *** ADMIN LOGIN PAGE ***                               #" << endl;
            cout << "#                                                                               #" << endl;
            cout << "#################################################################################" << endl;
 
            
            
            string adminPass;
            string adminUsername;
            bool adminLoginSuccess = false;
 
            for (int i = 0; i < 3; i++) {
                cout << "\nENTER USERNAME: ";
                cin >> adminUsername;
                cout << "ENTER PASSWORD: ";
                cin >> adminPass;
 
                //  compare as strings now
                if (adminPass == "1234" && adminUsername == "admin") {
                    cout << "\n<<<<<SUCCESS: YOU ARE LOGGED IN AS ADMIN.>>>>>" << endl;
                    adminLoginSuccess = true;
 
                    // ===== ADMIN MENU LOOP =====
                    bool adminLoggedIn = true;
                    while (adminLoggedIn) {
                        cout << "\n";
                        cout << "==========================================" << endl;
                        cout << "        *** ADMIN CONTROL PANEL ***        " << endl;
                        cout << "==========================================" << endl;
                        cout << "1.  MANAGE ACCOUNTS (View List)" << endl;
                        cout << "2.  ADD AN ACCOUNT" << endl;
                        cout << "3.  UPDATE ACCOUNT DETAILS" << endl;
                        cout << "4.  DELETE AN ACCOUNT" << endl;
                        cout << "5.  VIEW ALL TRANSACTIONS" << endl;
                        cout << "6.  ADD TRANSACTION" << endl;
                        cout << "7.  UPDATE TRANSACTION" << endl;
                        cout << "8.  SEARCH ACCOUNT BY ID" << endl;
                        cout << "9.  SEARCH TRANSACTION BY DATE" << endl;
                        cout << "10. GENERATE MONTHLY REPORT" << endl;
                        cout << "11. TRANSFER FUNDS BETWEEN ACCOUNTS" << endl;
                        cout << "12. SAVE DATA TO FILE" << endl;
                        cout << "13. LOGOUT / EXIT" << endl;
                        cout << "==========================================" << endl;
                        cout << "ENTER YOUR CHOICE: ";
 
                        int adminChoice;
                        cin >> adminChoice;
 
                        // ===== ADMIN OPTION 1: VIEW ALL ACCOUNTS =====
                        if (adminChoice == 1) {
                            cout << "\n========== VIEW ALL ACCOUNTS ==========" << endl;
                            if (accountCount == 0) {
                                cout << "NO ACCOUNTS AVAILABLE." << endl;
                            } else {
                                cout << "\nID\tName\t\tBalance\t\tLoan\t\tStatus" << endl;
                                cout << "========================================================================" << endl;
                                for (int i = 0; i < accountCount; i++) {
                                    cout << accountID[i] << "\t" << customerName[i] << "\t$" << balance[i]
                                         << "\t\t$" << loanBalance[i] << "\t\t"
                                         << (isActive[i] ? "Active" : "Inactive") << endl;
                                }
                            }
                        }
 
                        // ===== ADMIN OPTION 2: ADD ACCOUNT =====
                        else if (adminChoice == 2) {
                            cout << "\n========== ADD NEW ACCOUNT ==========" << endl;
                            if (accountCount >= 100) {
                                cout << "ERROR: MAXIMUM ACCOUNTS REACHED!" << endl;
                            } else {
                                
                                cin.ignore();
                                cout << "ENTER CUSTOMER NAME: ";
                                getline(cin, customerName[accountCount]);
 
                                
                                string newPin;
                                bool pinValid = false;
                                while (!pinValid) {
                                    cout << "ENTER SECURITY PIN (exactly 4 digits): ";
                                    cin >> newPin;
                                    if (newPin.length() == 4) {
                                        pinValid = true;
                                        for (int c = 0; c < 4; c++) {
                                            if (newPin[c] < '0' || newPin[c] > '9') {
                                                pinValid = false;
                                                break;
                                            }
                                        }
                                    }
                                    if (!pinValid) cout << "ERROR: PIN MUST BE EXACTLY 4 DIGITS!" << endl;
                                }
                                pin[accountCount] = newPin;
 
                                accountID[accountCount] = 1001 + accountCount;
                                balance[accountCount] = 0.0;
                                loanBalance[accountCount] = 0.0;
                                taxPaid[accountCount] = 0.0;
                                isActive[accountCount] = true;
 
                                cout << "ACCOUNT CREATED SUCCESSFULLY!" << endl;
                                cout << "ACCOUNT ID: " << accountID[accountCount] << endl;
                                accountCount++;
                            }
                        }
 
                        // ===== ADMIN OPTION 3: UPDATE ACCOUNT DETAILS =====
                        else if (adminChoice == 3) {
                            cout << "\n========== UPDATE ACCOUNT DETAILS ==========" << endl;
                            int searchID;
                            cout << "ENTER ACCOUNT ID: ";
                            cin >> searchID;
 
                            int index = -1;
                            for (int i = 0; i < accountCount; i++) {
                                if (accountID[i] == searchID) {
                                    index = i;
                                    break;
                                }
                            }
 
                            if (index == -1) {
                                cout << "ERROR: ACCOUNT NOT FOUND!" << endl;
                            } else {
                                cout << "CURRENT NAME: " << customerName[index] << endl;
                                cout << "\n1. Update Name\n2. Change PIN\nCHOICE: ";
                                int updateChoice;
                                cin >> updateChoice;
 
                                if (updateChoice == 1) {
                                    
                                    cin.ignore();
                                    cout << "ENTER NEW NAME: ";
                                    getline(cin, customerName[index]);
                                    cout << "NAME UPDATED SUCCESSFULLY!" << endl;
                                } else if (updateChoice == 2) {
                                    
                                    string newPin;
                                    bool pinValid = false;
                                    while (!pinValid) {
                                        cout << "ENTER NEW PIN (exactly 4 digits): ";
                                        cin >> newPin;
                                        if (newPin.length() == 4) {
                                            pinValid = true;
                                            for (int c = 0; c < 4; c++) {
                                                if (newPin[c] < '0' || newPin[c] > '9') {
                                                    pinValid = false;
                                                    break;
                                                }
                                            }
                                        }
                                        if (!pinValid) cout << "ERROR: PIN MUST BE EXACTLY 4 DIGITS!" << endl;
                                    }
                                    pin[index] = newPin;
                                    cout << "PIN UPDATED SUCCESSFULLY!" << endl;
                                }
                            }
                        }
 
                        // ===== ADMIN OPTION 4: DELETE ACCOUNT =====
                        else if (adminChoice == 4) {
                            cout << "\n========== DELETE ACCOUNT ==========" << endl;
                            int searchID;
                            cout << "ENTER ACCOUNT ID TO DELETE: ";
                            cin >> searchID;
 
                            int index = -1;
                            for (int i = 0; i < accountCount; i++) {
                                if (accountID[i] == searchID) {
                                    index = i;
                                    break;
                                }
                            }
 
                            if (index == -1) {
                                cout << "ERROR: ACCOUNT NOT FOUND!" << endl;
                            } else {
                                
                                int newTxnCount = 0;
                                for (int i = 0; i < transactionCount; i++) {
                                    if (txnAccountID[i] != searchID) {
                                        transactionID[newTxnCount]  = transactionID[i];
                                        txnAccountID[newTxnCount]   = txnAccountID[i];
                                        txnType[newTxnCount]        = txnType[i];
                                        txnAmount[newTxnCount]      = txnAmount[i];
                                        txnDate[newTxnCount]        = txnDate[i];
                                        newTxnCount++;
                                    }
                                }
                                transactionCount = newTxnCount;
 
                                // Shift account arrays
                                for (int i = index; i < accountCount - 1; i++) {
                                    accountID[i]      = accountID[i + 1];
                                    customerName[i]   = customerName[i + 1];
                                    pin[i]            = pin[i + 1];
                                    balance[i]        = balance[i + 1];
                                    loanBalance[i]    = loanBalance[i + 1];
                                    taxPaid[i]        = taxPaid[i + 1];
                                    isActive[i]       = isActive[i + 1];
                                }
                                accountCount--;
                                cout << "ACCOUNT AND ITS TRANSACTIONS DELETED SUCCESSFULLY!" << endl;
                            }
                        }
 
                        // ===== ADMIN OPTION 5: VIEW ALL TRANSACTIONS =====
                        else if (adminChoice == 5) {
                            cout << "\n========== VIEW ALL TRANSACTIONS ==========" << endl;
                            if (transactionCount == 0) {
                                cout << "NO TRANSACTIONS AVAILABLE." << endl;
                            } else {
                                cout << "\nTxn ID\tAcc ID\tType\t\tAmount\t\tDate" << endl;
                                cout << "========================================================================" << endl;
                                for (int i = 0; i < transactionCount; i++) {
                                    cout << transactionID[i] << "\t" << txnAccountID[i] << "\t"
                                         << txnType[i] << "\t$" << txnAmount[i] << "\t\t" << txnDate[i] << endl;
                                }
                            }
                        }
 
                        // ===== ADMIN OPTION 6: ADD TRANSACTION =====
                        else if (adminChoice == 6) {
                            cout << "\n========== ADD MANUAL TRANSACTION ==========" << endl;
                            int searchID;
                            cout << "ENTER ACCOUNT ID: ";
                            cin >> searchID;
 
                            int index = -1;
                            for (int i = 0; i < accountCount; i++) {
                                if (accountID[i] == searchID) {
                                    index = i;
                                    break;
                                }
                            }
 
                            if (index == -1) {
                                cout << "ERROR: ACCOUNT NOT FOUND!" << endl;
                            } else {
                                if (transactionCount < 500) {
                                    string type, date;
                                    double amount;
                                    cout << "ENTER TRANSACTION TYPE (Deposit/Withdrawal/Adjustment): ";
                                    cin >> type;
                                    cout << "ENTER AMOUNT: $";
                                    cin >> amount;
                                    cout << "ENTER DATE (YYYY-MM-DD): ";
                                    cin >> date;
 
                                    
                                    if (type == "Deposit") {
                                        balance[index] += amount;
                                    } else if (type == "Withdrawal") {
                                        if (balance[index] < amount) {
                                            cout << "ERROR: INSUFFICIENT BALANCE! TRANSACTION NOT ADDED." << endl;
                                        } else {
                                            balance[index] -= amount;
                                        }
                                    }
                                   
 
                                    transactionID[transactionCount] = transactionCount + 1;
                                    txnAccountID[transactionCount]  = searchID;
                                    txnType[transactionCount]       = type;
                                    txnAmount[transactionCount]     = amount;
                                    txnDate[transactionCount]       = date;
                                    transactionCount++;
 
                                    cout << "TRANSACTION ADDED SUCCESSFULLY!" << endl;
                                }
                            }
                        }
 
                        // ===== ADMIN OPTION 7: UPDATE TRANSACTION =====
                        else if (adminChoice == 7) {
                            cout << "\n========== UPDATE TRANSACTION ==========" << endl;
                            int txnID;
                            cout << "ENTER TRANSACTION ID: ";
                            cin >> txnID;
 
                            int index = -1;
                            for (int i = 0; i < transactionCount; i++) {
                                if (transactionID[i] == txnID) {
                                    index = i;
                                    break;
                                }
                            }
 
                            if (index == -1) {
                                cout << "ERROR: TRANSACTION NOT FOUND!" << endl;
                            } else {
                                cout << "CURRENT AMOUNT: $" << txnAmount[index] << endl;
                                cout << "ENTER NEW AMOUNT: $";
                                cin >> txnAmount[index];
                                cout << "TRANSACTION UPDATED SUCCESSFULLY!" << endl;
                            }
                        }
 
                        // ===== ADMIN OPTION 8: SEARCH ACCOUNT BY ID =====
                        else if (adminChoice == 8) {
                            cout << "\n========== SEARCH ACCOUNT ==========" << endl;
                            int searchID;
                            cout << "ENTER ACCOUNT ID: ";
                            cin >> searchID;
 
                            bool found = false;
                            for (int i = 0; i < accountCount; i++) {
                                if (accountID[i] == searchID) {
                                    cout << "\nACCOUNT FOUND!" << endl;
                                    cout << "ID: " << accountID[i] << endl;
                                    cout << "Name: " << customerName[i] << endl;
                                    cout << "Balance: $" << balance[i] << endl;
                                    cout << "Loan Balance: $" << loanBalance[i] << endl;
                                    cout << "Tax Paid: $" << taxPaid[i] << endl;
                                    found = true;
                                    break;
                                }
                            }
                            if (!found) cout << "ERROR: ACCOUNT NOT FOUND!" << endl;
                        }
 
                        // ===== ADMIN OPTION 9: SEARCH TRANSACTION BY DATE =====
                        else if (adminChoice == 9) {
                            cout << "\n========== SEARCH TRANSACTIONS BY DATE ==========" << endl;
                            string searchDate;
                            cout << "ENTER DATE (YYYY-MM-DD): ";
                            cin >> searchDate;
 
                            cout << "\nTxn ID\tAcc ID\tType\t\tAmount" << endl;
                            cout << "=====================================================" << endl;
                            bool found = false;
                            for (int i = 0; i < transactionCount; i++) {
                                if (txnDate[i] == searchDate) {
                                    cout << transactionID[i] << "\t" << txnAccountID[i]
                                         << "\t" << txnType[i] << "\t$" << txnAmount[i] << endl;
                                    found = true;
                                }
                            }
                            if (!found) cout << "NO TRANSACTIONS FOUND FOR THIS DATE!" << endl;
                        }
 
                        // ===== ADMIN OPTION 10: GENERATE MONTHLY REPORT =====
                        else if (adminChoice == 10) {
                            cout << "\n========== MONTHLY REPORT ==========" << endl;
                            string month;
                            cout << "ENTER MONTH (YYYY-MM): ";
                            cin >> month;
 
                            double totalDeposits = 0, totalWithdrawals = 0;
                            int depositCount = 0, withdrawalCount = 0;
 
                            for (int i = 0; i < transactionCount; i++) {
                                if (txnDate[i].substr(0, 7) == month) {
                                    if (txnType[i] == "Deposit") {
                                        totalDeposits += txnAmount[i];
                                        depositCount++;
                                    } else if (txnType[i] == "Withdrawal") {
                                        totalWithdrawals += txnAmount[i];
                                        withdrawalCount++;
                                    }
                                }
                            }
 
                            cout << "\nMONTHLY SUMMARY FOR " << month << endl;
                            cout << "===================================" << endl;
                            cout << "Total Deposits: " << depositCount << " Transactions = $" << totalDeposits << endl;
                            cout << "Total Withdrawals: " << withdrawalCount << " Transactions = $" << totalWithdrawals << endl;
                            cout << "Net: $" << (totalDeposits - totalWithdrawals) << endl;
                        }
 
                        // ===== ADMIN OPTION 11: TRANSFER FUNDS =====
                        else if (adminChoice == 11) {
                            cout << "\n========== TRANSFER FUNDS ==========" << endl;
                            int fromID, toID;
                            double amount;
 
                            cout << "ENTER FROM ACCOUNT ID: ";
                            cin >> fromID;
                            cout << "ENTER TO ACCOUNT ID: ";
                            cin >> toID;
                            cout << "ENTER AMOUNT: $";
                            cin >> amount;
 
                            
                            if (fromID == toID) {
                                cout << "ERROR: CANNOT TRANSFER TO THE SAME ACCOUNT!" << endl;
                            } else {
                                int fromIndex = -1, toIndex = -1;
                                for (int i = 0; i < accountCount; i++) {
                                    if (accountID[i] == fromID) fromIndex = i;
                                    if (accountID[i] == toID)   toIndex   = i;
                                }
 
                                if (fromIndex == -1 || toIndex == -1) {
                                    cout << "ERROR: ACCOUNT NOT FOUND!" << endl;
                                } else if (!isActive[toIndex]) {
                                    
                                    cout << "ERROR: RECIPIENT ACCOUNT IS INACTIVE!" << endl;
                                } else if (balance[fromIndex] < amount) {
                                    cout << "ERROR: INSUFFICIENT BALANCE!" << endl;
                                } else {
                                    balance[fromIndex] -= amount;
                                    balance[toIndex]   += amount;
 
                                    string transferDate;
                                    cout << "ENTER DATE (YYYY-MM-DD): ";
                                    cin >> transferDate;
 
                                    if (transactionCount < 500) {
                                        transactionID[transactionCount]  = transactionCount + 1;
                                        txnAccountID[transactionCount]   = fromID;
                                        txnType[transactionCount]        = "Transfer Out";
                                        txnAmount[transactionCount]      = amount;
                                        txnDate[transactionCount]        = transferDate;
                                        transactionCount++;
                                    }
                                    if (transactionCount < 500) {
                                        transactionID[transactionCount]  = transactionCount + 1;
                                        txnAccountID[transactionCount]   = toID;
                                        txnType[transactionCount]        = "Transfer In";
                                        txnAmount[transactionCount]      = amount;
                                        txnDate[transactionCount]        = transferDate;
                                        transactionCount++;
                                    }
                                    cout << "TRANSFER SUCCESSFUL!" << endl;
                                }
                            }
                        }
 
                        // ===== ADMIN OPTION 12: SAVE DATA =====
                        else if (adminChoice == 12) {
                            cout << "\n========== SAVE DATA TO FILE ==========" << endl;
                            cout << "DATA SAVED SUCCESSFULLY!" << endl;
                            cout << "Total Accounts: " << accountCount << endl;
                            cout << "Total Transactions: " << transactionCount << endl;
                        }
 
                        // ===== ADMIN OPTION 13: LOGOUT =====
                        else if (adminChoice == 13) {
                            cout << "\nLOGGING OUT..." << endl;
                            adminLoggedIn = false;
                        }
 
                        else {
                            cout << "ERROR: INVALID OPTION!" << endl;
                        }
                    }
                    break;
                } else {
                    cout << "ERROR: WRONG PASSWORD OR USERNAME!" << endl;
                    if (i < 2) {
                        cout << "ATTEMPTS REMAINING: " << (2 - i) << endl;
                    }
                }
            }
 
            if (!adminLoginSuccess) {
                cout << "TOO MANY FAILED ATTEMPTS. ACCESS DENIED." << endl;
            }
        }
 
        // ===== CUSTOMER LOGIN =====
        else if (mainChoice == 2) {
            cout << "\n";
            cout << "#################################################################################" << endl;
            cout << "#                                                                               #" << endl;
            cout << "#                      *** CUSTOMER LOGIN PAGE ***                              #" << endl;
            cout << "#                                                                               #" << endl;
            cout << "#################################################################################" << endl;
 
            int loginAccountID;
            string loginPin;
 
            cout << "\nENTER ACCOUNT ID: ";
            cin >> loginAccountID;
            cout << "ENTER PIN: ";
            cin >> loginPin;
 
            int index = -1;
            for (int i = 0; i < accountCount; i++) {
                if (accountID[i] == loginAccountID && pin[i] == loginPin) {
                    index = i;
                    break;
                }
            }
 
            if (index == -1) {
                cout << "ERROR: INVALID ACCOUNT ID OR PIN!" << endl;
            } else if (!isActive[index]) {
                cout << "ERROR: YOUR ACCOUNT HAS BEEN DEACTIVATED!" << endl;
            } else {
                cout << "\n<<<<<SUCCESS: WELCOME " << customerName[index] << ".>>>>>" << endl;
 
                // ===== CUSTOMER MENU LOOP =====
                bool customerLoggedIn = true;
                while (customerLoggedIn) {
                    cout << "\n";
                    cout << "==========================================" << endl;
                    cout << "      *** CUSTOMER MENU PORTAL ***         " << endl;
                    cout << "==========================================" << endl;
                    cout << "1.  VIEW ACCOUNT DETAILS" << endl;
                    cout << "2.  DEPOSIT MONEY" << endl;
                    cout << "3.  WITHDRAW MONEY" << endl;
                    cout << "4.  VIEW TRANSACTION HISTORY" << endl;
                    cout << "5.  TRANSFER FUNDS" << endl;
                    cout << "6.  VIEW PERSONAL PROFILE" << endl;
                    cout << "7.  CALCULATE LOAN ELIGIBILITY" << endl;
                    cout << "8.  APPLY FOR LOAN (10% Interest Rate)" << endl;
                    cout << "9.  PAY LOAN INSTALLMENT" << endl;
                    cout << "10. CHANGE SECURITY PIN" << endl;
                    cout << "11. VIEW LAST 5 TRANSACTIONS" << endl;
                    cout << "12. SAVINGS PROJECTION" << endl;
                    cout << "13. CHECK TAX CONTRIBUTION HISTORY" << endl;
                    cout << "14. LOGOUT" << endl;
                    cout << "==========================================" << endl;
                    cout << "ENTER YOUR CHOICE: ";
 
                    int custChoice;
                    cin >> custChoice;
 
                    // ===== CUSTOMER OPTION 1: VIEW ACCOUNT DETAILS =====
                    if (custChoice == 1) {
                        cout << "\n========== YOUR ACCOUNT DETAILS ==========" << endl;
                        cout << "Account ID: " << accountID[index] << endl;
                        cout << "Name: " << customerName[index] << endl;
                        cout << "Current Balance: $" << balance[index] << endl;
                        cout << "Loan Balance: $" << loanBalance[index] << endl;
                        cout << "Tax Paid: $" << taxPaid[index] << endl;
                    }
 
                    // ===== CUSTOMER OPTION 2: DEPOSIT MONEY =====
                    else if (custChoice == 2) {
                        cout << "\n========== DEPOSIT MONEY ==========" << endl;
                        double depositAmount;
                        cout << "ENTER DEPOSIT AMOUNT: $";
                        cin >> depositAmount;
 
                        if (depositAmount <= 0) {
                            cout << "ERROR: AMOUNT MUST BE POSITIVE!" << endl;
                        } else {
                            balance[index] += depositAmount;
 
                            
                            if (balance[index] > 100000) {
                                double tax = depositAmount * 0.05;
                                taxPaid[index] += tax;
                            }
 
                            string depositDate;
                            cout << "ENTER DATE (YYYY-MM-DD): ";
                            cin >> depositDate;
 
                            if (transactionCount < 500) {
                                transactionID[transactionCount]  = transactionCount + 1;
                                txnAccountID[transactionCount]   = accountID[index];
                                txnType[transactionCount]        = "Deposit";
                                txnAmount[transactionCount]      = depositAmount;
                                txnDate[transactionCount]        = depositDate;
                                transactionCount++;
                            }
 
                            cout << "DEPOSIT SUCCESSFUL!" << endl;
                            cout << "NEW BALANCE: $" << balance[index] << endl;
                        }
                    }
 
                    // ===== CUSTOMER OPTION 3: WITHDRAW MONEY =====
                    else if (custChoice == 3) {
                        cout << "\n========== WITHDRAW MONEY ==========" << endl;
                        double withdrawAmount;
                        cout << "ENTER WITHDRAWAL AMOUNT: $";
                        cin >> withdrawAmount;
 
                        if (withdrawAmount <= 0) {
                            cout << "ERROR: AMOUNT MUST BE POSITIVE!" << endl;
                        } else if (balance[index] < withdrawAmount) {
                            cout << "ERROR: INSUFFICIENT BALANCE! AVAILABLE: $" << balance[index] << endl;
                        } else {
                            balance[index] -= withdrawAmount;
 
                            string withdrawDate;
                            cout << "ENTER DATE (YYYY-MM-DD): ";
                            cin >> withdrawDate;
 
                            if (transactionCount < 500) {
                                transactionID[transactionCount]  = transactionCount + 1;
                                txnAccountID[transactionCount]   = accountID[index];
                                txnType[transactionCount]        = "Withdrawal";
                                txnAmount[transactionCount]      = withdrawAmount;
                                txnDate[transactionCount]        = withdrawDate;
                                transactionCount++;
                            }
 
                            cout << "WITHDRAWAL SUCCESSFUL!" << endl;
                            cout << "NEW BALANCE: $" << balance[index] << endl;
                        }
                    }
 
                    // ===== CUSTOMER OPTION 4: VIEW TRANSACTION HISTORY =====
                    else if (custChoice == 4) {
                        cout << "\n========== TRANSACTION HISTORY ==========" << endl;
                        cout << "Txn ID\tType\t\tAmount\t\tDate" << endl;
                        cout << "=================================================" << endl;
                        bool found = false;
                        for (int i = 0; i < transactionCount; i++) {
                            if (txnAccountID[i] == accountID[index]) {
                                cout << transactionID[i] << "\t" << txnType[i]
                                     << "\t$" << txnAmount[i] << "\t\t" << txnDate[i] << endl;
                                found = true;
                            }
                        }
                        if (!found) cout << "NO TRANSACTIONS AVAILABLE." << endl;
                    }
 
                    // ===== CUSTOMER OPTION 5: TRANSFER FUNDS =====
                    else if (custChoice == 5) {
                        cout << "\n========== TRANSFER FUNDS ==========" << endl;
                        int toID;
                        double transferAmount;
 
                        cout << "ENTER RECIPIENT ACCOUNT ID: ";
                        cin >> toID;
                        cout << "ENTER AMOUNT: $";
                        cin >> transferAmount;
 
                        
                        if (toID == accountID[index]) {
                            cout << "ERROR: CANNOT TRANSFER TO YOUR OWN ACCOUNT!" << endl;
                        } else if (transferAmount <= 0) {
                            cout << "ERROR: TRANSFER AMOUNT MUST BE POSITIVE!" << endl;
                        } else {
                            int toIndex = -1;
                            for (int i = 0; i < accountCount; i++) {
                                if (accountID[i] == toID) {
                                    toIndex = i;
                                    break;
                                }
                            }
 
                            if (toIndex == -1) {
                                cout << "ERROR: RECIPIENT ACCOUNT NOT FOUND!" << endl;
                            } else if (!isActive[toIndex]) {
                                
                                cout << "ERROR: RECIPIENT ACCOUNT IS INACTIVE!" << endl;
                            } else if (balance[index] < transferAmount) {
                                cout << "ERROR: INSUFFICIENT BALANCE!" << endl;
                            } else {
                                balance[index]   -= transferAmount;
                                balance[toIndex] += transferAmount;
 
                                string transferDate;
                                cout << "ENTER DATE (YYYY-MM-DD): ";
                                cin >> transferDate;
 
                                if (transactionCount < 500) {
                                    transactionID[transactionCount]  = transactionCount + 1;
                                    txnAccountID[transactionCount]   = accountID[index];
                                    txnType[transactionCount]        = "Transfer Out";
                                    txnAmount[transactionCount]      = transferAmount;
                                    txnDate[transactionCount]        = transferDate;
                                    transactionCount++;
                                }
                                if (transactionCount < 500) {
                                    transactionID[transactionCount]  = transactionCount + 1;
                                    txnAccountID[transactionCount]   = toID;
                                    txnType[transactionCount]        = "Transfer In";
                                    txnAmount[transactionCount]      = transferAmount;
                                    txnDate[transactionCount]        = transferDate;
                                    transactionCount++;
                                }
 
                                cout << "TRANSFER SUCCESSFUL!" << endl;
                            }
                        }
                    }
 
                    // ===== CUSTOMER OPTION 6: VIEW PERSONAL PROFILE =====
                    else if (custChoice == 6) {
                        cout << "\n========== PERSONAL PROFILE ==========" << endl;
                        cout << "Account ID: " << accountID[index] << endl;
                        cout << "Name: " << customerName[index] << endl;
                        
                        cout << "Security PIN: ****" << endl;
                        cout << "Account Status: " << (isActive[index] ? "Active" : "Inactive") << endl;
                    }
 
                    // ===== CUSTOMER OPTION 7: CALCULATE LOAN ELIGIBILITY =====
                    else if (custChoice == 7) {
                        cout << "\n========== LOAN ELIGIBILITY ==========" << endl;
                        double maxLoan = balance[index] * 2;
                        cout << "Current Balance: $" << balance[index] << endl;
                        cout << "Maximum Loan Amount (Balance x 2): $" << maxLoan << endl;
                    }
 
                    // ===== CUSTOMER OPTION 8: APPLY FOR LOAN =====
                    else if (custChoice == 8) {
                        cout << "\n========== APPLY FOR LOAN ==========" << endl;
                        double maxLoan = balance[index] * 2;
                        cout << "Maximum Eligible: $" << maxLoan << endl;
                        cout << "ENTER LOAN AMOUNT: $";
                        double loanAmount;
                        cin >> loanAmount;
 
                        if (loanAmount <= 0) {
                            cout << "ERROR: LOAN AMOUNT MUST BE POSITIVE!" << endl;
                        } else if (loanAmount > maxLoan) {
                            cout << "ERROR: EXCEEDS MAXIMUM ELIGIBLE AMOUNT!" << endl;
                        } else if (loanBalance[index] > 0) {
                            cout << "ERROR: EXISTING LOAN FOUND! PAY PREVIOUS LOAN FIRST!" << endl;
                        } else {
                            double interestAmount  = loanAmount * 0.10;
                            loanBalance[index]     = loanAmount + interestAmount;
 
                            cout << "LOAN APPROVED!" << endl;
                            cout << "Principal: $" << loanAmount << endl;
                            cout << "Interest (10%): $" << interestAmount << endl;
                            cout << "Total Amount Due: $" << loanBalance[index] << endl;
                        }
                    }
 
                    // ===== CUSTOMER OPTION 9: PAY LOAN INSTALLMENT =====
                    else if (custChoice == 9) {
                        cout << "\n========== PAY LOAN INSTALLMENT ==========" << endl;
                        cout << "Current Loan Balance: $" << loanBalance[index] << endl;
 
                        if (loanBalance[index] == 0) {
                            cout << "NO ACTIVE LOAN!" << endl;
                        } else {
                            cout << "ENTER PAYMENT AMOUNT: $";
                            double paymentAmount;
                            cin >> paymentAmount;
 
                            if (paymentAmount <= 0) {
                                cout << "ERROR: PAYMENT AMOUNT MUST BE POSITIVE!" << endl;
                            } else if (paymentAmount > loanBalance[index]) {
                                cout << "ERROR: EXCEEDS LOAN BALANCE!" << endl;
                            } else if (balance[index] < paymentAmount) {
                                
                                cout << "ERROR: INSUFFICIENT ACCOUNT BALANCE TO MAKE PAYMENT!" << endl;
                            } else {
                                // (continued): Deduct payment from account balance too
                                balance[index]      -= paymentAmount;
                                loanBalance[index]  -= paymentAmount;
 
                                string payDate;
                                cout << "ENTER DATE (YYYY-MM-DD): ";
                                cin >> payDate;
 
                                if (transactionCount < 500) {
                                    transactionID[transactionCount]  = transactionCount + 1;
                                    txnAccountID[transactionCount]   = accountID[index];
                                    txnType[transactionCount]        = "Loan Payment";
                                    txnAmount[transactionCount]      = paymentAmount;
                                    txnDate[transactionCount]        = payDate;
                                    transactionCount++;
                                }
 
                                cout << "PAYMENT SUCCESSFUL!" << endl;
                                cout << "AMOUNT DEDUCTED FROM ACCOUNT BALANCE." << endl;
                                if (loanBalance[index] == 0) {
                                    cout << "LOAN PAID OFF! CONGRATULATIONS!" << endl;
                                } else {
                                    cout << "Remaining Loan Balance: $" << loanBalance[index] << endl;
                                    cout << "Remaining Account Balance: $" << balance[index] << endl;
                                }
                            }
                        }
                    }
 
                    // ===== CUSTOMER OPTION 10: CHANGE SECURITY PIN =====
                    else if (custChoice == 10) {
                        cout << "\n========== CHANGE SECURITY PIN ==========" << endl;
                        string oldPIN;
                        cout << "ENTER CURRENT PIN: ";
                        cin >> oldPIN;
 
                        if (oldPIN != pin[index]) {
                            cout << "ERROR: INCORRECT PIN!" << endl;
                        } else {
                            
                            string newPIN;
                            bool pinValid = false;
                            while (!pinValid) {
                                cout << "ENTER NEW PIN (exactly 4 digits): ";
                                cin >> newPIN;
                                if (newPIN.length() == 4) {
                                    pinValid = true;
                                    for (int c = 0; c < 4; c++) {
                                        if (newPIN[c] < '0' || newPIN[c] > '9') {
                                            pinValid = false;
                                            break;
                                        }
                                    }
                                }
                                if (!pinValid) cout << "ERROR: PIN MUST BE EXACTLY 4 DIGITS!" << endl;
                            }
                            pin[index] = newPIN;
                            cout << "PIN CHANGED SUCCESSFULLY!" << endl;
                        }
                    }
 
                    // ===== CUSTOMER OPTION 11: VIEW LAST 5 TRANSACTIONS =====
                    else if (custChoice == 11) {
                        cout << "\n========== LAST 5 TRANSACTIONS ==========" << endl;
                        cout << "Type\t\tAmount\t\tDate" << endl;
                        cout << "============================================" << endl;
 
                        int count = 0;
                        for (int i = transactionCount - 1; i >= 0 && count < 5; i--) {
                            if (txnAccountID[i] == accountID[index]) {
                                cout << txnType[i] << "\t$" << txnAmount[i]
                                     << "\t\t" << txnDate[i] << endl;
                                count++;
                            }
                        }
                        if (count == 0) cout << "NO TRANSACTIONS AVAILABLE." << endl;
                    }
 
                    // ===== CUSTOMER OPTION 12: SAVINGS PROJECTION =====
                    else if (custChoice == 12) {
                        cout << "\n========== SAVINGS PROJECTION ==========" << endl;
                        cout << "Current Balance: $" << balance[index] << endl;
                        cout << "ENTER ANNUAL INTEREST RATE (e.g., 5 for 5%): ";
                        double rate;
                        cin >> rate;
                        cout << "ENTER NUMBER OF YEARS: ";
                        int years;
                        cin >> years;
 
                        if (rate < 0 || years < 0) {
                            cout << "ERROR: INTEREST RATE AND YEARS MUST BE NON-NEGATIVE!" << endl;
                        } else {
                            double p = balance[index];
                            double r = rate / 100.0;
                            double projectedAmount = p * pow(1 + r, years);
 
                            cout << "\nUsing Formula: A = P(1+r)^t" << endl;
                            cout << "After " << years << " years at " << rate << "% interest:" << endl;
                            cout << "PROJECTED AMOUNT: $" << projectedAmount << endl;
                            cout << "INTEREST EARNED: $" << (projectedAmount - p) << endl;
                        }
                    }
 
                    // ===== CUSTOMER OPTION 13: CHECK TAX CONTRIBUTION =====
                    else if (custChoice == 13) {
                        cout << "\n========== TAX CONTRIBUTION HISTORY ==========" << endl;
                        // (continued): taxPaid is now actually tracked, so display is meaningful
                        cout << "Total Tax Paid: $" << taxPaid[index] << endl;
 
                        if (balance[index] > 100000) {
                            double tax = balance[index] * 0.05;
                            cout << "Current Balance Qualifies for Tax (5%): $" << tax << endl;
                        }
                    }
 
                    // ===== CUSTOMER OPTION 14: LOGOUT =====
                    else if (custChoice == 14) {
                        cout << "\nTHANK YOU FOR USING OUR BANKING SYSTEM!" << endl;
                        customerLoggedIn = false;
                    }
 
                    else {
                        cout << "ERROR: INVALID OPTION!" << endl;
                    }
                }
            }
        }
 
        // ===== EXIT SYSTEM =====
        else if (mainChoice == 3) {
            cout << "\n#################################################################################" << endl;
            cout << "#                          THANK YOU FOR USING                               #" << endl;
            cout << "#                         OUR BANKING SYSTEM. GOODBYE!                       #" << endl;
            cout << "#################################################################################" << endl;
            systemRunning = false;
        }
 
        else {
            cout << "ERROR: INVALID CHOICE! PLEASE TRY AGAIN." << endl;
        }
    }
 
    return 0;
}