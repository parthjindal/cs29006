// **** Station class implementation
// **** Author: Parth Jindal
// **** Date: 1 March 2021
// **** Roll no.: 19CS30033


/**************** Project Headers ********************/
#include "Station.h"
#include "Railways.h" //for accessing master data:distance

using namespace std;

// **** constructors
Station::Station(const string &x) : name_(x) {}
Station::Station(const Station&x) : name_(x.name_) {}

// **** destructor
Station::~Station(){}

string Station::GetName () const{ 
	return name_;
}

int Station::GetDistance(const Station& x) const{
    return Railways::IndianRailways().GetDistance(*this,x); //Railway Singleton.GetDistance 
}

ostream& operator<<(ostream& os,const Station& x){
    os <<"Station: " <<x.name_;
    return os;
}
