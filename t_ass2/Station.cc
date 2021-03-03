#include "Station.h"
#include "Railways.h"

using namespace std;

//CONSTRUCTORS
//------------
Station::Station(const string &x) : name(x) {}
Station::Station(const Station&x) : name(x.name) {}

//DESTRUCTOR
//----------
Station::~Station(){}


string Station::GetName () const{ 
	return name; //Station name
}

int Station::GetDistance(const Station& x) const{
    return Railways::railways().GetDistance(*this,x); 
}

ostream& operator<<(ostream& os,const Station& x){
    os <<"Station:" <<x.name;
    return os;
}

void Station::UnitTestStation(){
    Station s1("Mumbai");
    Station s2 = s1;
    std::cout << s2;
}