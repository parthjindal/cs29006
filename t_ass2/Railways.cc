#include "Railways.h"

Railways* Railways::instance = 0;
vector<Station> Railways::sStations = {Station("Mumbai"),Station("Delhi"),Station("Kolkata"),Station("Bangalore")};
map<pair<string,string>,int> Railways::sDistStations  = {   };


Railways::Railways(){}
int Railways::GetDistance(const Station&x,const Station&y) const {
    return Railways::sDistStations.at({x.GetName(),y.GetName()});
}

const Railways& Railways::railways(){
    if(instance == 0){
        instance = new Railways();
    }
    return *instance;
}