#include "stdafx.h"
#include "Account.h"

const std::string Account::userKeyPath_ = "userKey.txt";
const std::string Account::tempPath_ = "temp.txt";
const std::string Account::basePath_ = "Database/";
const std::string Account::infoPath_ = "Account_Info/";
const std::string Account::withdrawalsPath_ = "Withdrawals/";
const std::string Account::depositsPath_ = "Deposits/";
const std::string Account::cryptoKey_ = "/M7YjY7sUhcdp51TY2jgLNjxa2+yWH7HJZhmvGP"
                                        "CC3USzP7LpCpqYww1wK7jGE0a7Gz+t5x1rrDVYZ"
                                        "PI0zcuvH7f/gsLIPMV4jY3fF44mn9XnWcRlcJgo"
                                        "Wxts0Zzq+177BmCKsLbT9UFlViigKMG8NZZOR9d"
                                        "RGcF8PBGI1FpJHC5on0E7TJeO1dmjmPpS46r3wj"
                                        "MdTDsiKBKcVI5KQEWEzg1HquSU4T5JkiKTIJOLm"
                                        "Jwk0FiI2Ba6Y8o8fGji8ERTWLxr1gGQ2NCIccVt"
                                        "lhFdztIgsNeHUryARdGJtJGvLDGtQ495PZh2WcE"
                                        "dyrciqUrGb5f8dlB8yvxZ/dA==";
const char Account::delimiter_ = ';';

Account::Account(const std::string& username, const std::string& password)
  : username_(username) {
  password_ = encrypt(password, cryptoKey_);
  id_ = new Id();
  accountPath_ = id_->getPath();
  balance_ = 0;
  firstName_ = "";
  lastName_ = "";
  save(true);

  // withdrawals_ = Withdrawal::load(accountPath_);
  // deposits_ = Deposits::load(accountPath_);
}

Account::Account(const int& id, const std::string& username,
                 const std::string& password, const double& balance,
                 const std::string& firstName, const std::string& lastName,
                 const std::string& accountPath)
  : username_(username), balance_(balance),
    firstName_(firstName), lastName_(lastName), accountPath_(accountPath) {
  id_ = new Id(id);
  password_ = encrypt(password, cryptoKey_);
  // withdrawals_ = Withdrawal::load(accountPath_);
  // deposits_ = Deposits::load(accountPath_);
}

// TODO: Finish destructor.
Account::~Account() {
  delete id_;

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
  std::string id = Id::find(username, false);
  if (id != "") {
    return true;
  }
  std::cout << "Username does not exists.\n";
  return false;
}

bool Account::authenticate(const std::string& username, const std::string& password) {
  std::ifstream file;
  std::string line;
  std::string accountPath = Id::find(username, true);
  file.open(basePath_ + infoPath_ + accountPath);
  std::getline(file, line);
  std::string decrypted = decrypt(password, cryptoKey_);
  bool found = Account::find(line, decrypted, "password");
  if (found) {
    return true;
  }
  std::cout << "Incorrect password/username.\n";
  return false;
}

Account* const Account::load(const std::string& username) {
  std::ifstream file;
  std::string line;
  int id;
  std::string password;
  double balance;
  std::string firstName;
  std::string lastName;

  std::string accountPath = Id::find(username, true);
  file.open(basePath_ + infoPath_ + accountPath);
  std::getline(file, line);
  id = std::stoi(Account::find(line, "id"));
  password = Account::find(line, "password");
  balance = std::stod(Account::find(line, "balance"));
  firstName = Account::find(line, "firstName");
  lastName = Account::find(line, "lastName");
  return new Account(id, username, password, balance, firstName, lastName, accountPath);
}

bool Account::create(const std::string& username, const std::string& password) {
  if (!Account::validate(username)) {
    Account account = Account(username, password);
    return true;
  }
  std::cout << "Username already exists.\n";
  return false;
}

void Account::update(const std::string& firstName, const std::string& lastName) {
  firstName_ = firstName;
  lastName_ = lastName;
  save(false);
}

void Account::update(const std::string& firstName, const std::string& lastName, const std::string& password) {
  password_ = encrypt(password, cryptoKey_);
  update(firstName, lastName);
}

void Account::remove(const std::string& username) {
  std::string line;
  std::string accountPath = Id::find(username, true);
  std::ifstream file(basePath_ + userKeyPath_);
  std::ofstream temp(basePath_ + tempPath_);
  while (!file.eof()) {
    std::getline(file, line);
    if (line.find(Account::delimiter_ + username + Account::delimiter_) == std::string::npos &&
        line.length() > 0) {
      temp << line << std::endl;
    }
  }
  file.close();
  temp.close();

  std::remove((basePath_ + userKeyPath_).c_str());
  std::rename((basePath_ + tempPath_).c_str(), (basePath_ + userKeyPath_).c_str());
  std::remove((basePath_ + infoPath_ + accountPath).c_str());
  std::remove((basePath_ + depositsPath_ + accountPath).c_str());
  std::remove((basePath_ + withdrawalsPath_ + accountPath).c_str());
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
  this->save(false);
}

void Account::deposit(const double& amount, const std::string& description,
                      const std::string& date) {
  balance_ += amount;
  // deposits_.push(new Deposit(amount, description, date));
  this->save(false);

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

void Account::save(const bool& unique) {
  if (unique) {
    saveId(basePath_ + Id::idPath_);
    saveUserKey(basePath_ + userKeyPath_);
  }
  saveInfo(basePath_ + infoPath_ + accountPath_);
  // saveWithdrawals(basePath_ + withdrawalPath_ + accountPath_);
  // saveDeposits(basePath_ + depositsPath_ + accountPath_);
}

void Account::saveId(const std::string& path) {
  std::ofstream file(path);
  file << id_->getId();
  file.close();
}

void Account::saveInfo(const std::string& path) {
  std::string entry = "";
  std::ofstream file(path);
  entry += delimiter_;
  entry += std::to_string(id_->getId()) + delimiter_;
  entry += username_ + delimiter_;
  entry += password_ + delimiter_;
  entry += std::to_string(balance_) + delimiter_;
  entry += firstName_ + delimiter_;
  entry += lastName_ + delimiter_;
  file << entry << std::endl;
  file.close();
}

void Account::saveUserKey(const std::string& path) {
  std::string entry = "";
  std::ofstream file(path, std::ios::app);
  entry = delimiter_ + username_ + delimiter_;
  entry += std::to_string(id_->getId()) + delimiter_;
  file << entry << std::endl;
  file.close();
}

void Account::saveWithdrawals(const std::string& path) {
  std::ofstream file(path);
  // std::stack<Withdrawals const*> tempWithdrawals;

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
}

void Account::saveDeposits(const std::string& path) {
  std::ofstream file(path);
  // std::stack<Deposits const*> tempDeposits;

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

