// ****** Station class definition
// ****** Author:Parth Jindal
// ****** Date: 1 March 2021
// ****** Version:1.0


#ifndef __STATION_H //Control inclusion of header files
#define __STATION_H

/************ C++ Project Headers ************************************/
#include <string>
#include<iostream>

/************ CLASS Declaration ******************************/
class Station{

    const std::string name_;        //name_
    Station& operator=(const Station&); //block assignment operator

public:

    //CONSTRUCTOR
    //-----------
    Station(const std::string &); // ctor
    Station(const Station&); //cctor
    
    //DESTRUCTOR
    //----------
    ~Station(); //dtor

    //returns name_
    std::string GetName() const; 

    //distance from another station
    int GetDistance(const Station &) const;
    friend std::ostream &operator<<(std::ostream &, const Station &);

    //UNIT TEST
    static void UnitTestStation();
};

#endif //__STATION_H