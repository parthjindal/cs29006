#include "Booking.h"

double Booking::sBaseFarePerKM = 0.50;
double Booking::sACSurcharge = 50.00;
double Booking::sLuxuryTaxPercent = 0.25;


int main(){

    Booking b1(Station("Mumbai"), Station("Delhi"), Date(15, 2, 2021), ACFirstClass::Type());
    Booking b2(Station("Mumbai"), Station("Delhi"), Date(16, 2, 2021), Sleeper::Type());
    Booking b3(Station("Mumbai"), Station("Delhi"), Date(1, 12, 2001), ACChairCar::Type());

    vector<Booking*>::iterator it;
    for(it = Booking::sBookings.begin(); it < Booking::sBookings.end();++it){
        cout << *(*it) <<"\n";
    }

}