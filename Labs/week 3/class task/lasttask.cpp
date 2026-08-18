#include<iostream>
using namespace std;
main() {


  int population;
   int n;

    cout << "Enter the current world population: ";
    cin >> population;

    cout << "Enter the number of people born each month: ";
    cin >> n;

   int  months = 30 * 12;  // 3 decades = 30 years
  int future_population = population + (n * months);

    cout << "The population in three decades will be: " << future_population;

  
}
	