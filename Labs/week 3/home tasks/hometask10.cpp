#include <iostream>
using namespace std;

int main() {

    double n1, n2, n3, n4, n5;
    double n6, n7, n8, n9, n10;
    double n11, n12, n13, n14, n15;

    cout << "Enter first five numbers: " << endl;
    cin >> n1 >> n2 >> n3 >> n4 >> n5;

    cout << "Enter next five numbers: " << endl;
    cin >> n6 >> n7 >> n8 >> n9 >> n10;

    cout << "Enter last five numbers: " << endl;
    cin >> n11 >> n12 >> n13 >> n14 >> n15;

    double sum = n1 + n2 + n3 + n4 + n5;
    double product = n6 * n7 * n8 * n9 * n10;
    double subtraction = n11 - n12 - n13 - n14 - n15;

    double result = (sum + product) - subtraction;

    cout << "Final Result: " << result << endl;

    return 0;
}