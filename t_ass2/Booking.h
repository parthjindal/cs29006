#ifndef __BOOKING_H
#define __BOOKING_H

#include "Station.h"
#include "BookingClasses.h"
#include "Date.h"
#include "Passenger.h"
#include <vector>

class Booking
{

protected:
    
    const Station fromStation_;
    const Station toStation_;
    const BookingClass &bookingClass_;
    const Date date_;
    const Passenger * const passenger_;
    const int PNR_;
    int fare_;
    bool bookingStatus_;
    std::string bookingMessage_;

    static int sBookingPNRSerial;

public:

    static double sBaseFarePerKM;
    static double sACSurcharge;
    static double sLuxuryTaxPercent;

    Booking(const Station&, const Station&, const Date &, const BookingClass &,const Passenger* const p);
    virtual ~Booking();
    virtual int ComputeFare();
    static std::vector<const Booking *> sBookings;
    friend std::ostream &operator<<(std::ostream &, const Booking &);
};

#endif