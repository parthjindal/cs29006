// **** BookingClass class implementaion
// **** Author: Parth Jindal
// **** Date: 1 March 2021
// **** Roll no.: 19CS30033

/***************** Project Headers *******************************/
#include "BookingClasses.h"

using namespace std;

/******************** BOOKING CLASS *******************************/

// **** constructor
BookingClass::BookingClass(const string &name,
                           bool isAC, bool isLuxury) : name_(name),
                                                       isAC_(isAC), isLuxury_(isLuxury){}
// **** Destructor
BookingClass::~BookingClass() {}

// **** member functions
string BookingClass::GetName() const{ return name_;}
bool BookingClass::isAc() const{ return isAC_; }
bool BookingClass::isLuxury() const{ return isLuxury_; }

ostream &operator<<(ostream &os, const BookingClass &x){
    os << "Travel Class = " << x.GetName() << "\n";
    string _isSitting = x.isSitting() ? "Sitting" : "Sleeping";
    string _isAc = x.isAc() ? "AC" : "Non-AC";
    string _isLuxury = x.isLuxury() ? "Yes" : "No";
    os << " : Mode: " << _isSitting << "\n";
    os << " : Comfort: " << _isAc << "\n";
    os << " : Bunks: " << x.GetNumberOfTiers() << "\n";
    os << " : Luxury: " << _isLuxury;
    return os;
}

/********************** SEAT CLASS *****************************/

// **** constructor
Seat::Seat(const string &name, bool isAC,
           bool isLuxury) : BookingClass(name, isAC, isLuxury) {}

// **** destructor
Seat::~Seat() {}

// **** member functions
bool Seat::isSitting() const{ return true; }
int Seat::GetNumberOfTiers() const{ return 0; }

/********************** BERTH CLASS **************************/

// **** constructor
Berth::Berth(const string &name, bool isAC,
             bool isLuxury) : BookingClass(name, isAC, isLuxury) {}

// **** destructor
Berth::~Berth() {}

// **** member functions
bool Berth::isSitting() const{ return false; }

/********************* BERTH-2-TIER CLASS ******************/

// **** constructor
Berth2Tier::Berth2Tier(const string &name, bool isAC,
                       bool isLuxury) : Berth(name, isAC, isLuxury) {}
// *** destructor
Berth2Tier::~Berth2Tier() {}

// **** member functions
int Berth2Tier::GetNumberOfTiers() const { return 2; }

/********************* BERTH-3-TIER CLASS *****************/

// **** constructor
Berth3Tier::Berth3Tier(const string &name, bool isAC,
                       bool isLuxury) : Berth(name, isAC, isLuxury) {}
// **** destructor
Berth3Tier::~Berth3Tier() {}

// **** member functions
int Berth3Tier::GetNumberOfTiers() const { return 3; }

/********************* AC CHAIR CAR CLASS *****************/

// **** constructor
ACChairCar::ACChairCar(const string &name, bool isAC,
                       bool isLuxury) : Seat(name, isAC, isLuxury) {}
// **** destructor
ACChairCar::~ACChairCar() {}

// returns const instance(static)
const ACChairCar &ACChairCar::Type(){
    // _MEYER_SINGLETON
    const static ACChairCar obj("AC Chair Car", true, false); //local static instance
    return obj;
}

// **** member functions
double ACChairCar::GetLoadFactor() const { return sloadFactor; }

/********************* SECOND SITTING CLASS ***************/
// **** constructor
SecondSitting::SecondSitting(const string &name, bool isAC,
                             bool isLuxury) : Seat(name, isAC, isLuxury) {}
// **** destructor
SecondSitting::~SecondSitting() {}

// returns const instance(static)
const SecondSitting &SecondSitting::Type(){
    // _MEYER_SINGLETON
    const static SecondSitting obj("Second Sitting", false, false);
    return obj;
}

// returns loadFactor
double SecondSitting::GetLoadFactor() const { return sloadFactor; }

/********************* AC FIRST CLASS **************/
// **** constructor
ACFirstClass::ACFirstClass(const string &name, bool isAC,
                           bool isLuxury) : Berth2Tier(name, isAC, isLuxury) {}
// **** destructor
ACFirstClass::~ACFirstClass() {}

// returns const instance(static)
const ACFirstClass &ACFirstClass::Type(){
    // _MEYER_SINGLETON
    const static ACFirstClass obj("AC First Class", true, true);
    return obj;
}
// **** member function
double ACFirstClass::GetLoadFactor() const { return sloadFactor; }

/********************* AC 2 TIER CLASS **************/
// **** constructor
AC2Tier::AC2Tier(const string &name, bool isAC,
                 bool isLuxury) : Berth2Tier(name, isAC, isLuxury) {}
// **** destructor
AC2Tier::~AC2Tier() {}

// returns const instance(static)
const AC2Tier &AC2Tier::Type(){
    // _MEYER_SINGLETON
    const static AC2Tier obj("AC 2 Tier", true, false);
    return obj;
}
// **** member functions
double AC2Tier::GetLoadFactor() const { return sloadFactor; }

/********************* 'FIRST CLASS' CLASS **************/
// **** constructor
FirstClass::FirstClass(const string &name, bool isAC,
                       bool isLuxury) : Berth2Tier(name, isAC, isLuxury) {}
// **** destructor
FirstClass::~FirstClass() {}

// returns const instance(static)
const FirstClass &FirstClass::Type(){
    // _MEYER_SINGLETON
    const static FirstClass obj("First Class", false, true);
    return obj;
}
// **** member functions
double FirstClass::GetLoadFactor() const { return sloadFactor; }

/********************* AC 3 TIER CLASS **************/
// **** constructor
AC3Tier::AC3Tier(const string &name, bool isAC,
                 bool isLuxury) : Berth3Tier(name, isAC, isLuxury) {}
// **** destructor
AC3Tier::~AC3Tier() {}

// returns const instance(static)
const AC3Tier &AC3Tier::Type(){
    // _MEYER_SINGLETON
    const static AC3Tier obj("AC 3 Tier", true, false);
    return obj;
}
// **** member functions
double AC3Tier::GetLoadFactor() const { return sloadFactor; }

/********************* SLEEPER CLASS *****************/
// **** constructor
Sleeper::Sleeper(const string &name, bool isAC,
                 bool isLuxury) : Berth3Tier(name, isAC, isLuxury) {}
// **** destructor
Sleeper::~Sleeper() {}

//  returns const instance(static)
const Sleeper &Sleeper::Type(){
    // _MEYER_SINGLETON
    const static Sleeper obj("Sleeper", false, false);
    return obj;
}
// **** member functions
double Sleeper::GetLoadFactor() const { return sloadFactor; }
