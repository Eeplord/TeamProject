//Date.cpp
#include<iostream>
#include "Date.h"

using namespace std;

Date::Date() //clears date for new date entry
{
	day_= 0;
	month_ = 0;
	year_ = 0;
}
//setDATE
void Date::setDate()
{
    cout << "Day: ";
    cin >> day_;
    cout << "Month: ";
    cin >> month_;
    cout << "Year: ";
    cin >> year_;
}

//getDATE
int Date::getDay()
{ return day_;}
int Date::getMonth()
{return month_;}
int Date::getYear()
{return year_;}
//printDate
void Date::printDate()
{
    cout << day_ << "/" << month_ << "/" << year_;
}
