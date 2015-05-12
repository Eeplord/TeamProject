// Storage.cpp
// Author: Cameron March

#include "Storage.h"

Storage::Storage(std::string filename) : filename_(filename) {

	// Check if filepath is correct.
}

// Save an account into the data file.
void Storage::save(Account account) {
	std::ofstream accounts;

	accounts.open(filename_.c_str());

	/** Account entries are in this format:
	*	@<Account ID>,<Account Owner Name>,<Balance>,<Annual Interest Rate>,<nDeposits>,<nWithdraws>
	*/
	accounts << "@" << account.getId() << ',' << account.getName() <<
		',' << account.getBalance() << ',' << account.getInterestRate() << ',' <<
		account.getNumDeposits() << ',' << account.getNumWithdraws() << std::endl;

	accounts.close();
}

// Load should take an accountId arg and look for the account in the storage file.
// Then it should create an account with the settings related to that account.
Account Storage::load(std::string accountId) {
  std::string line;
  std::ifstream accounts;
  accounts.open(filename_.c_str());

  std::vector<std::string> accountData;

  // Queries the info file for desired account and store account information in a vector.
  while(!accounts.eof()) {
  	std::string query = "@" + accountId;
	std::getline(accounts, line);
	if (line.find(query) != std::string::npos) {
		accountData = split(line);
	}
  }

  // Creates a new account with data vector.
  std::string ownerId       = accountData[0].substr(1, accountData[0].length() - 1);
  std::string ownerName     = accountData[1];
  double balance            = std::stod(accountData[2]);
  double annualInterestRate = std::stod(accountData[3]);
  int nDeposits             = std::stoi(accountData[4]);
  int nWithdraws            = std::stoi(accountData[5]);

  // TODO: Create a constructor for this.
  Account account = new Account(ownerId, ownerName, balance, annualInterestRate, nDeposits, nWithdraws);
  return account;
}

// Splits a string at designated delim.
std::vector<std::string> split(std::string str, char delim = ',') {
	std::string substr;
	std::vector<std::string> splitted;
	int current = 0;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == delim) {
			substr = str.substr(current, i - current);
			splitted.push_back(substr);
			current = i + 1;
		}
	}
	
	// Adds the last element to splitted (Assumes str doesn't end in delimitter).
	substr = str.substr(current, str.length() - 1);
	splitted.push_back();

	return splitted;
}

void Storage::changeFile(std::string filename)
{
  filename_ = filename;
}
