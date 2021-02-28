#ifndef __BOOKING_H
#define __BOOKING_H

#include "Station.h"
#include "BookingClasses.h"
#include "Date.h"
#include "Passenger.h"
#include <vector>
using namespace std;

class Booking
{

protected:
    const Station fromStation_;
    const Station toStation_;
    const BookingClass &bookingClass_;
    int PNR_;
    int fare_;
    Passenger *passenger_;
    bool bookingStatus_;
    string bookingMessage_;
    const Date date_;

    static double sBaseFarePerKM;

    static int sBookingPNRSerial;
    static double sACSurcharge;
    static double sLuxuryTaxPercent;

public:
    Booking(const Station, const Station, const Date &, const BookingClass &);
    virtual ~Booking();
    virtual int ComputeFare();
    static vector<Booking *> sBookings;
    friend ostream &operator<<(ostream &, const Booking &);
};

#endif