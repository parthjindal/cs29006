#include "BookingClasses.h"

ostream &operator<<(ostream &os, const BookingClass &x)
{
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

bool Seat::isSitting() const { return true; }
int Seat::GetNumberOfTiers() const { return 0; }

bool Berth::isSitting() const { return false; }

int Berth2Tier::GetNumberOfTiers() const { return 2; }
int Berth3Tier::GetNumberOfTiers() const { return 3; }

ACChairCar *ACChairCar::sInstance = 0;
const double ACChairCar::sloadFactor = 1.25;

ACChairCar::~ACChairCar() {}
ACChairCar::ACChairCar() {}

const ACChairCar &ACChairCar::Type()
{
    if (!sInstance)
        sInstance = new ACChairCar();
    return *sInstance;
}
double ACChairCar::GetLoadFactor() const { return sloadFactor; }
string ACChairCar::GetName() const { return string("ACChairCar"); }
bool ACChairCar::isAc() const { return true; }
bool ACChairCar::isLuxury() const { return false; }

SecondSitting *SecondSitting::sInstance = 0;
const double SecondSitting::sloadFactor = 0.5;

SecondSitting::~SecondSitting() {}
SecondSitting::SecondSitting() {}
const SecondSitting &SecondSitting::Type()
{
    if (!sInstance)
        sInstance = new SecondSitting;
    return *sInstance;
}

double SecondSitting::GetLoadFactor() const { return sloadFactor; }
string SecondSitting::GetName() const { return string("SecondSitting"); }
bool SecondSitting::isAc() const { return false; }
bool SecondSitting::isLuxury() const { return false; }

ACFirstClass *ACFirstClass::sInstance = 0;
const double ACFirstClass::sloadFactor = 3.00;

ACFirstClass::~ACFirstClass() {}
ACFirstClass::ACFirstClass() {}

const ACFirstClass &ACFirstClass::Type()
{
    if (!sInstance)
        sInstance = new ACFirstClass;
    return *sInstance;
}

double ACFirstClass::GetLoadFactor() const { return sloadFactor; }
string ACFirstClass::GetName() const { return string("ACFirstClass"); }
bool ACFirstClass::isAc() const { return true; }
bool ACFirstClass::isLuxury() const { return true; }

AC2Tier *AC2Tier::sInstance = 0;
const double AC2Tier::sloadFactor = 2.00;

AC2Tier::~AC2Tier() {}
AC2Tier::AC2Tier() {}

const AC2Tier &AC2Tier::Type()
{
    if (!sInstance)
        sInstance = new AC2Tier;
    return *sInstance;
}

double AC2Tier::GetLoadFactor() const { return sloadFactor; }
string AC2Tier::GetName() const { return string("AC2Tier"); }
bool AC2Tier::isAc() const { return true; }
bool AC2Tier::isLuxury() const { return false; }

FirstClass *FirstClass::sInstance = 0;
const double FirstClass::sloadFactor = 2.00;

FirstClass::~FirstClass() {}
FirstClass::FirstClass() {}

const FirstClass &FirstClass::Type()
{
    if (!sInstance)
        sInstance = new FirstClass;
    return *sInstance;
}

double FirstClass::GetLoadFactor() const { return sloadFactor; }
string FirstClass::GetName() const { return string("FirstClass"); }
bool FirstClass::isAc() const { return false; }
bool FirstClass::isLuxury() const { return true; }

AC3Tier *AC3Tier::sInstance = 0;
const double AC3Tier::sloadFactor = 1.75;

AC3Tier::AC3Tier() {}
AC3Tier::~AC3Tier() {}

const AC3Tier &AC3Tier::Type()
{
    if (!sInstance)
        sInstance = new AC3Tier;
    return *sInstance;
}

double AC3Tier::GetLoadFactor() const { return sloadFactor; }
string AC3Tier::GetName() const { return string("AC3Tier"); }
bool AC3Tier::isAc() const { return false; }
bool AC3Tier::isLuxury() const { return false; }

Sleeper *Sleeper::sInstance = 0;
const double Sleeper::sloadFactor = 1.00;

Sleeper::Sleeper() {}
Sleeper::~Sleeper() {}

const Sleeper &Sleeper::Type()
{
    if (!sInstance)
        sInstance = new Sleeper;
    return *sInstance;
}

double Sleeper::GetLoadFactor() const { return sloadFactor; }
string Sleeper::GetName() const { return string("Sleeper"); }
bool Sleeper::isAc() const { return false; }
bool Sleeper::isLuxury() const { return false; }
