#ifndef TRANSACTION_H
#define TRANSACTION_H

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