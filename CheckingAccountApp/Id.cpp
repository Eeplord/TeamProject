#include "stdafx.h"
#include "Id.h"
#include "Account.h"

int Id::generateId_ = 0;

Id::Id() {
  std::string line;
  std::ifstream file(Account::basePath_ + Account::userIdPath_);
  std::getline(file, line);
  generateId_ = std::stoi(line);
  id_ = ++generateId_;
  file.close();
}

Id::Id(int id) : id_(id) {
}

std::string Id::find(const std::string& username) {
  std::string line;
  std::ifstream file(Account::basePath_ + Account::userIdPath_);
  while (!file.eof()) {
    std::getline(file, line);
    size_t query = line.find(username + Account::delimiter_);
    if (query != std::string::npos) {
      return line.substr(line.find(Account::delimiter_) + 1, line.rfind(Account::delimiter_));
    }
  }
  file.close();
  return "";
}