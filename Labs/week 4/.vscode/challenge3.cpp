#include<iostream>
using namespace std;
main() {
    string word1;
    string word2;
    cout<<"ENTER THE FIRST WORD :";
    cin>>word1;
    cout<<"ENTER THE SECOND WORD :";
    cin>>word2;
    if(word2==word1){
        cout<<"YES, THE WORDS ARE SAME";

    }
    else{
        cout<<"NO, THE WORDS ARE NOT SAME";
    }
}