// **** Author:Parth Jindal
// **** Version:1.0
// **** Roll No.: 7/Mar/2021

/******************************* Project Headers**********************************/
#include "Booking.h"
#include "Station.h"
#include "Railways.h"
#include "Passenger.h"
#include "BookingClasses.h"
#include "Booking.h"

// **** static consts
const double Booking::sBaseFarePerKM = 0.50;
const double Booking::sACSurcharge = 50.00;
const double Booking::sLuxuryTaxPercent = 0.25;

const double ACChairCar::sloadFactor = 1.25;
const double SecondSitting::sloadFactor = 0.5;
const double ACFirstClass::sloadFactor = 3.00;
const double AC2Tier::sloadFactor = 2.00;
const double FirstClass::sloadFactor = 2.00;
const double AC3Tier::sloadFactor = 1.75;
const double Sleeper::sloadFactor = 1.00;

using namespace std;

void TestApplication(){

    Booking b1(Station("Mumbai"), Station("Delhi"), Date(15, 2, 2021), ACFirstClass::Type());
    Booking b2(Station("Kolkata"), Station("Delhi"), Date(5, 3, 2021), AC2Tier::Type());
    Booking b3(Station("Mumbai"), Station("Kolkata"), Date(17, 3, 2021), FirstClass::Type());
    Booking b4(Station("Mumbai"), Station("Delhi"), Date(23, 3, 2021), AC3Tier::Type());
    Booking b5(Station("Chennai"), Station("Delhi"), Date(25, 4, 2021), ACChairCar::Type());
    Booking b6(Station("Chennai"), Station("Kolkata"), Date(7, 5, 2021), Sleeper::Type());
    Booking b7(Station("Mumbai"), Station("Delhi"), Date(19, 5, 2021), SecondSitting::Type());
    Booking b8(Station("Delhi"), Station("Mumbai"), Date(22, 5, 2021), SecondSitting::Type());

    vector<Booking *>::iterator it;
    for (it = Booking::sBookings.begin(); it < Booking::sBookings.end(); ++it){
        cout << *(*it) << "\n\n";
    }
}

int main(){
    TestApplication();
}