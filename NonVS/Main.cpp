// main.cpp
// Author: Cameron March

// Remove if not using Visual Studio
// #include "stdafx.h"
#include <iostream>
#include <string>
#include "Account.h"
#include "Storage.h"

const double STARTING_BALANCE = 100.00;
const double ANNUAL_INTEREST_RATE = 2.3;

int main()
{
	Account account(STARTING_BALANCE, ANNUAL_INTEREST_RATE);

	Storage storage("deleteMe.txt");

	storage.save(account);

	return 0;
}
