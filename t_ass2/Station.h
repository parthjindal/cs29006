#ifndef __STATION_H
#define __STATION_H

/************ C++ Headers ************************************/
#include <string>
#include<iostream>
using namespace std;

/************ CLASS Declaration ******************************/
class Station{

    const string name;        //name
public:
    Station(const string &); //ctor
    string GetName() const;
    int GetDistance(const Station &) const;
    friend ostream &operator<<(std::ostream &, const Station &);
    static void UnitTestStation();
};

#endif //__STATION_H