#include "Railways.h"

Railways* Railways::instance = 0;
vector<string> Railways::sStations = {"Mumbai","Delhi","Kolkata","Bangalore"};
map<pair<string,string>,int> Railways::sDistStations  = {   };


Railways::Railways(){

}

const Railways& Railways::railways(){
    if(instance == 0){
        instance = new Railways();
    }
    return *instance;
}