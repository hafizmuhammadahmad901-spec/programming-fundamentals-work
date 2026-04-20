#include <iostream>

using namespace std;

void projectTimeCalculation(int neededHours, int days, int workers) 
{
    double availableDays = days - (days * 0.10);
    
    int totalHours = availableDays * workers * 10;

    if (totalHours >= neededHours) 
    {
        int hoursLeft = totalHours - neededHours;
        cout << "Yes!" << hoursLeft << " hours left." << endl;
    }
    else 
    {
        int hoursNeeded = neededHours - totalHours;
        cout << "Not enough time!" << hoursNeeded << " hours needed." << endl;
    }
}

int main() 
{
    int neededHours, days, workers;

    cout << "Enter needed hours: ";
    cin >> neededHours;
    cout << "Enter days available: ";
    cin >> days;
    cout << "Enter number of workers: ";
    cin >> workers;

    projectTimeCalculation(neededHours, days, workers);

    return 0;
}