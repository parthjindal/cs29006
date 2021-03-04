#include "Date.h"
using namespace std;

Date::Date(unsigned int d, unsigned int m,
           unsigned int y) : date_(d), month_(Month(m)), year_(y) {}

Date::Date(const Date &d)
{
    date_ = d.date_;
    month_ = d.month_;
    year_ = d.year_;
}


const vector<const string> Date::months = {
    "Jan", "Feb", "Mar", "Apr",
    "May", "Jun", "Jul", "Aug", "Sep",
    "Oct", "Nov", "Dec"};

const vector<const string> Date::days = {
    "Monday","Tuesday","Wednesday",
    "Thursday","Friday","Saturday",
    "Sunday"
};

ostream &operator<<(ostream &os, const Date &date)
{
    os << date.date_ << "/" << Date::months[static_cast<int>(date.month_) - 1]
       << "/" << date.year_;
    return os;
}