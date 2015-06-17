#ifndef DEPOSIT
#define DEPOSIT

class Deposit : public Transaction
{
public:

	Deposit(Date* date, double amount, std::string description);
	~Deposit();
	std::string getEntry();
	void print();
};

#endif DEPOSIT