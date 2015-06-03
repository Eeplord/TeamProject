//TimeStamp.h
#ifndef TimeStamp_H
#define TimeStamp_H
#include<ctime>

class TimeStamp
{
	private:
		time_t now;
		char* dt;
	public:
		TimeStamp();//sets current time
        char * getTimeStamp();//get current time
};
#endif // TimeStamp_H

