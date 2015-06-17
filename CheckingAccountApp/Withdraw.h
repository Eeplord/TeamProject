#ifndef WITHDRAW
#define WITHDRAW

class Withdraw : public Transaction
{
public:

	Withdraw(Date* date, double amount, std::string description);
	~Withdraw();
};

#endif WITHDRAW