#include "stdafx.h"
#include "Withdrawal.h"

Withdrawal::Withdrawal(double amount, std::string description, Date* date)
: Transaction(amount, description, date)
{}

Withdrawal::~Withdrawal()
{
  delete date_;
}