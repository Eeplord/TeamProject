#ifndef DEPOSIT
#define DEPOSIT

class Deposit : public Transaction
{
public:

	Deposit(Date* date, double amount, std::string description);
	~Deposit();
};

#endif DEPOSIT