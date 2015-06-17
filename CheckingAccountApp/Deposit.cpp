#include "stdafx.h"
#include "Deposit.h"

Deposit::Deposit(Date* date, double amount, std::string description)
	: Transaction(date, amount, description)
{}

Deposit::~Deposit()
{
	delete date_;
}