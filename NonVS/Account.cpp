// Account.cpp
// Authors: Cameron March, Tuan Phan

// Remove if not using Visual Studio
#include "stdafx.h"
#include "Account.h"

// Returns ID
int Account::getId()
{
	return id_;
}

// Return name
std::string Account::getName()
{
	return name_;
}

// Returns current balance
double Account::getBalance()
{
	return balance_;
}

// Returns interest rate
double Account::getInterestRate()
{
	return interestRate_;
}

// Applies monthly interest and returns balance
double Account::applyInterest()
{
	double monthlyInterestRate = interestRate_ / 12;
	double monthlyInterest = balance_ * monthlyInterestRate;
	balance_ += monthlyInterest;
	return balance_;
}

// Returns number of deposits made
int Account::getNumDeposits()
{
	return deposits_->size();
}

// Returns number of withdraws made
int Account::getNumWithdraws()
{
	return withdrawals_->size();
}

// Adds money to balance and returns current balance
double Account::deposit(double deposit)
{

	// Deposits has to be positive.
	if (deposit <= 0)
		throw std::invalid_argument("Deposit amount cannot be zero or negative.");

	balance_ += deposit;
	return balance_;
}

// Subtracts money from balance and returns current balance
double Account::withdraw(double withdraw) 
{
	// Withdraws must be less than amount available
	if (balance_ - withdraw < 0)
		throw std::invalid_argument("Withdraw amount cannot result in negative balance.");

	balance_ -= withdraw;
	return balance_;
}

void Account::save()
{
	std::ofstream ofile;
	ofile.open(id_)
}

void Account::load()
{

}