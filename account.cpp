// account.cpp
// Author: Cameron March

#include "account.h"

// Constructor
account::account(double startingBalance, double interestRate) {
  balance = startingBalance;
  annualInterestRate = interestRate;
}

// Returns current balance
double account::getBalance() {
  return balance;
}

// Adds money to balance and returns current balance
double account::deposit(double money) {
  balance += money;
  deposits++;
  return balance;
}

// Subtracts money from balance and returns current balance
double account::withdraw(double money) {
  balance -= money;
  withdraws++;
  return balance;
}

// Applies monthly interest rate and returns current balance
double account::calcInterest() {
  double monthlyInterestRate = annualInterestRate / 12;
  double monthlyInterest = balance * monthlyInterestRate;
  balance += monthlyInterest;
  return balance;
}
