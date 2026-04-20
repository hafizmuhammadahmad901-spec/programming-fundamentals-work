#include <iostream>
#include <string>

using namespace std;

void calculatePyramidVolume(double length, double width, double height, string unit) {
    double volumeInMeters = (length * width * height) / 3.0;
    double finalVolume = 0.0;

    if (unit == "millimeters") {
        finalVolume = volumeInMeters * 1000 * 1000 * 1000;
    } 
    else if (unit == "centimeters") {
        finalVolume = volumeInMeters * 100 * 100 * 100;
    } 
    else if (unit == "meters") {
        finalVolume = volumeInMeters;
    } 
    else if (unit == "kilometers") {
        finalVolume = volumeInMeters / (1000.0 * 1000.0 * 1000.0);
    }

    cout << finalVolume << " cubic " << unit << endl;
}

int main() {
    double l, w, h;
    string targetUnit;

    cout << "Enter Length: "; 
    cin >> l;
    cout << "Enter Width: "; 
    cin >> w;
    cout << "Enter Height: "; 
    cin >> h;
    cout << "Enter Unit: ";
    cin >> targetUnit;

    calculatePyramidVolume(l, w, h, targetUnit);

    return 0;
}