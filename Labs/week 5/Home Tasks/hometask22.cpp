#include<iostream>
using namespace std;
int main() {
    int choice;
    while(true){
        cout<<"======================================= LIBRARY SYSTEM ========================================"<<endl;
        cout<<"                             1. ADD BOOK"   <<endl;
        cout<<"                             2. VIEW BOOK" <<endl;
        cout<<"                             3. BORROW BOOK"<<endl;
        cout<<"                             4. ISSUE BOOK "<<endl;
        cout<<"                             5. EXIT          "<<endl;
        cout<<"ENTER YOUR CHOICE"<<endl;
        cin>>choice;


        if(choice==1){
            cout<<"ENTER BOOK NAME : "<<endl;
            cout<<"YOU ADDED A BOOK :"<<endl;
        }
        else if(choice==2){
            cout<<"YOU VIEWED A BOOK :"<<endl;

        }
        else if(choice==3){
            cout<<"YOU BORROWED A BOOK : "<<endl;

        }
        
        else if(choice==4){
            cout<<"YOU ISSUED A BOOK : "<<endl;
            

        }
        else if(choice==5){
            cout<<"EXITING LIBRARY SYSTEM :GOOD BYE!"<<endl;
            break;
        }
        else{
            cout<<"INVALID CHOICE"<<endl;
        }

    }
}