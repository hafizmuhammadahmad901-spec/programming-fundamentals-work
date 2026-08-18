#include<iostream>
using namespace std;
int main() {
    int shape;
    cout << "ENTER THE SHAPE (1-SQUARE, 2-RECTANGLE, 3-TRIANGLE, 4-CIRCLE) :";
    cin >> shape;

    if (shape == 1) {
        int side;
        cout << "ENTER THE SIDE OF SQUARE :";
        cin >> side;
        int area_of_square = side * side;
        cout << "AREA OF SQUARE :" << area_of_square << endl;
        return 0;
    }
    if (shape == 2) {
        int width, length;
        cout << "ENTER THE WIDTH OF RECTANGLE :";
        cin >> width;
        cout << "ENTER THE LENGTH OF RECTANGLE :";
        cin >> length;
        int area_of_rectangle = width * length;
        cout << "AREA OF RECTANGLE :" << area_of_rectangle << endl;
        return 0;
    }
    if (shape == 3) {
        int base, height;
        cout << "ENTER THE BASE OF TRIANGLE :";
        cin >> base;
        cout << "ENTER THE HEIGHT OF TRIANGLE :";
        cin >> height;
        float area_of_triangle = 0.5f * base * height;
        cout << "AREA OF TRIANGLE :" << area_of_triangle << endl;
        return 0;
    }
    if (shape == 4) {
        int radius;
        cout << "ENTER THE RADIUS OF CIRCLE :";
        cin >> radius;
        float area_of_circle = 3.14159f * radius * radius;
        cout << "AREA OF CIRCLE :" << area_of_circle << endl;
        return 0;
    }
    cout << "INVALID SHAPE ENTERED." << endl;
    return 0;
}
