// Account.cpp
// Authors: Cameron March, Tuan Phan

// Remove if not using Visual Studio
//#include "stdafx.h"
#include "Account.h"

// Constructor for creating a new account
Account::Account(int id, std::string name, double balance, double interestRate)
{
	id_ = id;
	name_ = name;
	balance_ = balance;
	interestRate_ = interestRate;
}

// Constructor used when the intention is to load a previous account
Account::Account(int id)
{
	id_ = id;
	name_ = "";
	balance_ = 0;
	interestRate_ = 0;
}

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
	//return deposits_->size();
	return 0;
}

// Returns number of withdraws made
int Account::getNumWithdrawals()
{
	//return withdrawals_->size();
	return 0;
}

// Adds money to balance and returns current balance
double Account::deposit(double deposit)
{

	// Deposits has to be positive.
	if (deposit <= 0)
	{
		throw std::invalid_argument("Deposit amount cannot be zero or negative.");
	}

	balance_ += deposit;
	return balance_;
}

// Subtracts money from balance and returns current balance
double Account::withdraw(double withdraw) 
{
	// Withdraws must be less than amount available
	if (balance_ < withdraw)
	{
		throw std::invalid_argument("Withdraw amount cannot result in negative balance.");
	}

	if (withdraw <= 0)
	{
		throw std::invalid_argument("Withdraw amount cannot be zero or negative.");
	}

	balance_ -= withdraw;
	return balance_;
}

void Account::save()
{
	std::string filepath = "account.txt";
	std::ofstream ofile(filepath.c_str());

	if(ofile.is_open())
	{
		ofile << id_ << std::endl;
		ofile << name_ << std::endl;
		ofile << balance_ << std::endl;
		ofile << interestRate_ << std::endl;

		ofile.close();
	}
}

void Account::load()
{
	std::string filepath = "account.txt";
	std::ifstream ifile(filepath.c_str());

	if(ifile.is_open())
	{
			ifile >> id_;
		ifile >> name_;
		ifile >> balance_;
		ifile >> interestRate_;

		ifile.close();
	}
}