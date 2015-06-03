//Id.cpp
//#include "stdafx.h"
#include "Id.h"

Id::Id()
{
    idGenerator_ = 1; //id will generate new id's by increments of 1
	id_ = 1000; //id's will start from 1000 to maintain 4 digit ID's
}

int Id::getId()
{
    id_ += idGenerator_;
	return id_;
}
