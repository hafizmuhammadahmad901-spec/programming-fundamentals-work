#include <iostream>
using namespace std;
void printCars(int cars[] [5],int rowSize);

int main() {
    const int rowSize = 5;
    const int colSize = 5;
    int cars[rowSize][colSize] = {
        {10,7,12,10,4},
        {18,11,15,17,2},
        {23,19,12,16,14},
        {5,8,6,9,3},
        {12,14,10,11,5}};
        printCars(cars,rowSize);

    };  
    void printCars(int cars[][5],int rowSize){
        for (int i = 0; i < rowSize; i++) {
            for (int j = 0; j < 5; j++) {
                cout << cars[i][j] << " ";
            }
            cout << endl;
        }

    

    
}