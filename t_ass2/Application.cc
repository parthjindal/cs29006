#include "Booking.h"

double Booking::sBaseFarePerKM = 0.50;
double Booking::sACSurcharge = 50.00;
double Booking::sLuxuryTaxPercent = 0.25;

const double ACChairCar::sloadFactor = 1.25;
const double SecondSitting::sloadFactor = 0.5;
const double ACFirstClass::sloadFactor = 3.00;
const double AC2Tier::sloadFactor = 2.00;
const double FirstClass::sloadFactor = 2.00;
const double AC3Tier::sloadFactor = 1.75;
const double Sleeper::sloadFactor = 1.00;

using namespace std;

int main(){
    
    Booking b1(Station("Mumbai"), Station("Delhi"), Date(15, 2, 2021), ACFirstClass::Type());
    Booking b2(Station("Mumbai"), Station("Delhi"), Date(16, 2, 2021), Sleeper::Type());
    Booking b3(Station("Mumbai"), Station("Delhi"), Date(1, 12, 2001), ACChairCar::Type());

    vector<const Booking*>::const_iterator it;
    for(it = Booking::sBookings.begin(); it < Booking::sBookings.end();++it){
        cout << *(*it) <<"\n";
    }

}