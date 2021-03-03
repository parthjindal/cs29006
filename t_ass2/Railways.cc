#include "Railways.h"

using namespace std;

vector<const Station> Railways::sStations = {Station("Mumbai"), Station("Delhi"),
                                             Station("Kolkata"), Station("Bangalore"), Station("Chennai")
                                            };
map<pair<const string,const string>,int> Railways::sDistStations;
Railways::Railways() {
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

void Railways::addDistances(const string&x, const string&y, int distance) {
    sDistStations[make_pair(x, y)] = distance;
    sDistStations[make_pair(y, x)] = distance;
}


int Railways::GetDistance(const Station &x, const Station &y) const
{
    return Railways::sDistStations.at({x.GetName(), y.GetName()});
}

const Railways &Railways::railways() {
    static const Railways indianRailways; //Local Static Singleton
    return indianRailways;
}