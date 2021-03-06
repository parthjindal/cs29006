// ****** Station class definition
// ****** Author:Parth Jindal
// ****** Date: 1 March 2021
// ****** Version:1.0


#ifndef __STATION_H //Control inclusion of header files
#define __STATION_H

/************ C++ Headers ************************************/
#include <string>
#include<iostream>

/************ CLASS Declaration ******************************/
class Station{

    const std::string name;        //name
    // Station& operator=(const Station&); //block assignment operator

public:

    //CONSTRUCTOR
    //-----------
    Station(const std::string &); // ctor
    Station(const Station&); //cctor
    
    //DESTRUCTOR
    //----------
    ~Station(); //dtor

    //returns Station name
    std::string GetName() const; 

    //distance from another station
    int GetDistance(const Station &) const;
    
    friend std::ostream &operator<<(std::ostream &, const Station &);
    static void UnitTestStation(); //Unit test
};

#endif //__STATION_H