#include <iostream>
#include <cassert>
#include "Booking.h"
using namespace std;

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

void Booking::UnitTest()
{
    Booking b1(Station("Delhi"), Station("Bangalore"), Date(17, 3, 2021),ACChairCar::Type());
    
    assert(Station("Delhi") == b1.fromStation_);
    assert(Station("Bangalore") == b1.toStation_);
    

    Booking b2(Station("Kolkata"), Station("Mumbai"), Date(17, 3, 2021), Berth_1A::Type(), NULL);
    assert("Kolkata"==b2.fromStation_.GetName() && "Mumbai"==b2.toStation_.GetName() && "AC First Class"==b2.bookingClass_.GetName()
           && NULL==b2.passenger_ && true==b2.bookingStatus_ && "BOOKING SUCCEEDED"==b2.bookingMessage_);

    Booking b3(Station("Kolkata"), Station("Mumbai"), Date(17, 3, 2021), Berth_1A::Type(), NULL, true);
    assert("Kolkata"==b3.fromStation_.GetName() && "Mumbai"==b3.toStation_.GetName() && "AC First Class"==b3.bookingClass_.GetName()
           && NULL==b3.passenger_ && true==b3.bookingStatus_ && "BOOKING SUCCEEDED"==b3.bookingMessage_);
    
    Booking b4(Station("Kolkata"), Station("Mumbai"), Date(17, 3, 2021), Berth_1A::Type(), NULL, true, "BOOKING SUCCEEDED");
    assert("Kolkata"==b4.fromStation_.GetName() && "Mumbai"==b4.toStation_.GetName() && "AC First Class"==b4.bookingClass_.GetName()
           && NULL==b4.passenger_ && true==b4.bookingStatus_ && "BOOKING SUCCEEDED"==b4.bookingMessage_);
    
    Booking b5(Station("Kolkata"), Station("Mumbai"), Date(17, 3, 2021), Berth_1A::Type());
    assert(3839==b5.fare_);

    Booking b6(Station("Kolkata"), Station("Mumbai"), Date(17, 3, 2021), Berth_2A::Type());
    assert(2064==b6.fare_);

    Booking b7(Station("Kolkata"), Station("Mumbai"), Date(17, 3, 2021), Berth_FC::Type());
    assert(2518==b7.fare_);

    Booking b8(Station("Kolkata"), Station("Mumbai"), Date(17, 3, 2021), Berth_3A::Type());
    assert(1812==b8.fare_);

    Booking b9(Station("Kolkata"), Station("Mumbai"), Date(17, 3, 2021), Seat_CC::Type());
    assert(1309==b9.fare_);

    Booking b10(Station("Kolkata"), Station("Mumbai"), Date(17, 3, 2021), Berth_SL::Type());
    assert(1007==b10.fare_);

    Booking b11(Station("Kolkata"), Station("Mumbai"), Date(17, 3, 2021), Seat_2S::Type());
    assert(504==b11.fare_);    
}

int main()
{
    Booking::UnitTest();
    return 0;
}
