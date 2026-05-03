#include <iostream>
#include <unistd.h>
using namespace std;

const int MaxBuses = 50;
const int MaxPassengers = 50;
int busCount = 0;

string busNo[MaxBuses];
string busType[MaxBuses];
int    busSeats[MaxBuses];
string busStatus[MaxBuses];
int    bookedSeats[MaxBuses] = {0};
int    busFare[MaxBuses]     = {0};   // NEW: per-bus fare

string passengerEmail[MaxPassengers];
string passengerPassword[MaxPassengers];

int    passengerBookedBus[MaxPassengers]    = {0};
int    passengerBookedCount[MaxPassengers]  = {0};
int    passengerCount = 0;

int    loggedInPassenger = -1; 

string managerEmail    = "manager@btms.com";
string managerPassword = "manager@123";


string adminEmail_const    = "admin@btms.com";
string adminPassword_const = "admin@123";


void header();

void adminMenu();
void manageBuses();
void addBus();
void showBus();
void updateBus();
void deleteBus();
void changeBusStatus();
// NEW Admin features
void viewBookingReport();
void resetPassengerAccount();
void setBusFare();

void passengerSignup();
bool passengerLogin();
bool validEmail(string email);
bool validPassword(string pass);

void managerMenu();
bool managerLogin();

void viewBookingSummary();
void viewBusListFormatted();
void viewPassengerCount();

void adminEmailid();
void adminPassword();

void passengerMenu();
void viewAvailableBuses();
void bookSeat();
void cancelBooking();
void viewBookings();

void viewMyProfile();
void changePassword();
void viewSeatsByType();


void searchBus();
void viewActiveBuses();
void viewSeats();


int main()
{
    
    for(int i = 0; i < MaxPassengers; i++)
    {
        passengerBookedBus[i]   = -1;
        passengerBookedCount[i] = 0;
    }

    char choice;
    system("clear");
    header();

    cout << "1. Login as Admin\n";
    cout << "2. Login as Manager\n";
    cout << "3. Login as Passenger\n";
    cout << "Choice: ";
    cin  >> choice;

    if(choice == '1')
    {
        system("clear"); header();
        adminEmailid();
        system("clear"); header();
        adminPassword();
        adminMenu();
    }
    else if(choice == '2')
    {
        system("clear");
        header();
        if(managerLogin())
            managerMenu();
    }
    else if(choice == '3')
    {
        char pchoice;
        system("clear");
        header();

        cout << "1. Signup\n";
        cout << "2. Login\n";
        cout << "Choice: ";
        cin  >> pchoice;

        if(pchoice == '1')
        {
            system("clear");
            header();
            passengerSignup();
           
            system("clear");
            header();
            cout << "Please login with your new credentials.\n\n";
            if(passengerLogin())
                passengerMenu();
        }
        else if(pchoice == '2')
        {
            system("clear");
            header();
            if(passengerLogin())
                passengerMenu();
        }
    }

    return 0;
}

// ── Admin ─────────────────────────────────────────────────────────────────────
void adminMenu()
{
    char ch;
    while(true)
    {
        system("clear"); header();
        cout << "--- ADMIN MENU ---\n";
        cout << "1. Manage Buses\n";
        cout << "2. View Booking Report\n";       
        cout << "3. Reset Passenger Account\n";   
        cout << "4. Set Bus Fare\n";            
        cout << "5. Logout\n";
        cout << "Choice: ";
        cin  >> ch;

        if     (ch == '1') manageBuses();
        else if(ch == '2') viewBookingReport();
        else if(ch == '3') resetPassengerAccount();
        else if(ch == '4') setBusFare();
        else if(ch == '5') break;
    }
}

void manageBuses()
{
    char ch;
    while(true)
    {
        system("clear");
        header();
        cout << "--- MANAGE BUSES ---\n";
        cout << "1. Add Bus\n";
        cout << "2. Update Bus\n";
        cout << "3. Delete Bus\n";
        cout << "4. Show Buses\n";
        cout << "5. Change Bus Status\n";
        cout << "6. Back\n";
        cout << "Choice: ";
        cin  >> ch;

        if     (ch == '1') addBus();
        else if(ch == '2') updateBus();
        else if(ch == '3') deleteBus();
        else if(ch == '4') showBus();
        else if(ch == '5') changeBusStatus();
        else if(ch == '6') break;
    }
}

