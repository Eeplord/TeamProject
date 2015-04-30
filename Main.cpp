// main.cpp
// Author: Cameron March

#include <iostream>
#include "Account.h"

const double STARTING_BALANCE = 100.00;
const double ANNUAL_INTEREST_RATE = 2.3;

int main() 
{
  Account me(STARTING_BALANCE, ANNUAL_INTEREST_RATE);
  
  std::cout << "Starting balance: " << me.getBalance() << std::endl;
  std::cout << "Depositing 500: " << me.deposit(500.0) << std::endl;
  std::cout << "Withdrawing 250.25: " << me.withdraw(250.25) << std::endl;
  std::cout << "Applying Monthly Interest: " << me.calculateInterest()
	<< std::endl;
}
