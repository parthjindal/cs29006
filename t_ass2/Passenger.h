// **** Passenger class definition
// **** Author: Parth Jindal
// **** Date: 3 March 2021
// **** Roll no.: 19CS30033


#ifndef __PASSENGER_H //Control inclusion of header files
#define __PASSENGER_H

/************** Project Headers ***************/
#include "Date.h"

/************** C++ Standard Library Headers *******************/
#include <string>

/*************** ABSTRACT CLASS ***************/
class Passenger{

protected:
    const std::string name_;
    const std::string aadhar_;   //aadhar
    const Date dob_;             //date-of-birth
    const std::string mobile_; //const for future

public:
    //CONSTRUCTOR
    //-----------
    Passenger(const std::string &, const std::string &,
              const Date &, const std::string &);

    //DESTRUCTOR
    //----------
    virtual ~Passenger(); //virtual destructor
    virtual string GetCategory() = 0; //pure virtual hierarchical method
    virtual string GetGender() = 0;
};

#endif // __PASSENGER_H