void addBus()
{
    char choice;
    for(; busCount < MaxBuses;)
    {
        system("clear");
        header();
        cout << "--- ADD NEW BUS ---\n";
        cout << "Bus Number: ";
        cin  >> busNo[busCount];
        cout << "Bus Type: ";
        cin  >> busType[busCount];
        cout << "Seats: ";
        cin  >> busSeats[busCount];
        cout << "Fare (Rs): ";
        cin  >> busFare[busCount];

        busStatus[busCount]   = "Active";
        bookedSeats[busCount] = 0;
        busCount++;

        cout << "\nBus Added Successfully!\n";

        if(busCount >= MaxBuses)
        {
            cout << "Bus limit reached!\n";
            sleep(2);
            break;
        }

        cout << "\nAdd another bus? (Y/N): ";
        cin  >> choice;
        if(choice != 'Y' && choice != 'y') break;
    }
}

void showBus()
{
    if(busCount == 0)
    {
        cout << "No buses available\n";
        sleep(2);
        return;
    }

    cout << "No\tNumber\t\tType\t\tSeats\tBooked\tFare\tStatus\n";
    cout << "-------------------------------------------------------------------\n";
    for(int i = 0; i < busCount; i++)
    {
        cout << i+1 << "\t"
             << busNo[i] << "\t\t"
             << busType[i] << "\t\t"
             << busSeats[i] << "\t"
             << bookedSeats[i] << "\t"
             << "Rs" << busFare[i] << "\t"
             << busStatus[i] << "\n";
    }
    cout << "Press Enter...";
    cin.ignore();
    cin.get();
}

void updateBus()
{
    string search;
    cout << "Enter Bus Number: ";
    cin  >> search;

    for(int i = 0; i < busCount; i++)
    {
        if(busNo[i] == search)
        {
            cout << "New Type: ";
            cin  >> busType[i];
            cout << "New Seats: ";
            cin  >> busSeats[i];
            cout << "Updated!\n";
            sleep(2);
            return;
        }
    }
    cout << "Bus not found\n";
    sleep(2);
}

void deleteBus()
{
    string search;
    cout << "Enter Bus Number: ";
    cin  >> search;

    for(int i = 0; i < busCount; i++)
    {
        if(busNo[i] == search)
        {
            
            for(int j = i; j < busCount - 1; j++)
            {
                busNo[j]       = busNo[j+1];
                busType[j]     = busType[j+1];
                busSeats[j]    = busSeats[j+1];
                busStatus[j]   = busStatus[j+1];
                bookedSeats[j] = bookedSeats[j+1];
                busFare[j]     = busFare[j+1];
            }
            busCount--;
            cout << "Bus Deleted\n";
            sleep(2);
            return;
        }
    }
    cout << "Bus not found\n";
    sleep(2);
}

void changeBusStatus()
{
    string search;
    cout << "Enter Bus Number: ";
    cin  >> search;

    for(int i = 0; i < busCount; i++)
    {
        if(busNo[i] == search)
        {
            cout << "Current Status: " << busStatus[i] << "\n";
            cout << "Enter New Status (Active/Inactive): ";
            cin  >> busStatus[i];
            cout << "Status Updated!\n";
            sleep(2);
            return;
        }
    }
    cout << "Bus not found!\n";
    sleep(2);
}

// NEW Admin: View Booking Report with revenue
void viewBookingReport()
{
    system("clear"); header();
    cout << "--- BOOKING REPORT ---\n\n";

    if(busCount == 0)
    {
        cout << "No buses in the system.\n";
        sleep(2);
        return;
    }

    int totalBooked = 0;
    cout << "Bus No\t\tType\t\tTotal\tBooked\tAvail\tFare\tRevenue\n";
    cout << "--------------------------------------------------------------------\n";
    for(int i = 0; i < busCount; i++)
    {
        int revenue = bookedSeats[i] * busFare[i];
        totalBooked += bookedSeats[i];
        cout << busNo[i] << "\t\t"
             << busType[i] << "\t\t"
             << busSeats[i] << "\t"
             << bookedSeats[i] << "\t"
             << (busSeats[i] - bookedSeats[i]) << "\t"
             << "Rs" << busFare[i] << "\t"
             << "Rs" << revenue << "\n";
    }
    cout << "--------------------------------------------------------------------\n";
    cout << "Total Seats Booked: " << totalBooked << "\n";
    cout << "\nPress Enter...";
    cin.ignore();
    cin.get();
}

