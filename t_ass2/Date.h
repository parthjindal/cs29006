// **** Date Class definition
// **** Author: Parth Jindal
// **** Date: 3 March 2021
// **** Roll No.: 19CS30033


#ifndef __DATE_H //Control inclusion of header files
#define __DATE_H

/************ C++ Project Headers ******************/
#include <ostream>
#include<string>
#include<vector>

class Date{
    
    // Month enums
    enum Month{
        Jan = 1,
        Feb,
        Mar,
        Apr,
        May,
        Jun,
        Jul,
        Aug,
        Sep,
        Oct,
        Nov,
        Dec
    };
    //Day enum
    enum Day{
        Sun = 0,
        Mon,
        Tue,
        Wed,
        Thur,
        Fri,
        Sat,
    };
    typedef unsigned int UINT;
    
    UINT date_; 
    Month month_;
    UINT year_;
    Day day_; 

    Date &operator=(const Date &); //block 'operator='

    Day GetDay(); //returns DOW
public:
    //CONSTRUCTOR
    //-----------
    Date(UINT, UINT, UINT); //ctor
    Date(const Date &);     //cctor

    //DESTRUCTOR
    //---------
    ~Date();

    //static constants
    //----------------
    static const std::vector<const std::string> sMonths; //Month Names
    static const std::vector<const std::string> sDays;   //Day Names

    bool operator==(const Date&);
    friend std::ostream &operator<<(std::ostream&,const Date&);

    //UNIT TEST
    //---------
    static void UnitTest();
};

#endif // __DATE_H