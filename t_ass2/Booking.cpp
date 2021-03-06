// **** Booking class Implementation
// **** Author: Parth Jindal
// **** Date: 3 March 2021
// **** Roll no.: 19CS30033

/************ Project Headers *************/
#include "Booking.h"

/************ C++ Project Headers *****************/
#include <math.h>

using namespace std;

Booking::Booking(const Station &x, const Station &y,
                 const Date &d, const BookingClass &b,const Passenger* const p) : fromStation_(x), toStation_(y),
                                                         date_(d), bookingClass_(b), passenger_(p),PNR_(sBookingPNRSerial)
{
    bookingStatus_ = true;
    bookingMessage_ = string("BOOKING SUCCEEDED");
    fare_ = ComputeFare();
    sBookingPNRSerial += 1;
    sBookings.push_back(this);

}
//DESTRUCTOR
//----------
Booking::~Booking() {}

// **** static consts
vector<const Booking *> Booking::sBookings;
int Booking::sBookingPNRSerial = 1;

int Booking::ComputeFare(){ 

    //Business logic
    double fare = sBaseFarePerKM *
                  (static_cast<double>(fromStation_.GetDistance(toStation_)));
    fare *= bookingClass_.GetLoadFactor();
    fare = bookingClass_.isAc() ? (fare + sACSurcharge) : fare;
    if (bookingClass_.isLuxury()){
        double luxuryTax = sLuxuryTaxPercent * fare;
        fare += luxuryTax;
    }
    return static_cast<int>(round(fare));
}

ostream &operator<<(ostream &os, const Booking &booking){
    
    os << booking.bookingMessage_ << ":\n";
    os << "PNR Number = " << booking.PNR_ << "\n";
    os << "From Station = " << booking.fromStation_.GetName() << "\n";
    os << "To Station = " << booking.toStation_.GetName() << "\n";
    os << "Travel Date = " << booking.date_ << "\n";
    os << booking.bookingClass_ << "\n";
    os << "Fare = " << booking.fare_;
    return os;
}
