// **** Railways class implementation
// **** Author:Parth Jindal
// **** Date: 3 March 2021
// **** Roll No.: 19CS30033


/***************** Project Headers *******************/
#include "Railways.h"

using namespace std;

// **** static definitions
vector<const Station> Railways::sStations = {Station("Mumbai"), Station("Delhi"),
                                             Station("Kolkata"), Station("Bangalore"), Station("Chennai")};
map<pair<const string,const string>,int> Railways::sDistStations;

Railways::Railways() {

    // **** master data
    addDistances("Mumbai", "Delhi", 1447); 
    addDistances("Mumbai", "Bangalore", 981);
    addDistances("Mumbai", "Kolkata", 2014);
    addDistances("Mumbai", "Chennai", 1338);
    addDistances("Delhi", "Kolkata", 1472);
    addDistances("Delhi", "Chennai", 2180);
    addDistances("Delhi", "Bangalore", 2150);
    addDistances("Bangalore", "Kolkata", 1871);
    addDistances("Bangalore", "Chennai", 350);
    addDistances("Kolkata", "Chennai", 1659);


    #if _DEBUG
        cout << "Railways Created\n";
    #endif // _DEBUG
}

Railways::~Railways() {
    #if _DEBUG
        cout << "Railways Destroyed\n";
    #endif // _DEBUG
}

//Utility function
void Railways::addDistances(const string&x, const string&y, int distance) {
    sDistStations[make_pair(x, y)] = distance; // x -----> y :distance
    sDistStations[make_pair(y, x)] = distance; // y -----> x :distance
}

//distance b/w two stations
int Railways::GetDistance(const Station &x, const Station &y) const{
    return Railways::sDistStations.at(make_pair(x.GetName(), y.GetName())); 
}

//returns const instance of railways(Singleton)
const Railways &Railways::IndianRailways() {
    static const Railways indianRailways; //Local Static Singleton
    return indianRailways;
}

ostream& operator<<(ostream& os,const Railways& railway){
    vector<const Station>::const_iterator it;
    os << "Indian Railways:\n";
    for(it = railway.sStations.begin();it != railway.sStations.end();++it){
        os << " "<< *it << "\n";
    }
    return os;
}