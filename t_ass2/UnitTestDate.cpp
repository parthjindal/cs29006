/*
  *** Compilation: g++ -std=c++11 Date.cpp UnitTestDate.cpp -o test3
*/

// **** Unit Test:Date Class
// **** Author: Parth Jindal
// **** Date: 5 March 2021
// **** Roll no.: 19CS30033

/***************************** Project Headers *********************/
#include "Date.h"

/***************************** C++ Standard Library Headers ********/
#include <iostream>
#include <cassert>
#include <sstream>

using namespace std;

void Date::UnitTest(){

    Date d1(11, 03, 2001); //ctor
    Date d2(d1)            //cctor

    assert(d1 == d2) //Test operator==

    //Test Constructed object with given values
    assert(11 == d.date_);
    assert(Date::Month::Mar == d.month_);
    assert(2001 == d.year_);

    assert(Date::Day::Sun == d.GetDay()); //Test GetDay()
     
    stringstream out;
    out << d;
    assert("Sun, 11/Mar/2001" == out.str()); //Test operator<< with Golden Output
}

int main(){

    Date::UnitTest();
    return 0;
}