#ifndef DEPOSITS_H
#define DEPOSITS_H

class Deposits : public Transactions {
private:

	// Amount deposited
	double amount;

	// Date of deposit
	Date date;

	// Description of the transaction
	std::string description;

public:

	void printAmount();
	void printDescription();
	void printDate();
}

#endif