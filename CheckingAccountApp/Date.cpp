#include "stdafx.h"
#include "Date.h"

Date::Date() //clears date for new date entry
{
	day_= 0;
	month_ = 0;
	year_ = 0;
}

//setDATE
void Date::setDate()
{
  std::cout << "Day: ";
  std::cin >> day_;
  std::cout << "Month: ";
  std::cin >> month_;
  std::cout << "Year: ";
  std::cin >> year_;
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
  std::cout << day_ << "/" << month_ << "/" << year_;
}