#include "Date.h"
#include<ctime>
using namespace std;

Date::Date(unsigned int d, unsigned int m,
           unsigned int y) : date_(d), month_(Month(m)), year_(y)
{
    day_ = GetDay();
}

Date::Date(const Date &d)
{
    date_ = d.date_;
    month_ = d.month_;
    year_ = d.year_;
    day_ = d.day_;
}

Date::Day Date::GetDay(){
    
    struct tm curr_date = {0, 0, 0, static_cast<int>(date_),
                           static_cast<int>(month_) - 1, static_cast<int>(year_) - 1900};

    time_t rawtime = mktime(&curr_date);
    return static_cast<Date::Day>(localtime(&rawtime)->tm_wday);
}

const vector<const string> Date::sMonths = {
    "Jan", "Feb", "Mar", "Apr",
    "May", "Jun", "Jul", "Aug", "Sep",
    "Oct", "Nov", "Dec"};

const vector<const string> Date::sDays = {"Mon", "Tue", "Wed",
                                          "Thur", "Fri", "Sat","Sun"};

ostream &operator<<(ostream &os, const Date &date)
{   
    os << Date::sDays[static_cast<int>(date.day_)-1] << ", "<< date.date_ << "/" << Date::sMonths[static_cast<int>(date.month_) - 1]
       << "/" << date.year_;
    return os;
}