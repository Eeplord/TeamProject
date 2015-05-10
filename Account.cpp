// Account.cpp
// Author: Cameron March

#include "Account.h"

// Constructor
Account::Account(double startingBalance, double annualInterestRate) 
{
  balance_ = startingBalance;
  annualInterestRate_ = annualInterestRate;
  nDeposits_ = 0;
  nWithdraws_ = 0;
}

// Returns current balance
double Account::getBalance() 
{
  return balance_;
}

// Returns number of deposits made
int Account::getNumDeposits()
{
  return nDeposits_;
}

// Returns number of withdraws made
int Account::getNumWithdraws()
{
  return nWithdraws_;
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

void Account::saveToFile(std::string filename)
{
  std::ofstream file(filename.c_str());
  file.put('H');  
  file.close();
}

void Account::loadFromFile(std::string filename)
{

}

void writeLine(std::ofstream file, std::string key, std::string value)
{
  // Convert key and value into char arrays
  // Parse key in by char
  // Parse " : " in
  // Parse value in by char
  // Parse '\n'
}
