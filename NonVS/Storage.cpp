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

	std::ofstream ofile;
	ofile.open(filename_.c_str());

	// Saves each member on a separate line in the order:
	// Id, Name, Balance, Interest Rate, Number of Deposits,
	// Number of Withdraws

	ofile << account.getId() << std::endl;
	ofile << account.getName() << std::endl;
	ofile << account.getBalance() << std::endl;
	ofile << account.getInterestRate() << std::endl;
	ofile << account.getNumDeposits() << std::endl;
	ofile << account.getNumWithdraws() << std::endl;

	ofile.close();
}

// Load should take an accountId arg and look for the account in the storage file.
// Then it should create an account with the settings related to that account.
Account Storage::load() {

	std::ifstream ifile;
	ifile.open(filename_.c_str());

	std::string line;
	
	std::getline(ifile, line);
       	int id = atoi(line.c_str());

	std::getline(ifile, line);
	std::string name = line;

	std::getline(ifile, line);
	double balance = atof(line.c_str());

	std::getline(ifile, line);
	double interest = atof(line.c_str());

	std::getline(ifile, line);
	int deposits = atoi(line.c_str());

	std::getline(ifile, line);
	int withdraws = std::atoi(line.c_str());

	Account account(id, name, balance, interest, deposits, withdraws);
	return account;
}

void Storage::changeFile(std::string filename) {

	filename_ = filename;
}
