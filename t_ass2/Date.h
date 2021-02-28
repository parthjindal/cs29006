#ifndef __DATE_H
#define __DATE_H
#include <iostream>
#include<string>
#include<vector>

class Date{

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
    static std::vector<std::string> months;
    typedef unsigned int UINT;
    UINT date_;
    Month month_;
    UINT year_;

public:
    Date(UINT, UINT, UINT);
    Date(const Date&);
    Date &operator=(const Date &);
    ~Date(){};
    friend std::ostream &operator<<(std::ostream&,const Date&);
};

#endif // __DATE_H