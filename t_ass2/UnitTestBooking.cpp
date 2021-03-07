/*
  *** Compilation: $ g++ -std=c++11 Station.cpp Railways.cpp Date.cpp \
                        BookingClasses.cpp Booking.cpp UnitTestBooking.cpp -o test5
*/

// **** Unit Test:Booking
// **** Author: Parth Jindal
// **** Date: 5 March 2021
// **** Roll no.: 19CS30033

/***************** Project Headers *******************************/
#include "Booking.h"

/***************** C++ Standard Library Headers *******************************/
#include <iostream>
#include <cassert>
#include <fstream>
#include <sstream>

using namespace std;

// **** static consts (must be initialized)
const double Booking::sBaseFarePerKM = 0.50;
const double Booking::sACSurcharge = 50.00;
const double Booking::sLuxuryTaxPercent = 0.25;

// **** static consts (must be initialized)
const double ACChairCar::sloadFactor = 1.25;
const double SecondSitting::sloadFactor = 0.5;
const double ACFirstClass::sloadFactor = 3.00;
const double AC2Tier::sloadFactor = 2.00;
const double FirstClass::sloadFactor = 2.00;
const double AC3Tier::sloadFactor = 1.75;
const double Sleeper::sloadFactor = 1.00;

void Booking::UnitTest()
{
    
    Booking b1(Station("Kolkata"), Station("Mumbai"), Date(17, 3, 2021), ACFirstClass::Type());
    Booking b2(Station("Kolkata"), Station("Mumbai"), Date(17, 3, 2021), ACChairCar::Type());
    Booking b3(Station("Kolkata"), Station("Mumbai"), Date(17, 3, 2021), SecondSitting::Type());
    Booking b4(Station("Kolkata"), Station("Mumbai"), Date(17, 3, 2021), AC2Tier::Type());
    Booking b5(Station("Kolkata"), Station("Mumbai"), Date(17, 3, 2021), FirstClass::Type());
    Booking b6(Station("Kolkata"), Station("Mumbai"), Date(17, 3, 2021), AC3Tier::Type());
    Booking b7(Station("Kolkata"), Station("Mumbai"), Date(17, 3, 2021), Sleeper::Type());

    // Booking b2(b1);
    vector<Booking*>::iterator it;

    it = find(sBookings.begin(),sBookings.end(),&b1);
    assert("Kolkata" == b1.fromStation_.GetName()); //Test fromStation()
    assert("Mumbai" == b1.toStation_.GetName());    //Test ToStation
    assert(Date(17,3,2021) == b1.date_);            //Test Date
    assert("AC First Class" == b1.bookingClass_.GetName()); //Test BookingClass
    assert(1 == b1.PNR_);                           //Test PNR(must start from 1)
    assert(3839 == b1.fare_ );                      
    assert(sBookings.end() != it);                  //Test if Booking is stored in sBookings or not


    //Test Compute Fare(acc.to business logic)
    assert(3839 == b1.ComputeFare());
    assert(1309 == b2.ComputeFare());
    assert(504 == b3.ComputeFare());
    assert(2064 == b4.ComputeFare());
    assert(2518 == b5.ComputeFare());
    assert(1812 == b6.ComputeFare());
    assert(1007 == b7.ComputeFare());
    
    // TEST GOLDEN OUTPUT
    ifstream log("logs/Booking.log");
    if (log){

        stringstream expectedOut, out;
        expectedOut << log.rdbuf();
        out << b1;
        assert(out.str() == expectedOut.str());
    }
    else{
        cout << "LogFile: Booking.log Not Found";
        exit(1);
    }
}

int main()
{
    Booking::UnitTest();
    return 0;
}
