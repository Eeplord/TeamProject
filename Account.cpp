// Account.cpp
// Author: Cameron March

#include "Account.h"

// Constructor
// TODO: Default startingBalance, and annualInterestRate
Account::Account(double startingBalance, double annualInterestRate) {
  
  // Starting balance has to be positive.
  if (startingBalance < 0)
    throw invalid_argument("Starting balance cannot be negative.");

  balance_ = startingBalance;
  annualInterestRate_ = annualInterestRate;
  nDeposits_ = 0;
  nWithdraws_ = 0;
}

// Returns current balance
double Account::getBalance() {
  return balance_;
}

// Returns number of deposits made
int Account::getNumDeposits(){
  return nDeposits_;
}

// Returns number of withdraws made
int Account::getNumWithdraws(){
  return nWithdraws_;
}

// Adds money to balance and returns current balance
double Account::deposit(double deposit) {

  // Deposits has to be positive.
  if (deposit <= 0)
    throw invalid_argument("Deposit amount cannot be zero or negative.");

  balance_ += deposit;
  nDeposits_++;
  return balance_;
}

// Subtracts money from balance and returns current balance
double Account::withdraw(double withdraw) {

  // Withdraws must be less than amount available
  if (balance_ - withdraw < 0)
    throw invalid_argument("Withdraw amount cannot result in negative balance.");

  balance_ -= withdraw;
  nWithdraws_++;
  return balance_;
}

// Applies monthly interest rate and returns current balance
double Account::calculateInterest() {
  double monthlyInterestRate = annualInterestRate_ / 12;
  double monthlyInterest = balance_ * monthlyInterestRate;
  balance_ += monthlyInterest;
  return balance_;
}
