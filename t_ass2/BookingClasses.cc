#include "BookingClasses.h"
#include "ACChairCar.h"
#include "SecondSitting.h"

bool Seat::isSitting() const { return true; }
bool Berth::isSitting() const { return false; }

int Berth2Tier::GetNumberOfTiers() const { return 2; }
int Berth3Tier::GetNumberOfTiers() const { return 3; }


ACChairCar* ACChairCar::sInstance = 0;
const double ACChairCar::sloadFactor_ = 1.25;

const ACChairCar &ACChairCar::Type(){
    if (!sInstance)
        sInstance = new ACChairCar();
    return *sInstance;
}
double ACChairCar::GetLoadFactor() const { return sloadFactor_; }
string ACChairCar::GetName() const { return string("ACChairCar"); }
bool ACChairCar::isAc() const { return true; }
bool ACChairCar::isLuxury() const { return true; }
int ACChairCar::GetNumberOfTiers() const { return 0; }



SecondSitting* SecondSitting::sInstance = 0;
const double SecondSitting::sloadFactor_ = 0.5;

const SecondSitting &SecondSitting::Type(){
    if (!sInstance)
        sInstance = new SecondSitting;
    return *sInstance;
}

double SecondSitting::GetLoadFactor() const{ return sloadFactor_; }
string SecondSitting::GetName() const { return string("SecondSitting"); }
bool SecondSitting::isAc() const { return true; }
bool SecondSitting::isLuxury() const { return true; }
int SecondSitting::GetNumberOfTiers() const { return 0; }


ACFirstClass* ACFirstClass::sInstance = 0;
const double ACFirstClass::sloadFactor_ = 3.00;

double ACFirstClass::GetLoadFactor() const{ return sloadFactor_; }
string ACFirstClass::GetName() const { return string("SecondSitting"); }
bool SecondSitting::isAc() const { return true; }
bool SecondSitting::isLuxury() const { return true; }
int SecondSitting::GetNumberOfTiers() const { return 0; }


