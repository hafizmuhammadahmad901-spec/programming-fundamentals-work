#include <iostream>
using namespace std;


void calculatePoolState(double V, double P1, double P2, double H) {
    
    
    double waterP1 = P1 * H;
    double waterP2 = P2 * H;
    double totalWater = waterP1 + waterP2;

    if (totalWater <= V) {
        
        int totalPercent = (totalWater / V) * 100;
        int p1Percent = (waterP1 / totalWater) * 100;
        int p2Percent = (waterP2 / totalWater) * 100;

        
        cout << "The pool is " << totalPercent << "% full. ";
        cout << "Pipe 1: " << p1Percent << "%. ";
        cout << "Pipe 2: " << p2Percent << "%." << endl;
    } 
    else {
        
        double overflow = totalWater - V;
        cout << "For " << H << " hours the pool overflows with ";
        cout << overflow << " liters." << endl;
    }
}

int main() {
    double V, P1, P2, H;

    
    cout << "Enter Pool Volume (liters): ";
    cin >> V;
    cout << "Enter Pipe 1 Flow Rate (liters/hr): ";
    cin >> P1;
    cout << "Enter Pipe 2 Flow Rate (liters/hr): ";
    cin >> P2;
    cout << "Enter Hours Worker was Absent: ";
    cin >> H;

    
    cout << "Result: ";
    calculatePoolState(V, P1, P2, H);

    return 0;
}