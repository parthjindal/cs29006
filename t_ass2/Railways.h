// **** Railways class definition
// **** Author: Parth Jindal
// **** Date:3 March 2021
// **** Roll No.: 19CS30033

#ifndef __RAILWAYS_H //Control inclusion of header files
#define __RAILWAYS_H


/**************Project Headers*****************************/
#include "Station.h"

/***************C++ Headers********************************/
#include <map>
#include <string>
#include <vector>
#include <utility>
#include <iostream>

/****************CLASS Declaration*************************/

//Singleton Class
//--------------
class Railways {

	static std::vector<const Station> sStations;										 //list of stations
	static std::map<std::pair<const std::string, const std::string>, int> sDistStations; //distance between two stations
	void addDistances(const std::string &, const std::string &, int);					 //Utility function

	//CONSTRUCTORS
	// -----------
	Railways();                 //private ctor
	~Railways();				//private dtor
	Railways(const Railways &); //block cctor

public:
	//returns const instance of Railways
	static const Railways &railways(); 

	//returns distance between two stations
	int GetDistance(const Station &, const Station &) const;
	friend std::ostream& operator<<(std::ostream &,const Railways&);
	static void UnitTest();
};

#endif //__RAILWATS_H