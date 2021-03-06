// **** Station class implementation
// **** Author: Parth Jindal
// **** Date: 1 March 2021
// **** Roll no.: 19CS30033


/**************** Project Headers ********************/
#include "Station.h"
#include "Railways.h"

using namespace std;

// **** constructors
Station::Station(const string &x) : name(x) {
    #if _DEBUG
        cout << "Station constructed\n"; 
    #endif
}
Station::Station(const Station&x) : name(x.name) {}

// **** destructor
Station::~Station(){
    #if _DEBUG
        cout << "Station destructed\n"; 
    #endif
}


string Station::GetName () const{ 
	return name;
}


int Station::GetDistance(const Station& x) const{
    return Railways::railways().GetDistance(*this,x); //Railway Singleton.GetDistance 
}

ostream& operator<<(ostream& os,const Station& x){
    os <<"Station: " <<x.name;
    return os;
}
