#ifndef WITHDRAWALS_H
#define WITHDRAWALS_H

class Withdrawals : public Transactions {
private:

	// Amount withdrawed
	double amount;

	// Date of withdrawal
	Date date;

	// Description of the transaction
	std::string description;

public:

	void printAmount();
	void printDescription();
	void printDate();
}

#endif