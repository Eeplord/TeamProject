#include "stdafx.h"
#include "Withdraw.h"

Withdraw::Withdraw(Date* date, double amount, std::string description)
	: Transaction(date, amount, description)
{}

Withdraw::~Withdraw()
{
	delete date_;
}