#include "Railways.h"
#include "Station.h"
#include<iostream>
#include<cassert>
#include<sstream>

using namespace std;


void Railways::UnitTest(){

    const Railways &obj = Railways::railways();
    assert(&obj == &Railways::railways());
    assert( 1447 == Railways::railways().GetDistance(Station("Mumbai"),Station("Delhi")));

    stringstream out;
    out << obj;
    string gOutput = "Indian Railways:\n"
                     " Station: Mumbai\n"
                     " Station: Delhi\n"
                     " Station: Kolkata\n"
                     " Station: Bangalore\n"
                     " Station: Chennai\n";
                     
    assert(gOutput == out.str());
}

int main(){
    Railways::UnitTest();
}