// NEW Admin: Reset a passenger's account and bookings
void resetPassengerAccount()
{
    system("clear"); header();
    cout << "--- RESET PASSENGER ACCOUNT ---\n\n";

    if(passengerCount == 0)
    {
        cout << "No passengers registered.\n";
        sleep(2);
        return;
    }

    cout << "Registered Passengers:\n";
    for(int i = 0; i < passengerCount; i++)
        cout << i+1 << ". " << passengerEmail[i] << "\n";

    string email;
    cout << "\nEnter passenger email to reset: ";
    cin  >> email;

    for(int i = 0; i < passengerCount; i++)
    {
        if(passengerEmail[i] == email)
        {
            int bi = passengerBookedBus[i];
            if(bi != -1 && bi < busCount)
            {
                bookedSeats[bi] -= passengerBookedCount[i];
                if(bookedSeats[bi] < 0) bookedSeats[bi] = 0;
            }
            passengerBookedBus[i]   = -1;
            passengerBookedCount[i] = 0;
            passengerPassword[i]    = "Reset@1";
            cout << "Account reset. Default password set to: Reset@1\n";
            sleep(2);
            return;
        }
    }
    cout << "Passenger not found.\n";
    sleep(2);
}

// NEW Admin: Set fare for a specific bus
void setBusFare()
{
    system("clear"); header();
    cout << "--- SET BUS FARE ---\n\n";

    if(busCount == 0)
    {
        cout << "No buses available.\n";
        sleep(2);
        return;
    }

    string search;
    cout << "Enter Bus Number: ";
    cin  >> search;

    for(int i = 0; i < busCount; i++)
    {
        if(busNo[i] == search)
        {
            cout << "Current Fare: Rs" << busFare[i] << "\n";
            cout << "New Fare (Rs): ";
            cin  >> busFare[i];
            cout << "Fare updated successfully!\n";
            sleep(2);
            return;
        }
    }
    cout << "Bus not found.\n";
    sleep(2);
}

// ── Manager ───────────────────────────────────────────────────────────────────
void viewActiveBuses()
{
    bool found = false;
    cout << "Bus No\t\tType\t\tSeats\tAvailable\n";
    cout << "--------------------------------------------\n";
    for(int i = 0; i < busCount; i++)
    {
        if(busStatus[i] == "Active")
        {
            cout << busNo[i] << "\t\t"
                 << busType[i] << "\t\t"
                 << busSeats[i] << "\t"
                 << (busSeats[i] - bookedSeats[i]) << "\n";
            found = true;
        }
    }
    if(!found) cout << "No active buses.\n";
    cin.ignore();
    cin.get();
}

void searchBus()
{
    string search;
    cout << "Enter Bus Number: ";
    cin  >> search;

    for(int i = 0; i < busCount; i++)
    {
        if(busNo[i] == search)
        {
            cout << "Found!\n";
            cout << "Type:   " << busType[i] << "\n";
            cout << "Seats:  " << busSeats[i] << "\n";
            cout << "Booked: " << bookedSeats[i] << "\n";
            cout << "Fare:   Rs" << busFare[i] << "\n";
            cout << "Status: " << busStatus[i] << "\n";
            cin.ignore();
            cin.get();
            return;
        }
    }
    cout << "Bus not found\n";
    sleep(2);
}

void viewSeats()
{
    string search;
    cout << "Enter Bus Number: ";
    cin  >> search;

    for(int i = 0; i < busCount; i++)
    {
        if(busNo[i] == search)
        {
            cout << "Total Seats:     " << busSeats[i] << "\n";
            cout << "Booked Seats:    " << bookedSeats[i] << "\n";
            cout << "Available Seats: " << (busSeats[i] - bookedSeats[i]) << "\n";
            cin.ignore();
            cin.get();
            return;
        }
    }
    // BUG-FIX: was completely silent on bus not found
    cout << "Bus not found!\n";
    sleep(2);
}

