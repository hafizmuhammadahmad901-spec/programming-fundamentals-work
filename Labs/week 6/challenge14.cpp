#include<iostream>
using namespace std;
int main() {
     string chord[] = {"C7", "G7","G", "H", "a" };
   int size = sizeof(chord) / sizeof(chord[0]);
    for (int i=0;i< size; i++){
        if (chord[i].back() != '7')
        chord [i] +="7";
       
    }

    for (int i=0; i< size; i++){
 cout << chord[i] << " ";
    }
}