#include<iostream>
using namespace std;
int main() {
    char ch;
    cout<<"ENTER THE CHARACTER :";
    cin>>ch;
    
     if(ch>='0' && ch<='9') {
        cout<<"the character is a digit";

    }
    else if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U') {
        cout<<"the character is a vowel";
    }
    else if(ch=='b' || ch=='c' || ch=='d' || ch=='f' || ch=='g' || ch=='h' || ch=='j' || ch=='k' || ch=='l' || ch=='m' || ch=='n' || ch=='p' || ch=='q' || ch=='r' || ch=='s' || ch=='t' || ch=='v' || ch=='w' || ch=='x' || ch=='y' || ch=='z' || ch=='B' || ch=='C' || ch=='D' || ch=='F' || ch=='G' || ch=='H' || ch=='J' || ch=='K' || ch=='L' || ch=='M' || ch=='N' || ch=='P' || ch=='Q' || ch=='R' || ch=='S' || ch=='T' || ch=='V' || ch=='W' || ch=='X' || ch=='Y'||ch =='Z') {
        cout<<"the character is a consonant";


    }
    else{
        cout<<"the character is a special character";
    

    
    }
    
   
}

