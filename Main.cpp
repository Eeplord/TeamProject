// main.cpp
// Author: Cameron March

#include <iostream>
#include <cstring>
#include "Account.h"

const double STARTING_BALANCE = 100.00;
const double ANNUAL_INTEREST_RATE = 2.3;

int main() 
{
  Account me(STARTING_BALANCE, ANNUAL_INTEREST_RATE);

  std::string name = "Cameron";

  const char* c_name = name.c_str();

  std::cout << c_name << std::endl;  
}
