#include "stdafx.h"
#include "Transaction.h"

Transaction::Transaction(Date *date, double amount, std::string description)
{
	date_ = date;
	amount_ = amount;
	description_ = description;
}

std::string Transaction::getEntry()
{
  return Account::delimiter_ + std::to_string(date_->getMonth()) +
    std::to_string(date_->getDay()) + std::to_string(date_->getYear()) +
    Account::delimiter_ + std::to_string(amount_) + Account::delimiter_ +
    description_ + Account::delimiter_ + '\n';
}

void Transaction::print()
{
	std::cout << "Date: " << date_->getMonth() << "/" << date_->getDay() <<
		"/" << date_->getYear() << std::endl;

	std::cout << "Amount: $" << amount_ << std::endl;

	std::cout << "Description: "<< description_ << std::endl;
}