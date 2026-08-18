#include<iostream>
using namespace std;
int main() {
    string atm_pin;
    int choice;
	int current_balance= 10000;
     int deposit_cash;
     int withdraw_cash;
    int i = 0;
   
    
   
	
    for(int i=1; i <= 3; i++) {
		
		 cout<<"Enter the 4-digit ATM PIN: ";
         cin>>atm_pin;
        if(atm_pin=="1234") {
            cout<<"YOU HAVE LOGGED IN SUCCESSFULLY!"<<endl;
			break;

        }
		else
		cout<<"WRONG LOGIN"<<endl;
	}
	if( i == 3 && !( atm_pin=="1234")){
		cout<<"TOO MANY ATTEMPTS, PROGRAM ENDS"<<endl;
		return 0;
	}
		
	
    
	   for(int i=1; i<=3; i++) {
		cout<<   " =============================== ATM MAIN MENU====================================="<<endl;
		
	
        cout<<"                              1. PRESS 1 TO CHECK BALANCE                                 "<<endl;
        
        cout<<"                              2. PRESS 2 TO DEPOSIT CASH                               "<<endl;                      
        
        cout<<"                              3. PRESS 3 TO WITHDRAW CASH                              "<<endl;
		cout<<"                              4. PRESS 4 TO EXIT                                       "<<endl;
		cout<<" ENTER CHOICE  "<<endl;
        cin>>choice;
      
    
	}
        if(choice==1) {
			
            cout<<"Your current balance is: $"<<current_balance<<endl;
			

        }   
		
			
        else if(choice==2) {
			cout<<"ENTER MONEY DO YOU WANT TO DEPOSIT :"<<endl;
			cin>>deposit_cash;
            
            cout<<"You have deposited: $"<<deposit_cash<<endl;
        }
        else if(choice==3) {
			cout<<"ENTER MONEY YOU WANT TO WITHDRAW"<<endl;
			cin>>withdraw_cash;
           cout<<"You have withdrawn: $"<<withdraw_cash<<endl;
		   if(withdraw_cash > current_balance && current_balance < withdraw_cash){
			   cout<<"SORRY! INSUFFICIENT BALANCE " <<endl;
			   
			   
            
            }
            if(choice==4){
                cout<<"THANKYOU SO MUCH FOR USING ATM";
            }
		
			else{
				cout<<"THE PROGRAM EXITS"<<endl;
			}
		
            
			
			
        
 
    
}
    
}