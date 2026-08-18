#include<iostream>
using namespace std;
int main() {
   int n;
   cout<<"HOW MANY NUMBERS DO YOU WANT TO ENTER :"<<endl;
   cin>> n;
   int arr[100];

   for(int i = 0; i<n; i=i+1){
    cout<<"ENTER"<<n<<"numbers:\n";
    cin>>arr[i];
   }
   for(int i = 0; i < n; i++){
    cout<<"THE NUMBERS YOU ENTERED ARE :\n";
    cout<<arr[i] <<" ";
   }

  return 0;


}