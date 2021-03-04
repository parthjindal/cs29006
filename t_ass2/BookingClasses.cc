#include "BookingClasses.h"

using namespace std;

BookingClass::BookingClass(const string &name,
                           bool isAC, bool isLuxury) : name_(name),
                                                       isAC_(isAC), isLuxury_(isLuxury){}
BookingClass::~BookingClass() {}

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

/********************** SEAT CLASS DEFINITION*********************/

Seat::Seat(const string &name, bool isAC,
           bool isLuxury) : BookingClass(name, isAC, isLuxury) {}

Seat::~Seat() {}
bool Seat::isSitting() const{
    return true;
}

int Seat::GetNumberOfTiers() const{
    return 0;
}

Berth::Berth(const string &name, bool isAC, bool isLuxury) : BookingClass(name, isAC, isLuxury) {}
Berth::~Berth() {}

bool Berth::isSitting() const{
    return false;
}

Berth2Tier::Berth2Tier(const string &name, bool isAC, bool isLuxury) : Berth(name, isAC, isLuxury) {}
Berth2Tier::~Berth2Tier() {}

int Berth2Tier::GetNumberOfTiers() const { return 2; }

Berth3Tier::Berth3Tier(const string &name, bool isAC, bool isLuxury) : Berth(name, isAC, isLuxury) {}
Berth3Tier::~Berth3Tier() {}
int Berth3Tier::GetNumberOfTiers() const { return 3; }

ACChairCar::ACChairCar(const string &name, bool isAC, bool isLuxury) : Seat(name, isAC, isLuxury) {}
ACChairCar::~ACChairCar() {}

const ACChairCar &ACChairCar::Type()
{
    const static ACChairCar obj("AC Chair Car", true, false);
    return obj;
}

double ACChairCar::GetLoadFactor() const { return sloadFactor; }

SecondSitting::SecondSitting(const string &name, bool isAC, bool isLuxury) : Seat(name, isAC, isLuxury) {}
SecondSitting::~SecondSitting() {}

const SecondSitting &SecondSitting::Type()
{
    const static SecondSitting obj("Second Sitting", false, false);
    return obj;
}

double SecondSitting::GetLoadFactor() const { return sloadFactor; }

ACFirstClass::ACFirstClass(const string &name, bool isAC, bool isLuxury) : Berth2Tier(name, isAC, isLuxury) {}
ACFirstClass::~ACFirstClass() {}

const ACFirstClass &ACFirstClass::Type()
{
    const static ACFirstClass obj("AC First Class", true, true);
    return obj;
}

double ACFirstClass::GetLoadFactor() const { return sloadFactor; }

AC2Tier::AC2Tier(const string &name, bool isAC, bool isLuxury) : Berth2Tier(name, isAC, isLuxury) {}
AC2Tier::~AC2Tier() {}

const AC2Tier &AC2Tier::Type()
{
    const static AC2Tier obj("AC 2 Tier", true, false);
    return obj;
}

double AC2Tier::GetLoadFactor() const { return sloadFactor; }

FirstClass::FirstClass(const string &name, bool isAC, bool isLuxury) : Berth2Tier(name, isAC, isLuxury) {}
FirstClass::~FirstClass() {}

const FirstClass &FirstClass::Type()
{
    const static FirstClass obj("First Class", false, false);
    return obj;
}
double FirstClass::GetLoadFactor() const { return sloadFactor; }

AC3Tier::AC3Tier(const string &name, bool isAC, bool isLuxury) : Berth3Tier(name, isAC, isLuxury) {}
AC3Tier::~AC3Tier() {}

const AC3Tier &AC3Tier::Type()
{
    const static AC3Tier obj("AC 3 Tier", true, false);
    return obj;
}

double AC3Tier::GetLoadFactor() const { return sloadFactor; }

Sleeper::Sleeper(const string &name, bool isAC, bool isLuxury) : Berth3Tier(name, isAC, isLuxury) {}
Sleeper::~Sleeper() {}

const Sleeper &Sleeper::Type()
{
    const static Sleeper obj("Sleeper", false, false);
    return obj;
}

double Sleeper::GetLoadFactor() const { return sloadFactor; }
