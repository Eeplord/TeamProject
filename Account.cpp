// Account.cpp
// Author: Cameron March

#include "Account.h"

// Constructor
Account::Account(double startingBalance, double annualInterestRate) 
{
  balance_ = startingBalance;
  annualInterestRate_ = annualInterestRate;
}

// Returns current balance
double Account::getBalance() 
{
  return balance_;
}

// Adds money to balance and returns current balance
double Account::deposit(double deposit) 
{
  balance_ += deposit;
  nDeposits_++;
  return balance_;
}

// Subtracts money from balance and returns current balance
double Account::withdraw(double withdraw) 
{
  balance_ -= withdraw;
  nWithdraws_++;
  return balance_;
}

// Applies monthly interest rate and returns current balance
double Account::calculateInterest() 
{
  double monthlyInterestRate = annualInterestRate_ / 12;
  double monthlyInterest = balance_ * monthlyInterestRate;
  balance_ += monthlyInterest;
  return balance_;
}
