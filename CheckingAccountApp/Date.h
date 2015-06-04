#ifndef DATE_H
#define DATE_H

class Date
{
private:
	int day_;
	int month_;
	int year_;

public:
	Date(); //constructor will clear date entries to enter a new date
	void setDate(); //gets date from user
	int getDay();
	int getMonth();
	int getYear();
	void printDate();
};

#endif // DATE_H