// NEW Manager: Booking summary totals
void viewBookingSummary()
{
    system("clear"); header();
    cout << "--- BOOKING SUMMARY ---\n\n";

    if(busCount == 0)
    {
        cout << "No buses in the system.\n";
        sleep(2);
        return;
    }

    int grandTotal = 0;
    cout << "Bus No\t\tType\t\tBooked\tCapacity\n";
    cout << "--------------------------------------------\n";
    for(int i = 0; i < busCount; i++)
    {
        grandTotal += bookedSeats[i];
        cout << busNo[i] << "\t\t"
             << busType[i] << "\t\t"
             << bookedSeats[i] << "\t"
             << busSeats[i] << "\n";
    }
    cout << "--------------------------------------------\n";
    cout << "Grand Total Booked Seats: " << grandTotal << "\n";
    cout << "\nPress Enter...";
    cin.ignore();
    cin.get();
}

// NEW Manager: Nicely formatted complete bus list
void viewBusListFormatted()
{
    system("clear"); header();
    cout << "--- COMPLETE BUS LIST ---\n\n";

    if(busCount == 0)
    {
        cout << "No buses available.\n";
        sleep(2);
        return;
    }

    for(int i = 0; i < busCount; i++)
    {
        cout << "Bus #" << i+1 << "\n";
        cout << "  Number : " << busNo[i] << "\n";
        cout << "  Type   : " << busType[i] << "\n";
        cout << "  Seats  : " << busSeats[i]
             << " (Booked: " << bookedSeats[i]
             << ", Free: " << busSeats[i] - bookedSeats[i] << ")\n";
        cout << "  Fare   : Rs" << busFare[i] << "\n";
        cout << "  Status : " << busStatus[i] << "\n";
        cout << "  ----------------------\n";
    }

    cout << "\nPress Enter...";
    cin.ignore();
    cin.get();
}

// NEW Manager: View registered passenger count
void viewPassengerCount()
{
    system("clear"); header();
    cout << "--- PASSENGER COUNT ---\n\n";
    cout << "Total Registered Passengers: " << passengerCount << " / " << MaxPassengers << "\n\n";

    if(passengerCount > 0)
    {
        cout << "Email List:\n";
        for(int i = 0; i < passengerCount; i++)
            cout << "  " << i+1 << ". " << passengerEmail[i] << "\n";
    }

    cout << "\nPress Enter...";
    cin.ignore();
    cin.get();
}

void managerMenu()
{
    char ch;
    while(true)
    {
        system("clear");
        header();
        cout << "--- MANAGER MENU ---\n";
        cout << "1. View All Buses\n";
        cout << "2. View Active Buses\n";
        cout << "3. Search Bus\n";
        cout << "4. View Seats\n";
        cout << "5. Booking Summary\n";        // NEW
        cout << "6. Complete Bus List\n";      // NEW
        cout << "7. View Passenger Count\n";   // NEW
        cout << "8. Logout\n";
        cout << "Choice: ";
        cin  >> ch;

        if     (ch == '1') showBus();
        else if(ch == '2') viewActiveBuses();
        else if(ch == '3') searchBus();
        else if(ch == '4') viewSeats();
        else if(ch == '5') viewBookingSummary();
        else if(ch == '6') viewBusListFormatted();
        else if(ch == '7') viewPassengerCount();
        else if(ch == '8') break;
    }
}

// ── Passenger ─────────────────────────────────────────────────────────────────

// BUG-FIX: only show Active buses; original showed all buses regardless of status
void viewAvailableBuses()
{
    bool found = false;
    cout << "Bus No\t\tType\t\tAvail Seats\tFare\n";
    cout << "--------------------------------------------\n";
    for(int i = 0; i < busCount; i++)
    {
        if(busStatus[i] == "Active")
        {
            cout << busNo[i] << "\t\t"
                 << busType[i] << "\t\t"
                 << (busSeats[i] - bookedSeats[i]) << "\t\t"
                 << "Rs" << busFare[i] << "\n";
            found = true;
        }
    }
    if(!found) cout << "No active buses available.\n";
    cin.ignore();
    cin.get();
}

