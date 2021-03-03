#ifndef __RAILWAYS_H
#define __RAILWAYS_H

#include "Station.h"

/***************C++ Headers********************************/
#include <map>
#include <string>
#include <vector>
#include <iostream>

/****************CLASS Declaration*************************/
class Railways
{

    static std::vector<Station> sStations;
    static std::map<std::pair<std::string, std::string>, int> sDistStations;

    //CONSTRUCTORS
    // -----------
    Railways();                 //private ctor
    ~Railways();
    Railways(const Railways &); //block cctor

public:
    const static Railways &railways();
    int GetDistance(const Station &, const Station &) const;
};

#endif //__RAILWATS_H