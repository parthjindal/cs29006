#include "Booking.h"
#include<math.h>

Booking::Booking(const Station x, const Station y,
                 const Date &d, const BookingClass &b) : fromStation_(x), toStation_(y),
                                                         date_(d), bookingClass_(b),passenger_(0)
{   
    fare_ = ComputeFare();

    sBookingPNRSerial += 1;
    PNR_ = sBookingPNRSerial;
    bookingStatus_ = true;
    bookingMessage_ = string("BOOKING SUCCEEDED");

    sBookings.push_back(this);
}

double Booking::sBaseFarePerKM = 0.50;
vector<Booking *> sBookings = {};
double Booking::sACSurcharge = 50.00;
double Booking::sLuxuryTaxPercent = 0.25;


int Booking::ComputeFare()
{
    double fare = sBaseFarePerKM *
                      (static_cast<double>(fromStation_.GetDistance(toStation_)));
    fare *= bookingClass_.GetLoadFactor();
    fare = bookingClass_.isAc() ? (fare+sACSurcharge) :fare;
    if(bookingClass_.isLuxury()){
        double luxuryTax = sLuxuryTaxPercent*fare;
        fare += luxuryTax;
    }
    return static_cast<int>(round(fare));

}

ostream& operator<<(ostream& os,const Booking& booking){
    os << booking.bookingMessage_ << ":\n";
    os << "PNR Number = " << booking.PNR_ << "\n";
    os << "From Station = "<< booking.fromStation_.GetName() <<"\n";
    os << "To Station = "<< booking.toStation_.GetName() <<"\n";
    os << "Travel Date = " << "-------\n";
    os << booking.bookingClass_ << "\n";
    os << "Fare = " << booking.fare_ ;
}