void bookSeat()
{
    string search;
    cout << "Enter Bus Number: ";
    cin  >> search;

    for(int i = 0; i < busCount; i++)
    {
        if(busNo[i] == search)
        {
            // BUG-FIX: reject booking on Inactive buses
            if(busStatus[i] != "Active")
            {
                cout << "This bus is not active and cannot be booked!\n";
                sleep(2);
                return;
            }
            if(bookedSeats[i] < busSeats[i])
            {
                bookedSeats[i]++;
                if(loggedInPassenger != -1)
                {
                    passengerBookedBus[loggedInPassenger]   = i;
                    passengerBookedCount[loggedInPassenger]++;
                }
                cout << "Seat booked successfully!\n";
                cout << "Fare: Rs" << busFare[i] << " per seat\n";
                sleep(2);   // BUG-FIX: missing in original
            }
            else
            {
                cout << "No seats available!\n";
                cout.flush();
                sleep(2);
            }
            return;
        }
    }
    // BUG-FIX: no feedback when bus not found
    cout << "Bus not found!\n";
    sleep(2);
}

void cancelBooking()
{
    string search;
    cout << "Enter Bus Number: ";
    cin  >> search;

    for(int i = 0; i < busCount; i++)
    {
        if(busNo[i] == search)
        {
            if(bookedSeats[i] > 0)
            {
                bookedSeats[i]--;
                if(loggedInPassenger != -1 && passengerBookedCount[loggedInPassenger] > 0)
                    passengerBookedCount[loggedInPassenger]--;
                cout << "Booking cancelled!\n";
                sleep(2);
            }
            else
            {
                // BUG-FIX: original was silent here
                cout << "No bookings found for this bus!\n";
                sleep(2);
            }
            return;
        }
    }
    // BUG-FIX: original was silent when bus not found
    cout << "Bus not found!\n";
    sleep(2);
}

void viewBookings()
{
    bool found = false;
    cout << "Bus No\t\tType\t\tBooked Seats\n";
    cout << "--------------------------------------------\n";
    for(int i = 0; i < busCount; i++)
    {
        if(bookedSeats[i] > 0)
        {
            cout << busNo[i] << "\t\t"
                 << busType[i] << "\t\t"
                 << bookedSeats[i] << "\n";
            found = true;
        }
    }
    if(!found) cout << "No bookings found.\n";
    cin.ignore();
    cin.get();
}

// NEW Passenger: View my own profile and booking info
void viewMyProfile()
{
    system("clear"); header();
    cout << "--- MY PROFILE ---\n\n";

    if(loggedInPassenger == -1)
    {
        cout << "Error: No passenger logged in.\n";
        sleep(2);
        return;
    }

    cout << "Email    : " << passengerEmail[loggedInPassenger] << "\n";
    int bi = passengerBookedBus[loggedInPassenger];
    if(bi != -1 && bi < busCount && passengerBookedCount[loggedInPassenger] > 0)
    {
        cout << "Booked Bus   : " << busNo[bi] << "\n";
        cout << "Seats Booked : " << passengerBookedCount[loggedInPassenger] << "\n";
        cout << "Total Fare   : Rs" << (busFare[bi] * passengerBookedCount[loggedInPassenger]) << "\n";
    }
    else
    {
        cout << "No active bookings.\n";
    }

    cout << "\nPress Enter...";
    cin.ignore();
    cin.get();
}

