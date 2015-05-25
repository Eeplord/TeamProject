// Account.h
// Authors: Cameron March, Tuan Phan

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <stdexcept>
#include <stack>

// Account simulates a person's bank account. It stores balance,
// interest rate, charges, and running counts of deposits and withdraws.
// Money can be withdrawn and deposited, and monthly interest can
// be applied.

class Account {
private:

	// Id of the account
	Id id_;

	// Name of owner
	std::string name_;

	// Balance
	double balance_;

	// Annual interest rate
	Interest annualInterestRate_;

	// Pointer to Withdrawals
	std::stack<Withdrawals> *withdrawals_;

	// Pointer to Deposits
	std::stack<Deposits> *deposits_;

	// Saves the account into an encrypted txt file
	void save();

	// Loads the account and decrypt
	void load();


public:

	// TODO: Constructors

	// Returns the id_ of the account
	int getId();

	// Returns the full name of the owner
	std::string getFullName();

	// Returns the first name of the owner
	std::string getFirstName();

	// Returns the last name of the owner
	std::string getFullName();

	// Returns the balance
	double getBalance();

	// Returns the yearly interest rate
	double getYearlyInterest();

	// Returns the monthly interest rate
	double getMonthlyInterest();

	// Returns new balance after yearly interest
	double applyYearlyInterest();

	// Returns new balance after monthly interest
	double applyMonthlyInterest();

	// Returns new balance after withdraw
	double withdraw(double amount);

	// Returns new balance after deposit
	double deposit(double amount);
}

#endif