// **** TestApplication
// **** Author: Parth Jindal
// **** Date: 5 March 2021
// **** Roll no.: 19CS30033

/************************** Project Headers ******************************************/
#include "Station.h"
#include "Railways.h"
#include "Date.h"
#include "BookingClasses.h"
#include "Booking.h"
#include "Passenger.h"

/************************* C++ Standard Library Headers *****************************/
#include<iostream>

// **** static consts
const double Booking::sBaseFarePerKM = 0.5;
const double Booking::sACSurcharge = 50;
const double Booking::sLuxuryTaxPercent = 0.25;

// **** static consts
const double ACFirstClass::sloadFactor = 3.00;
const double AC2Tier::sloadFactor = 2.00;
const double FirstClass::sloadFactor = 2.00;
const double AC3Tier::sloadFactor = 1.75;
const double ACChairCar::sloadFactor = 1.25;
const double Sleeper::sloadFactor = 1.00;
const double SecondSitting::sloadFactor = 0.50;

using namespace std;

// Test application for booking
void BookingApplication()
{
    const Railways &obj = Railways::IndianRailways();

    vector<Station> fromVector, toVector;
    vector<int> Distances;

    Station m("Mumbai"), d("Delhi"), c("Chennai"), b("Bangalore"), k("Kolkata");
    Date d1(2, 11, 2011), d2(29, 3, 2002), d3(13, 4, 2022),
        d4(15, 4, 2019), d5(15, 8, 2021), d6(1, 8, 2010), d7(11, 03, 2001);

    fromVector.push_back(d);
    toVector.push_back(m);

    Distances.push_back(obj.GetDistance(fromVector.back(), toVector.back()));
    Booking b1(fromVector.back(), toVector.back(), d1 , ACFirstClass::Type());

    fromVector.push_back(b);
    toVector.push_back(c);

    Distances.push_back(obj.GetDistance(fromVector.back(), toVector.back()));
    Booking b2(fromVector.back(), toVector.back(), d2 , AC2Tier::Type());

    fromVector.push_back(k);
    toVector.push_back(m);

    Distances.push_back(obj.GetDistance(fromVector.back(), toVector.back()));
    Booking b3(fromVector.back(), toVector.back(), d3 , FirstClass::Type());

    fromVector.push_back(d);
    toVector.push_back(b);

    Distances.push_back(obj.GetDistance(fromVector.back(), toVector.back()));
    Booking b4(fromVector.back(), toVector.back(), d4 , AC3Tier::Type());

    fromVector.push_back(c);
    toVector.push_back(m);

    Distances.push_back(obj.GetDistance(fromVector.back(), toVector.back()));
    Booking b5(fromVector.back(), toVector.back(), d5, ACChairCar::Type());

    fromVector.push_back(c);
    toVector.push_back(d);


    Distances.push_back(obj.GetDistance(fromVector.back(), toVector.back()));
    Booking b6(fromVector.back(), toVector.back(), d6, Sleeper::Type());

    fromVector.push_back(b);
    toVector.push_back(k);

    Distances.push_back(obj.GetDistance(fromVector.back(), toVector.back()));
    Booking b7(fromVector.back(), toVector.back(), d7, SecondSitting::Type());

    fromVector.push_back(k);
    toVector.push_back(d);

    Distances.push_back(obj.GetDistance(fromVector.back(), toVector.back()));
    Booking b8(fromVector.back(), toVector.back(), d2, Sleeper::Type());

    fromVector.push_back(k);
    toVector.push_back(d);

    Distances.push_back(obj.GetDistance(fromVector.back(), toVector.back()));
    Booking b9(fromVector.back(), toVector.back(), d7, FirstClass::Type());

    fromVector.push_back(b);
    toVector.push_back(m);

    Distances.push_back(obj.GetDistance(fromVector.back(), toVector.back()));
    Booking b10(fromVector.back(), toVector.back(), d4 , ACFirstClass::Type());

    fromVector.push_back(b);
    toVector.push_back(c);

    Distances.push_back(obj.GetDistance(fromVector.back(), toVector.back()));
    Booking b11(fromVector.back(), toVector.back(), d6 , AC2Tier::Type());

    int n = (int)fromVector.size();
    int i;
    for (i = 0; i < n; i++){
        cout << "Booking - " << i + 1 << endl;
        cout << fromVector[i] << " ------> " << toVector[i] << " === " << Distances[i] << " km\n\n";
        cout << *(Booking::sBookings[i]) << endl 
            << endl;
    }
}

int main(){

    BookingApplication();
    return 0;
}