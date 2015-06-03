// Id.h

#ifndef ID_H
#define ID_H

class Id
{
public:

	// Constructor will generate unique 4 digit id
	Id();

	// Returns id
	int getId();

	void setId(int id);

private:

	int id_;
};

#endif