// **** Railways class definition
// **** Author: Parth Jindal
// **** Date:3 March 2021
// **** Roll No.: 19CS30033

#ifndef __RAILWAYS_H //Control inclusion of header files
#define __RAILWAYS_H


/**************Project Headers*****************************/
#include "Station.h"

/***************C++ Project Headers********************************/
#include <map>	  	//hashmap
#include <string> 	
#include <vector>	
#include <utility>	//make_pair operation
#include <iostream> //basic i/o operation

/****************CLASS Declaration*************************/

//Singleton Class
//--------------
class Railways {

private:
	static std::vector<const Station> sStations;										 //list of stations
	static std::map<std::pair<const std::string, const std::string>, int> sDistStations; //distance between two stations
	void addDistances(const std::string &, const std::string &, int);					 //Utility function

	//CONSTRUCTORS
	// -----------
	Railways();                 //private ctor
	~Railways();				//private dtor
	Railways(const Railways &) = delete;//block cctor
	Railways& operator=(const Railways&) = delete; //block operator= 
 
public:
	//returns const instance of Railways
	static const Railways &IndianRailways(); 

	//returns distance between two stations
	int GetDistance(const Station &, const Station &) const;
	
	friend std::ostream& operator<<(std::ostream &,const Railways&);
	//UNIT TEST
	//---------
	static void UnitTest();
};

#endif //__RAILWAYS_H