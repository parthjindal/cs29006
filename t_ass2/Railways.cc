#include "Railways.h"

using namespace std;

vector<const Station> Railways::sStations = {Station("Mumbai"), Station("Delhi"),
                                             Station("Kolkata"), Station("Bangalore"), Station("Chennai")
                                            };
Railways::Railways() {
    sDistStations[ {"Mumbai", "Delhi"}] = 1447;
    sDistStations[ {"Delhi","Mumbai"} ] = 1447;
    
}

Railways::~Railways() {

}

int Railways::GetDistance(const Station &x, const Station &y) const
{
    return Railways::sDistStations.at({x.GetName(), y.GetName()});
}

const Railways &Railways::railways() {

    static const Railways indianRailways; //Local Static Singleton
    return indianRailways;
}