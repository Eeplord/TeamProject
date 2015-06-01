// Account.h
// Authors: Cameron March, Tuan Phan

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <stdexcept>
#include <stack>
#include <iostream>
#include <fstream>

// Account simulates a person's bank account. It stores balance,
// interest rate, charges, and running counts of deposits and withdraws.
// Money can be withdrawn and deposited, and monthly interest can
// be applied.
class Account {

public:

	// TODO: Constructors

	// Returns the id of the account
	int getId();

	// Returns the name of the owner
	std::string getName();

	// Returns the balance
	double getBalance();

	// Returns the interest rate
	double getInterestRate();

	// Returns new balance after interest
	double applyInterest();

	// Returns number of deposits
	int getNumDeposits();

	// Returns number of withdrawals
	int getNumWithdrawals();

	// Returns new balance after deposit
	double deposit(double amount);

	// Returns new balance after withdraw
	double withdraw(double amount);

	// Saves the account into an encrypted txt file
	void save();

	// Loads the account and decrypt
	void load();

private:

	Id id_;									// ID of the account
	std::string name_;						// Name of owner
	double balance_;						// Balance
	double interestRate_;					// Annual interest rate
	std::stack<Withdrawals> *withdrawals_; 	// Pointer to withdrawls
	std::stack<Deposits> *deposits_;		// Pointer to deposits
};

#endif