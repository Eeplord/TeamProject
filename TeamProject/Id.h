// Id.h
#ifndef ID_H
#define ID_H

class Id
{
	private:
		int idGenerator_;
		int id_;

	public:
		Id(); //will generate 4 digit id's with increments of 1
        	int getId();
};
#endif // ID_H
