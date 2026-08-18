#include<iostream>
using namespace std;
int main() {
    string word;
    char letter;
    bool is_found = false;
    cout<<"ENTER A WORD :"<<endl;
    cin>>word;
    cout<<"ENTER THE CHARACTER YOU WANT TO FIND :"<<endl;
    cin>>letter;
    for(int i = 0; word[0] != 0; i++){
        if(word[i] == letter) {
            is_found =true;
            break;
        }


    }
    if(is_found ){
    cout<<letter<<"is found in"<<word<<endl;
    }
    else{

        cout<<letter<<"is not found in"<<word<<endl;
    }

}