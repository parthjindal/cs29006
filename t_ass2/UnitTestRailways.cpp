/*
  *** Compilation: g++ -std=c++11 UnitTestRailways.cpp Station.cpp Railways.cpp -o test1
*/

// **** Unit Test:Railway Class
// **** Author: Parth Jindal
// **** Date: 5 March 2021
// **** Roll no.: 19CS30033

#include "Railways.h"
#include "Station.h"
#include<iostream>
#include<cassert>
#include<sstream>

using namespace std;


void Railways::UnitTest(){

    const Railways &obj = Railways::IndianRailways();
    assert(&obj == &Railways::IndianRailways()); //Singleton check

    // check Distance x----->y
    assert( 1447 == Railways::IndianRailways().GetDistance(Station("Mumbai"),Station("Delhi")));
    // check Distance y----->x
    assert( 1447 == Railways::IndianRailways().GetDistance(Station("Delhi"),Station("Mumbai")));
    
    stringstream out;
    out << obj;
    string gOutput = "Indian Railways:\n"
                     " Station: Mumbai\n"
                     " Station: Delhi\n"
                     " Station: Kolkata\n"
                     " Station: Bangalore\n"
                     " Station: Chennai\n";
                     
    assert(gOutput == out.str()); //Test ostream operator with Golden Output
}

int main(){
    Railways::UnitTest();
}
