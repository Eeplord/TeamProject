#include "stdafx.h"
#include "Deposit.h"

Deposit::Deposit(double amount, std::string description, Date* date)
: Transaction(amount, description, date)
{}

Deposit::~Deposit()
{
  delete date_;
}