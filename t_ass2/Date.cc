#include "Date.h"
using namespace std;

Date::Date(unsigned int d = 1, unsigned int m = 1,
           unsigned int y = 1970) : date_(d), month_(Month(m)), year_(y) {}
Date::Date(const Date &d)
{
    date_ = d.date_;
    month_ = d.month_;
    year_ = d.year_;
}

vector<string> Date::months = {
    "Jan", "Feb", "Mar", "Apr",
    "May", "Jun", "Jul", "Aug", "Sep",
    "Oct", "Nov", "Dec"};

ostream &operator<<(ostream &os, const Date &date)
{
    os << date.date_ << "/" << Date::months[static_cast<int>(date.month_) - 1]
       << "/" << date.year_;
    return os;
}