// NEW Passenger: Change password
void changePassword()
{
    system("clear"); header();
    cout << "--- CHANGE PASSWORD ---\n\n";

    if(loggedInPassenger == -1)
    {
        cout << "Error: No passenger logged in.\n";
        sleep(2);
        return;
    }

    string oldPass, newPass;
    cout << "Enter Current Password: ";
    cin  >> oldPass;

    if(oldPass != passengerPassword[loggedInPassenger])
    {
        cout << "Incorrect current password!\n";
        sleep(2);
        return;
    }

    while(true)
    {
        cout << "Enter New Password: ";
        cin  >> newPass;

        if(!validPassword(newPass))
        {
            cout << "Password must contain at least one digit and one special character (@!#$&)!\n";
            continue;
        }
        if(newPass == oldPass)
        {
            cout << "New password must be different from the current one!\n";
            continue;
        }
        break;
    }

    passengerPassword[loggedInPassenger] = newPass;
    cout << "Password changed successfully!\n";
    sleep(2);
}

// NEW Passenger: Filter available buses by type
void viewSeatsByType()
{
    system("clear"); header();
    cout << "--- VIEW SEATS BY BUS TYPE ---\n\n";
    cout << "Enter Bus Type (e.g. AC / NonAC / Deluxe): ";
    string searchType;
    cin  >> searchType;

    bool found = false;
    cout << "\nBus No\t\tSeats\tAvailable\tFare\tStatus\n";
    cout << "----------------------------------------------------\n";
    for(int i = 0; i < busCount; i++)
    {
        if(busType[i] == searchType)
        {
            cout << busNo[i] << "\t\t"
                 << busSeats[i] << "\t"
                 << (busSeats[i] - bookedSeats[i]) << "\t\t"
                 << "Rs" << busFare[i] << "\t"
                 << busStatus[i] << "\n";
            found = true;
        }
    }
    if(!found) cout << "No buses found for type: " << searchType << "\n";

    cout << "\nPress Enter...";
    cin.ignore();
    cin.get();
}

void passengerMenu()
{
    char ch;
    while(true)
    {
        system("clear");
        header();
        cout << "--- PASSENGER MENU ---\n";
        cout << "1. View Available Buses\n";
        cout << "2. Search Bus\n";
        cout << "3. Book Seat\n";
        cout << "4. Cancel Booking\n";
        cout << "5. View Bookings\n";
        cout << "6. My Profile\n";          // NEW
        cout << "7. Change Password\n";     // NEW
        cout << "8. View Seats By Type\n";  // NEW
        cout << "9. Logout\n";
        cout << "Choice: ";
        cin  >> ch;

        if     (ch == '1') viewAvailableBuses();
        else if(ch == '2') searchBus();
        else if(ch == '3') bookSeat();
        else if(ch == '4') cancelBooking();
        else if(ch == '5') viewBookings();
        else if(ch == '6') viewMyProfile();
        else if(ch == '7') changePassword();
        else if(ch == '8') viewSeatsByType();
        else if(ch == '9') break;
    }
}

// ── Auth ─────────────────────────────────────────────────────────────────────

// BUG-FIX: now validates against adminEmail_const, not just any valid email format
void adminEmailid()
{
    string email;
    while(true)
    {
        cout << " --------  Login using your credentials   -------\n";
        cout << "Enter your email: ";
        cin  >> email;

        if(email == adminEmail_const)
        {
            cout << "Valid Email :";
            for(int i = 0; i < 3; i++) { cout << ")"; cout.flush(); usleep(500000); }
            cout << "\n";
            break;
        }
        else
        {
            cout << "Invalid Admin Email. Please try again";
            for(int i = 0; i < 3; i++) { cout << "."; cout.flush(); usleep(500000); }
            system("clear");
            header();
        }
    }
}

// BUG-FIX: now validates against adminPassword_const, not just any digit+special pattern
void adminPassword()
{
    string pass;
    while(true)
    {
        cout << " --------  Login using your credentials   -------\n";
        cout << "Enter password: ";
        cin  >> pass;

        if(pass == adminPassword_const)
        {
            cout << "Login Successful";
            for(int i = 0; i < 3; i++) { cout << "!"; cout.flush(); usleep(500000); }
            cout << "\n";
            break;
        }
        else
        {
            cout << "Invalid Password";
            for(int i = 0; i < 3; i++) { cout << "."; cout.flush(); usleep(500000); }
            system("clear");
            header();
        }
    }
}

