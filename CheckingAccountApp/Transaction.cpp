// Transaction.cpp

#include "stdafx.h"
#include "Account.h"
#include "Transaction.h"

Transaction::Transaction(Date *date, double amount, std::string description)
{
	date_ = date;
	amount_ = amount;
	description_ = description;
}

std::string Transaction::getEntry()
{
	return Account::delimiter_ << date_->getMonth() << date_->getDay() <<
		date_->getYear() << Account::delimiter_ << amount_ <<
		Account::delimiter_ << description_ << Account::delimiter_ << std::endl;
}

void Transaction::print()
{
	std::cout << "Date: " << date_->getMonth() << "/" << date_->getDay() <<
		"/" << date_->getYear() << std::endl;

	std::cout << "Amount: $" << amount_ << std::endl;

	std::cout << "Description: "<< description_ << std::endl;
}