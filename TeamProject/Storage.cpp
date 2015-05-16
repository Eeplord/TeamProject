// Storage.cpp
// Authors: Cameron March, Tuan Phan

// Remove if not using Visual Studio
#include "stdafx.h"
#include "Storage.h"

Storage::Storage(std::string filename) : filename_(filename) {

	// Check if filepath is correct.
}

// Save an account into the data file.
void Storage::save(Account account) {
	std::ofstream accounts;

	accounts.open(filename_.c_str());

	// Saves each member on a separate line in the order:
	// Id, Name, Balance, Interest Rate, Number of Deposits,
	// Number of Withdraws

	accounts << account.getId() << std::endl;
	accounts << account.getName() << std::endl;
	accounts << account.getBalance() << std::endl;
	accounts << account.getInterestRate() << std::endl;
	accounts << account.getNumDeposits() << std::endl;
	accounts << account.getNumWithdraws() << std::endl;

	accounts.close();
}

// Load should take an accountId arg and look for the account in the storage file.
// Then it should create an account with the settings related to that account.
Account Storage::load() {

	Account account(0, "null", 0.0, 0.0, 0, 0);
	return account;
}

void Storage::changeFile(std::string filename) {

	filename_ = filename;
}