bool validEmail(string email)
{
    bool hasAt = false, hasDot = false;

    if(email[0] == '@' || email[email.length()-1] == '.')
        return false;

    for(int i = 0; i < (int)email.length(); i++)
    {
        if(email[i] == '@') hasAt = true;
        if(email[i] == '.') hasDot = true;
    }

    return (hasAt && hasDot);
}

bool validPassword(string pass)
{
    bool hasDigit = false, hasSpecial = false;

    for(int i = 0; i < (int)pass.length(); i++)
    {
        if(pass[i] >= '0' && pass[i] <= '9') hasDigit = true;
        if(pass[i] == '@' || pass[i] == '!' || pass[i] == '#' ||
           pass[i] == '$' || pass[i] == '&') hasSpecial = true;
    }

    return (hasDigit && hasSpecial);
}

void passengerSignup()
{
    string email, pass;

    if(passengerCount >= MaxPassengers)
    {
        cout << "Passenger limit reached!\n";
        sleep(2);
        return;
    }

    while(true)
    {
        cout << "Enter Email: ";
        cin  >> email;

        if(!validEmail(email))
        {
            cout << "Invalid Email Format!\n";
            continue;
        }

        bool exists = false;
        for(int i = 0; i < passengerCount; i++)
        {
            if(passengerEmail[i] == email) { exists = true; break; }
        }

        if(exists) { cout << "Email already registered!\n"; continue; }

        break;
    }

    while(true)
    {
        cout << "Enter Password: ";
        cin  >> pass;

        if(!validPassword(pass))
        {
            cout << "Password must contain digit & special character (@!#$&)!\n";
            continue;
        }
        break;
    }

    passengerEmail[passengerCount]       = email;
    passengerPassword[passengerCount]    = pass;
    passengerBookedBus[passengerCount]   = -1;
    passengerBookedCount[passengerCount] = 0;
    passengerCount++;

    cout << "Signup Successful!\n";
    sleep(2);
}

bool passengerLogin()
{
    string email, pass;

    cout << "Enter Email: ";
    cin  >> email;
    cout << "Enter Password: ";
    cin  >> pass;

    for(int i = 0; i < passengerCount; i++)
    {
        if(passengerEmail[i] == email && passengerPassword[i] == pass)
        {
            loggedInPassenger = i;  // BUG-FIX: track logged-in passenger
            cout << "Login Successful!\n";
            sleep(1);
            return true;
        }
    }

    cout << "Invalid Email or Password!\n";
    sleep(2);
    return false;
}

bool managerLogin()
{
    string email, pass;
    int attempts = 3;

    while(attempts > 0)
    {
        cout << "Enter Manager Email: ";
        cin  >> email;

        if(!validEmail(email))
        {
            cout << "Invalid Email Format!\n";
            attempts--;
            continue;
        }

        cout << "Enter Password: ";
        cin  >> pass;

        if(email == managerEmail && pass == managerPassword)
        {
            cout << "Manager Login Successful!\n";
            sleep(1);
            return true;
        }
        else
        {
            cout << "Incorrect Email or Password!\n";
            attempts--;
            cout << "Attempts left: " << attempts << "\n";
        }
    }

    cout << "Too many failed attempts. Access denied!\n";
    sleep(2);
    return false;
}

// ── Header ────────────────────────────────────────────────────────────────────
void header()
{
    cout << "\033[1;36m";
    cout << "#####################################################################################################################################################################################\n";
    cout << "#                                                                                                                                                                                   #\n";
    cout << "\033[1;33m";
    cout << "#                                                                          BUS TICKETS MANAGEMENT SYSTEM                                                                            #\n";
    cout << "\033[1;36m";
    cout << "#                                                                                                                                                                                   #\n";
    cout << "#####################################################################################################################################################################################\n";
    cout << "\033[1;32m";
    cout << "#                                                                        FAST | EASY | SECURE BUS BOOKING                                                                           #\n";
    cout << "\033[1;36m";
    cout << "#####################################################################################################################################################################################\n";
    cout << "\033[0m";

    cout << "\033[1;36m\n\n";
    cout << "Loading Bus Tickets System";
    for(int i = 0; i < 3; i++) { cout << "."; cout.flush(); usleep(500000); }
    cout << "\n\033[1;32mSystem Ready!\n\033[0m\n\n";
}