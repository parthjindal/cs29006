#include "Station.h"
#include "Railways.h"
#include<iostream>
#include <sstream>
#include<cassert>

using namespace std;

void Station::UnitTestStation(){
    
    Station m("Mumbai");

    assert("Mumbai" == m.GetName()); 
    assert(1447 == m.GetDistance(Station("Delhi")));

    stringstream out;
    out << m;
    string gOutput = "Station: Mumbai";
    assert(gOutput == out.str()); 
}

int main(){
    Station::UnitTestStation();
}