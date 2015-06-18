#include "stdafx.h"
#include "Transaction.h"

Transaction::Transaction(double amount, std::string description, Date* date)
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

  std::cout << "Description: " << description_ << std::endl;
}

template <typename T> std::stack<T*> Transaction::load(std::string path) {
  std::ifstream fileIn(path);
  std::ofstream fileOut;
  std::stack<T*> transactions;
  int month;
  int day;
  int year;
  double amount;
  std::string sDate;
  std::string sAmount;
  std::string sDescription;
  std::string line;
  int delim = 0;

  if (fileIn.is_open()) {
    while (!fileIn.eof()) {
      std::getline(fileIn, line);
      for (std::string::const_iterator it = line.begin(); it < line.end(); ++it) {
        if (*it == Account::delimiter_) {
          +delim;
        }
        switch (delim) {
        case 1:
          sDate.push_back(*it + 1);
          break;
        case 2:
          sAmount.push_back(*it + 1);
          break;
        case 3:
          sDescription.push_back(*it + 1);
          break;
        }
      }
      month = std::stoi(sDate.substr(0, 2));
      day = std::stoi(sDate.substr(2, 2));
      year = std::stoi(sDate.substr(4, 4));
      amount = std::stod(sAmount);
      transactions.push_back(new T(amount, description, new Date(month, day, year)));
    }
    fileIn.close();
    return transctions;
  }
  else {
    std::ofstream fileOut(path);
    fileOut.close();
  }
}