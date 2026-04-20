#include<iostream> 
#include<string>
using namespace std;
string checkalphabetcase(char input){
    if(input >= 'A'&& input<='Z'){
        return "you have entered a capital letter";
        
    }
    else{
        return"YOU HAVE ENTERED A SMALL LETTER";

    }
    
}
int main() {
    char user;
    cout<<"ENTER AN ALPHABET :"<<endl;
    cin>>user;
    string  result =  checkalphabetcase(user);
    cout<<result<<endl;

}