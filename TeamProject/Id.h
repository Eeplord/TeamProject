#ifndef ID_H
#define ID_H

class Id {
private:

	// Generates an id for each new account
	static int idGenerator_ = 0;

	// The id of the account
	int id_;

public:

	// Set id_ = idGenerator++ everytime it's called
	Id();

	// Returns id_ of the account
	int getId();
}

#endif