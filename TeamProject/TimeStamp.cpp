//TimeStamp.cpp
#include <ctime>
#include "TimeStamp.h"

TimeStamp::TimeStamp()
{
    now = time(0);
    dt = ctime(&now);
}

char * TimeStamp::getTimeStamp()
{
    return dt;
}
