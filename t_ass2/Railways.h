#ifndef __RAILWAYS_H //Control inclusion of header files
#define __RAILWAYS_H

#include "Station.h"

/***************C++ Headers********************************/
#include <map>
#include <string>
#include <vector>
#include <utility>
#include <iostream>

/****************CLASS Declaration*************************/
class Railways {

	static std::vector<const Station> sStations;
	static std::map<std::pair<const std::string, const std::string>, int> sDistStations;
	void addDistances(const std::string&, const std::string&, int);

	//CONSTRUCTORS
	// -----------
	Railways();                 //private ctor
	~Railways();
	Railways(const Railways &); //block cctor

public:
	const static Railways &railways();
	int GetDistance(const Station &, const Station &) const;
};

#endif //__RAILWATS_H