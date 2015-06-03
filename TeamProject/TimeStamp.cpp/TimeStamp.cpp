//TimeStamp.cpp
#include <ctime>
#include "TimeStamp.h"

TimeStamp::TimeStamp()//getting time from system
{
    now = time(0);
    dt = ctime(&now);
}

//Returns time with the fallowing format:
//Wed Jun 03 08:55:00 2015
char * TimeStamp::getTimeStamp() 
{
    return dt;
}
