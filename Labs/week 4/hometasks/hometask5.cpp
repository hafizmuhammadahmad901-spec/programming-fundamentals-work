#include <iostream>

using namespace std;

int main() {
    
    const int totalDaysInYear = 365;
    const int annualNorm = 30000;
    const int playTimeWorkingDay = 63;
    const int playTimeHoliday = 127;

    int holidays;
    cout << "Enter number of holidays: ";
    cin >> holidays;

    
    int workingDays = totalDaysInYear - holidays;

    
    int totalPlayTime = (workingDays * playTimeWorkingDay) + (holidays * playTimeHoliday);

   
    int difference = annualNorm - totalPlayTime;

    if (totalPlayTime <= annualNorm) {
        
        cout << "Tom sleeps well" << endl;
        
        int hours = difference / 60;
        int minutes = difference % 60;
        cout << hours << " hours and " << minutes << " minutes less for play" << endl;
    } 
    else {
        
        cout << "Tom will run away" << endl;
        
        
        int overLimit = totalPlayTime - annualNorm;
        int hours = overLimit / 60;
        int minutes = overLimit % 60;
        cout << hours << " hours and " << minutes << " minutes excess for play" << endl;
    }

    return 0;
}