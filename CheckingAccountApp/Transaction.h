// Transaction.h

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include "Date.h"

class Transaction
{
public:

	Transaction(Date *date, double amount, std::string description);
	std::string getEntry();
	void print();

private:

	Date *date_;
	double amount_;
	std::string description_;
};

#endif