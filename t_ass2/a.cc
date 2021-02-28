// #include "Railways.h"
// #include "Station.h"
#include "BookingClasses.h"
#include<iostream>
using namespace std;


int main(){
    const BookingClass& x = ACChairCar::Type();
    cout << x << endl;
}
