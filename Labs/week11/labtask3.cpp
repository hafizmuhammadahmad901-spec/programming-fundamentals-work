#include <iostream>
using namespace std;


void printToyotaBlue(string cars[][2], int rows) {
    cout << "\nToyota Blue Cars:\n";
    for (int i = 0; i < rows; i++) {
        if (cars[i][0] == "Toyota" && cars[i][1] == "Blue") {
            cout << cars[i][0] << " " << cars[i][1] << endl;
        }
    }
}


int countRedCars(string cars[][2], int rows) {
    int count = 0;
    for (int i = 0; i < rows; i++) {
        if (cars[i][1] == "Red") {
            count++;
        }
    }
    return count;
}


int countNissanCars(string cars[][2], int rows) {
    int count = 0;
    for (int i = 0; i < rows; i++) {
        if (cars[i][0] == "Nissan") {
            count++;
        }
    }
    return count;
}


int converter(string cars[][2], int rows, string color) {
    int count = 0;
    for (int i = 0; i < rows; i++) {
        if (cars[i][1] == color) {
            count++;
        }
    }
    return count;
}


void transpose(string cars[][2], int rows) {
    cout << "Transpose Matrix:";
    
    for (int j = 0; j < 2; j++) {  
        for (int i = 0; i < rows; i++) {
            cout << cars[i][j] << "\t";
        }
        cout << endl;
    }
}


int main() {

    string cars[6][2] = {
        {"Toyota", "Blue"},
        {"Nissan", "Red"},
        {"Toyota", "Red"},
        {"Honda", "Blue"},
        {"Nissan", "Blue"},
        {"Toyota", "Blue"}
    };

    int rows = 6;

    
    printToyotaBlue(cars, rows);

   
    cout << "\nTotal Red Cars: " << countRedCars(cars, rows);

    
    cout << "\nTotal Nissan Cars: " << countNissanCars(cars, rows);

    
    cout << "\nTotal Blue Cars (converter): " 
         << converter(cars, rows, "Blue");

   
    transpose(cars, rows);

    return 0;
}