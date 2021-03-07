/*
  *** Compilation: g++ -std=c++11 UnitTestStation.cpp Station.cpp Railways.cpp -o test1
*/

// **** Unit Test:Station Class
// **** Author: Parth Jindal
// **** Date: 5 March 2021
// **** Roll no.: 19CS30033


/***************** Project Headers *******************************/
#include "Station.h"
#include "Railways.h"

/*****************C++ Standard Library Headers********************/
#include<iostream>
#include <sstream>
#include<cassert>

using namespace std;

void Station::UnitTest(){

    Station m("Mumbai");                             //ctor
    Station temp(m);                                 //cctor
    assert("Mumbai" == m.GetName());                 //Test GetName
    assert(1447 == m.GetDistance(Station("Delhi"))); //Test GetDistance

    stringstream out;
    out << m;
    string gOutput = "Station: Mumbai";
    assert(gOutput == out.str()); // Test operator<< with Golden output
}

int main(){
    Station::UnitTest();
}