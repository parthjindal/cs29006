#ifndef __RAILWAYS_H
#define __RAILWAYS_H

#include "Station.h"

/***************C++ Headers********************************/
#include<map>
#include<string>
#include<vector>
#include<iostream>


/****************CLASS Declaration*************************/
class Railways{

    static vector<string> sStations;
    static map<pair<string,string>,int> sDistStations;
    
    //CONSTRUCTORS
    // -----------
    Railways(); //private ctor
    Railways(const Railways&); //block cctor
    static Railways* instance;
public:
    ~Railways();
    const static Railways& railways(); 
    friend int Station::GetDistance(const Station&);
};


#endif //__RAILWATS_H