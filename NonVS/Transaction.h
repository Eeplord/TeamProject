#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

class Transactions {
private:
	double amount;
	Date date;
	std::string description;

public:
	void printAmount();
	void printDescription();
	void printDate();
}

#endif