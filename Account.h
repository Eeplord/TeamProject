// Account.h
// Author: Cameron March

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <cstring>
#include <fstream>

// Account simulates a person's bank account. It stores balance,
// interest rate, charges, and running counts of deposits and withdraws.
// Money can be withdrawn and deposited, and monthly interest can
// be applied.

class Account 
{
 public:
  
  // Constructor
  Account(double startingBalance, double annualInterestRate);

  // Getters
  double getBalance();
  int getNumDeposits();
  int getNumWithdraws();

  // Alter balance
  double deposit(double deposit); 
  double withdraw(double withdraw);

  // Calculates monthly interest and adds it to balance
  double calculateInterest();

  // Allowing for persistent data storage
  void saveToFile(std::string filename);
  void loadFromFile(std::string filename);

 private:

  double balance_;
  double annualInterestRate_;
  double charges_;
  int nDeposits_;
  int nWithdraws_;
};

#endif
