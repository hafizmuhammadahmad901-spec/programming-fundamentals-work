#include<iostream>
using namespace std;
int main() {
    int n;
    cout<<"ENTER HOW MANY NUMBERS :"<<endl;
    cin>>n;
    int arr[100];
    for(int i = 0; i<n; i++){
        int num;
        
        cout<<"ENTER A NUMBER :"<<i+1<<endl;
        cin>>num;
         bool found = false;
        for(int j = 0; j<i; j++){
            if(arr[j]==num){
                found=true;
                break;


            }
            
        }
        if(found){
                cout<<"ALREADY ENTERED"<<endl;
                i--;

            }
            else{
                arr[i] =num;
            }
    }
    cout<<"\nFINAL NUMBERS ARE :\n";
    for(int i = 0; i<n;i++){
        cout<< arr[i]<<" "<<endl;
    }

    
}