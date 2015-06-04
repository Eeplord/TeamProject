#include "stdafx.h"
#include "Account.h"

// TODO: Replace with correct paths.
const std::string Account::userKeyPath_ = "userKey.txt";
const std::string Account::basePath_ = "Database/";
const std::string Account::infoPath_ = "AccountInfo/";
const std::string Account::withdrawalsPath_ = "Withdrawals/";
const std::string Account::depositsPath_ = "Deposits/";
const std::string Account::userIdPath_ = "userId.txt";

const char Account::delimiter_ = ';';

Account::Account(const std::string& username, const std::string& password)
  : username_(username), password_(password) {
  // id_ = new Id();
  // accountPath_ = id_->getPath();
  balance_ = 0;
  firstName_ = "";
  lastName_ = "";
}

Account::Account(const int& id, const std::string& username,
                 const std::string& password, const double& balance,
                 const std::string& firstName, const std::string& lastName,
                 const std::string& accountPath)
  : username_(username), password_(password), balance_(balance),
    firstName_(firstName), lastName_(lastName), accountPath_(accountPath) {
  // id_ = new Id(id);
}

// TODO: Finish destructor.
Account::~Account() {
  // id_->save();
  this->save();
  // Delete Id

  //while(!withdrawals_.empty()) {
  //  delete withdrawals_.top();
  //  withdrawals_.pop();
  //}

  //while(!deposits_.empty()) {
  //  delete deposits_.top();
  //  deposits_.pop();
  //}
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
  // std::string accountPath = Id::find(username);
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

  std::string accountPath = Id::find(username);
  file.open(basePath_ + accountPath + infoPath_);
  std::getline(file, line);
  id = std::stoi(Account::find(line, "id"));
  password = Account::find(line, "password");
  balance = std::stod(Account::find(line, "balance"));
  firstName = Account::find(line, "firstName");
  lastName = Account::find(line, "lastName");

  return new Account(id, username, password, balance, firstName, lastName, accountPath);
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
  // Check if username is in userKey first.
  // std::string accountPath = Id::find(username);
  // remove username:id from userKey.txt
  // remove basePath_/accountPath/
}

void Account::withdraw(const double& amount, const std::string& description,
                       const std::string& date) {
  if ((balance_ - amount) < 0) {
    getBalance();
    std::cout << "You cannot withdraw $";
    std::cout << std::setprecision(2) << std::fixed << amount;
    std::cout << " from this balance.\n";
    return;
  }
  balance_ -= amount;
  // withdrawals_.push(new Withdraw(amount, description, date));
  // this->save();
}

void Account::deposit(const double& amount, const std::string& description,
                      const std::string& date) {
  balance_ += amount;
  // deposits_.push(new Deposit(amount, description, date));
  // this->save();

}

void Account::getWithdrawals() {
  // this->get(withdrawals_);
}

void Account::getDeposits() {
  // this->get(deposits_);
}

template <typename T> void Account::get(std::stack<T const*>& stack) {
  //std::stack<T const*> bucket;
  //T const* temp;
  //while (!stack.empty()) {
  //  temp = stack.top();
  //  temp->print();
  //  bucket.push(temp);
  //  stack.pop();
  //}
  //
  //while (!bucket.empty()) {
  //  temp = bucket.top();
  //  stack.push(temp);
  //  bucket.pop();
  //}
}

void Account::save() {
  std::ofstream file;
  std::string entry = "";
  // std::stack<Withdrawals const*> tempWithdrawals;
  // std::stack<Withdrawals const*> tempDeposits;
  
  // Account Info
  file.open(basePath_ + infoPath_ + accountPath_);
  entry += delimiter_;
  // entry += id_->getId() + delimiter_;
  entry += username_ + delimiter_;
  entry += firstName_ + delimiter_;
  entry += lastName_ + delimiter_;
  entry += balance_ + delimiter_;
  file << entry << std::endl;
  file.close();

  // Withdrawals
  file.open(basePath_ + withdrawalsPath_ + accountPath_);
  //while (!withdrawals_.empty()) {
  //  file << (withdrawals_.top())->getEntry() << std::endl;
  //  tempWithdrawals.push(withdrawals_.top());
  //  withdrawals_.pop();
  //}
  //
  //while (!tempWithdrawals.empty()) {
  //  withdrawals_.push(tempWithdrawals.top());
  //  tempWithdrawals.pop();
  //}
  file.close();

  // Deposits
  file.open(basePath_ + depositsPath_ + accountPath_);
  //while (!deposits_.empty()) {
  //  file << (deposits_.top())->getEntry() << std::endl;
  //  tempDeposits.push(deposits_.top());
  //  deposits_.pop();
  //}
  //
  //while (!tempWithdrawals.empty()) {
  //  deposits_.push(tempDeposits.top());
  //  tempDeposits.pop();
  //}
  file.close();
}

void Account::getBalance() {
  std::cout << "Your current balance is $";
  std::cout << std::setprecision(2) << std::fixed << balance_ << ".\n";
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

