// **** Passenger class implementation
// **** Author: Parth Jindal
// **** Date: 3 March 2021
// **** Roll no.: 19CS30033

/****************Project Headers **************/
#include "Passenger.h"

using namespace std;


//CONSTRUCTOR
//-----------
Passenger::Passenger(const string &name, const string &aadhar, const Date &d,
                     const string &m) : name_(name), aadhar_(aadhar), dob_(d), mobile_(m) {}
//DESTRUCTOR
//----------
Passenger::~Passenger(){} 