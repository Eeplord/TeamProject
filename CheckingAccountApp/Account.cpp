#include "stdafx.h"
#include "Account.h"

// TODO: Replace with correct paths.
const std::string Account::userKeyPath_ = "";
const std::string Account::basePath_ = "";
const std::string Account::infoPath_ = "accountInfo.txt";
const std::string Account::withdrawalsPath_ = "withdrawals.txt";
const std::string Account::depositsPath_ = "deposits.txt";

const char Account::delimiter_ = ';';

Account::Account(const std::string& username, const std::string& password)
  : username_(username), password_(password) {
  // id_ = new Id();
  // accountPath_ = basePath_ + id_->getPath();
  balance_ = 0;
  firstName_ = "";
  lastName_ = "";
}

Account::Account(const int& id, const std::string& username,
                 const std::string& password, const double& balance,
                 const std::string& firstName, const std::string& lastName)
  : username_(username), password_(password), balance_(balance),
    firstName_(firstName), lastName_(lastName) {
  // id_ = new Id(id);
}

// TODO: Finish destructor.
Account::~Account() {
  // Save userKey username:id
  // Save basePath_/accountPath_/infoPath_
  // Save basePath_/accountPath_/withdrawalsPath_
  // Save basePath_/accountPath_/depositsPath_
  // Delete Id
  // Delete Withdrawals
  // Delete Deposits
}

bool Account::validate(const std::string& username) {
  std::ifstream file;
  std::string line;
  file.open(userKeyPath_);

  // TODO: O(n) is better because of small file size. What about large?
  while (!file.eof()) {
    std::getline(file, line);
    if (username == line) {
      return true;
    }
  }
  return false;
}
// TODO: Algorithm could be faster.
// TODO: Change depending on how data is stored.
bool Account::authenticate(const std::string& username, const std::string& password) {
  std::ifstream file;
  std::string line;
  // std::string accountPath = Id.find(username);
  // file.open(basePath_ + accountPath + infoPath_);
  std::getline(file, line);
  return Account::find(line, password, "password");
}

// TODO: Change depending on how data is stored.
Account* const Account::load(const std::string& username) {
  std::ifstream file;
  std::string line;

  int id;
  std::string password;
  double balance;
  std::string firstName;
  std::string lastName;

  // std::string accountPath = Id.find(username);
  // file.open(basePath_ + accountPath + infoPath_);
  std::getline(file, line);
  id = std::stoi(Account::find(line, "id"));
  password = Account::find(line, "password");
  balance = std::stod(Account::find(line, "balance"));
  firstName = Account::find(line, "firstName");
  lastName = Account::find(line, "lastName");

  return new Account(id, username, password, balance, firstName, lastName);
}

void Account::create(const std::string& username, const std::string& password) {
  Account account = Account(username, password);
  // Account info will be saved by destructor.
}

void Account::update(const std::string& firstName, const std::string& lastName) {
  firstName_ = firstName;
  lastName_ = lastName;
}

void Account::update(const std::string& firstName, const std::string& lastName, const std::string& password) {
  password_ = password;
  update(firstName, lastName);
}

// TODO: Finish remove
void Account::remove(const std::string& username) {
  // std::string accountPath = Id.find(username);
  // remove username:id from userKey.txt
  // remove basePath_/accountPath/
}

// TODO: Below
void Account::withdraw(const double& amount, const std::string& description,
  const std::string& date) {
  balance_ += amount;

}

void Account::deposit(const double& amount, const std::string& description,
                      const std::string& date) {
  balance_ += amount;
  // Deposit(amount, description, date);

}

void Account::getWithdrawals() {

}

void Account::getDeposits() {

}

void Account::getBalance() {

}

bool Account::find(const std::string& line, const std::string& query,
                   const std::string& queryType) {
  std::string index = find(line, queryType);
  return index == query;
}

// TODO: Change depending on how data is stored.
std::string Account::find(const std::string& line, const std::string& queryType) {
  int stop = 0;
  int pos = 0;
  std::string::const_iterator it;
  std::string index = "";

  if (queryType == "id") {
    stop = 1;
  }
  else if (queryType == "username") {
    stop = 2;
  }
  else if (queryType == "password") {
    stop = 3;
  }
  else if (queryType == "balance") {
    stop = 4;
  }
  else if (queryType == "firstName") {
    stop = 5;
  }
  else if (queryType == "lastName") {
    stop = 6;
  }

  for (it = line.begin(); it < line.end(); ++it) {
    if (*it == delimiter_) {
      ++pos;
    }
    if (pos == stop) {
      ++it;
      while (*it != delimiter_) {
        index.push_back(*it);
        ++it;
      }
      return index;
    }
  }
}

