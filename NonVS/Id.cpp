// Id.cpp

//#include "stdafx.h"
#include "Id.h"

Id::Id()
{
	id_ = 1000; //id's will start from 1000 to maintain 4 digit ID's
}

int Id::getId()
{
	id_ += 1;
	return id_;
}

void Id::setId(int id)
{
	id_ = id;
}