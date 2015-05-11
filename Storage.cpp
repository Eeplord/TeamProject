// Storage.cpp
// Author: Cameron March

#include "Storage.h"
#include <fstream>
#include <string>

Storage::Storage(std::string filename) : filename_(filename) {

	// Check if filepath is correct.
}

void Storage::save(Account account) {
	std::ofstream accounts;
	accounts.open(filename_);

	/** Account entries are in this format:
	*	@<Account ID>,<Account Owner Name>,<Balance>,<Annual Interest Rate>,<nDeposits>,<nWithdraws>
	*/
	accounts << "@" << account.ownerId_ << ',' << account.ownerName_ << ',' << account.balance_;
	accounts << ',' << account.annualInterestRate_ << ',' << account.nDeposits_ << ',' << account.nWithdraws_;
	accounts << std::endl;

	accounts.close();
}

// Load should take an accountId arg and look for the account in the storage file.
// Then it should create an account with the settings related to that account.
Account Storage::load(std::string accountId) {
  std::string line;
  std::ifstream accounts;
  accounts.open(filename_);

  while(!accounts.eof()) {
  	std::string query = "@" + accountId;
  	std::getline(accounts, line)
  }
}

void Storage::changeFile(std::string filename)
{
  filename_ = filename;
}
