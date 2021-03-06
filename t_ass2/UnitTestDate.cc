#include "Date.h"
#include <iostream>
#include <cassert>
#include <sstream>
using namespace std;

void Date::UnitTest(){

    Date d1(11, 03, 2001);
    Date d2(1,1);

    assert(11 == d.date_);
    assert(Date::Month::Mar == d.month_);
    assert(2001 == d.year_);
    assert(Date::Day::Sun == d.GetDay());
     
    stringstream out;
    out << d;
    assert("Sun, 11/Mar/2001" == out.str());
}

int main(){

    Date::UnitTest();
    return 0;
}