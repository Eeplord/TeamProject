// Transaction.h

#ifndef TRANSACTION_H
#define TRANSACTION_H

class Transaction
{
public:

	void printAmount();
	void printDescription();
	void printDate();
	std::string getEntry();

private:

	Date date_;
	double amount_;
	std::string description_;
};

#endif