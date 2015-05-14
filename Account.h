// Account.h
// Authors: Cameron March, Tuan Phan

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <cstring>
#include <stdexcept>

// Account simulates a person's bank account. It stores balance,
// interest rate, charges, and running counts of deposits and withdraws.
// Money can be withdrawn and deposited, and monthly interest can
// be applied.

class Account 
{
 public:
  
  // Constructor
  Account(double startingBalance, double annualInterestRate);

  Account(int id, std::string name, double startingBalance,
	double annualInterestRate, double nDeposits, double nWithdraws);

  // Getters
  double getBalance();
  int getNumDeposits();
  int getNumWithdraws();
  int getId();
  std::string getName();
  double getInterestRate();

  // Alter balance
  double deposit(double deposit); 
  double withdraw(double withdraw);

  // Calculates monthly interest and adds it to balance
  double calculateInterest();

 private:

  double balance_;
  double annualInterestRate_;
  double charges_;
  int nDeposits_;
  int nWithdraws_;
  int id_;
  std::string name_; 
};

#endif
