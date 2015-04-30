// main.cpp
// Author: Cameron March

#include <iostream>
#include "account.h"

const double STARTING_BALANCE = 100.00;
const double ANNUAL_INTEREST_RATE = 2.3;

int main() {

  account me(STARTING_BALANCE, ANNUAL_INTEREST_RATE);
  
  std::cout << "Starting balance: " << me.getBalance() << std::endl;
  std::cout << "Depositing 500: " << me.deposit(500.0) << std::endl;
  std::cout << "Withdrawing 250.25: " << me.withdraw(250.25) << std::endl;
  std::cout << "Applying Montly Interest: " << me.calcInterest() << std::endl;

}
