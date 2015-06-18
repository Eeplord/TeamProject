#include "stdafx.h"
#include "Date.h"

Date::Date() //clears date for new date entry
{
	day_= 0;
	month_ = 0;
	year_ = 0;
}

Date::Date(int month, int day, int year)
: month_(month), day_(day), year_(year) {
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