#include <iostream>
    
using namespace std;

float taxCalculator(char type, float price) {
    float rate = 0;

    if (type == 'M' || type == 'm') {
        rate = 0.06;
    }
    else if (type == 'E' || type == 'e') {
        rate = 0.08;
    }
    else if (type == 'S' || type == 's') {
        rate = 0.10;
    }
    else if (type == 'V' || type == 'v') {
        rate = 0.12;
    }
    else if (type == 'T' || type == 't') {
        rate = 0.15;
    }

    float taxAmount = price * rate;
    float finalPrice = price + taxAmount;

    return finalPrice;
}

int main() {
    char vehicleType;
    float itemPrice;
    string typeName;

    cout << "Enter vehicle price: ";
    cin >> itemPrice;
    cout << "Enter vehicle code (M, E, S, V, T): ";
    cin >> vehicleType;

    if (vehicleType == 'M' || vehicleType == 'm') 
{
    typeName = "Motorcycle";
}
else if (vehicleType == 'E' || vehicleType == 'e') 
{
    typeName = "Electric";
}
else if (vehicleType == 'S' || vehicleType == 's') 
{
    typeName = "Sedan";
}
else if (vehicleType == 'V' || vehicleType == 'v') 
{
    typeName = "Van";
}
else if (vehicleType == 'T' || vehicleType == 't') 
{
    typeName = "Truck";
}
else 
{
    typeName = "Unknown";
}

    float result = taxCalculator(vehicleType, itemPrice);

    cout << "The final price on a vehicle of type " << typeName;
    cout << " after adding the tax is $" << result << "." << endl;

    return 0;
}