// **** Booking class definition
// **** Author: Parth Jindal
// **** Date: 3 March 2021
// **** Roll no.: 19CS30033

#ifndef __BOOKING_H //Control inclusion of header files
#define __BOOKING_H

/***************** Project Headers ****************/
#include "Station.h" 
#include "Railways.h"
#include "BookingClasses.h"
#include "Date.h"
#include "Passenger.h"

/***************** C++ Headers ********************/
#include <vector>
#include <ostream>

class Booking{

protected:
    const Station fromStation_;
    const Station toStation_;
    const BookingClass &bookingClass_; //static BookingClass obj
    const Date date_;                  //Date of booking
    const Passenger *const passenger_; //Set to default(for future)
    const int PNR_;
    int fare_;
    bool bookingStatus_; //set to true
    std::string bookingMessage_;
    static int sBookingPNRSerial; //total Booking count

    Booking(const Booking &);            //block cctor
    Booking &operator=(const Booking &); //block operator=

public:
    // **** static consts
    static const double sBaseFarePerKM; 
    static const double sACSurcharge;
    static const double sLuxuryTaxPercent;

    //CONSTRUCTOR
    //-----------
    Booking(const Station &, const Station &, const Date &, const BookingClass &,
            const Passenger *const p = NULL);

    //DESTRUCTOR
    //----------
    virtual ~Booking();

    virtual int ComputeFare();                     //virtual(future extension ?)
    static std::vector<const Booking *> sBookings; //Booking* array
    friend std::ostream &operator<<(std::ostream &, const Booking &);
    static void UnitTest();
};

#endif