#include "BookingClasses.h"

ostream &operator<<(ostream &os, const BookingClass &x)
{
    os << "Name: " << x.GetName() << "\n";
    os << "Load Factor: " << x.GetLoadFactor() << "\n";
    string _isSitting = x.isSitting() ? "Seat" : "Berth";
    string _isAc = x.isAc() ? "Yes" : "No";
    string _isLuxury = x.isLuxury() ? "Luxury" : "Ordinary";
    os << "Seat/Berth: " << _isSitting << "\n";
    os << "AC: " << _isAc << "\n";
    os << "Luxury/Ordinary: " << _isLuxury;
    return os;
}

bool Seat::isSitting() const { return true; }
bool Berth::isSitting() const { return false; }

int Berth2Tier::GetNumberOfTiers() const { return 2; }
int Berth3Tier::GetNumberOfTiers() const { return 3; }

ACChairCar *ACChairCar::sInstance = 0;
const double ACChairCar::sloadFactor_ = 1.25;

const ACChairCar &ACChairCar::Type()
{
    if (!sInstance)
        sInstance = new ACChairCar();
    return *sInstance;
}
double ACChairCar::GetLoadFactor() const { return sloadFactor_; }
string ACChairCar::GetName() const { return string("ACChairCar"); }
bool ACChairCar::isAc() const { return true; }
bool ACChairCar::isLuxury() const { return false; }
int ACChairCar::GetNumberOfTiers() const { return 0; }

SecondSitting *SecondSitting::sInstance = 0;
const double SecondSitting::sloadFactor_ = 0.5;

const SecondSitting &SecondSitting::Type()
{
    if (!sInstance)
        sInstance = new SecondSitting;
    return *sInstance;
}

double SecondSitting::GetLoadFactor() const { return sloadFactor_; }
string SecondSitting::GetName() const { return string("SecondSitting"); }
bool SecondSitting::isAc() const { return false; }
bool SecondSitting::isLuxury() const { return false; }
int SecondSitting::GetNumberOfTiers() const { return 0; }

ACFirstClass *ACFirstClass::sInstance = 0;
const double ACFirstClass::sloadFactor_ = 3.00;

const ACFirstClass &ACFirstClass::Type(){
    if (!sInstance)
        sInstance = new ACFirstClass;
    return *sInstance;
}

double ACFirstClass::GetLoadFactor() const { return sloadFactor_; }
string ACFirstClass::GetName() const { return string("ACFirstClass"); }
bool ACFirstClass::isAc() const { return true; }
bool ACFirstClass::isLuxury() const { return true; }

AC2Tier *AC2Tier::sInstance = 0;
const double AC2Tier::sloadFactor_ = 2.00;

const AC2Tier &AC2Tier::Type(){
    if (!sInstance)
        sInstance = new AC2Tier();
    return *sInstance;
}

double AC2Tier::GetLoadFactor() const { return sloadFactor_; }
string AC2Tier::GetName() const { return string("AC2Tier"); }
bool AC2Tier::isAc() const { return true; }
bool AC2Tier::isLuxury() const { return false; }

FirstClass *FirstClass::sInstance = 0;
const double FirstClass::sloadFactor_ = 2.00;

const FirstClass &FirstClass::Type(){
    if (!sInstance)
        sInstance = new FirstClass();
    return *sInstance;
}

double FirstClass::GetLoadFactor() const { return sloadFactor_; }
string FirstClass::GetName() const { return string("FirstClass"); }
bool FirstClass::isAc() const { return false; }
bool FirstClass::isLuxury() const { return true; }

AC3Tier *AC3Tier::sInstance = 0;
const double AC3Tier::sloadFactor_ = 1.75;

const AC3Tier &AC3Tier::Type(){
    if (!sInstance)
        sInstance = new AC3Tier();
    return *sInstance;
}

double AC3Tier::GetLoadFactor() const { return sloadFactor_; }
string AC3Tier::GetName() const { return string("AC3Tier"); }
bool AC3Tier::isAc() const { return false; }
bool AC3Tier::isLuxury() const { return false; }

Sleeper *Sleeper::sInstance = 0;
const double Sleeper::sloadFactor_ = 1.00;

const Sleeper &Sleeper::Type(){
    if (!sInstance)
        sInstance = new Sleeper();
    return *sInstance;
}

double Sleeper::GetLoadFactor() const { return sloadFactor_; }
string Sleeper::GetName() const { return string("Sleeper"); }
bool Sleeper::isAc() const { return false; }
bool Sleeper::isLuxury() const { return false; }
