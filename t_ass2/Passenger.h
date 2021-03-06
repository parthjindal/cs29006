// **** Passenger class definition
// **** Author: Parth Jindal
// **** Date: 3 March 2021
// **** Roll no.: 19CS30033


#ifndef __PASSENGER_H //Control inclusion of header files
#define __PASSENGER_H

/************** Project Headers ***************/
#include "Date.h"

/************** C++ Project Headers *******************/
#include <string>

/*************** ABSTRACT CLASS ***************/
class Passenger{

protected:
    const std::string name_;
    const std::string aadhar_;   //aadhar
    const Date dob_;             //date-of-birth
    mutable std::string mobile_; //mutable for future

public:
    //CONSTRUCTOR
    //-----------
    Passenger(const std::string &, const std::string &,
              const Date &, const std::string &);

    //DESTRUCTOR
    //----------
    virtual ~Passenger() = 0; //pure virtual destructor
};

#endif // __PASSENGER_H