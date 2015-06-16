#include "stdafx.h"
#include "Id.h"

int Id::generateId_;
const std::string Id::idPath_ = "id.txt";

Id::Id() {
  std::string line;
  std::ifstream file(Account::basePath_ + Id::idPath_);
  if (file.is_open()) {
    std::getline(file, line);
    generateId_ = std::stoi(line);
    id_ = ++generateId_;
    file.close();
  }
  else {
    generateId_ = 0;
    id_ = generateId_;
  }
}

Id::Id(int id) : id_(id) {
}

std::string Id::find(const std::string& username, const bool& path) {
  std::string line;
  std::ifstream file(Account::basePath_ + Account::userKeyPath_);
  if (!file.is_open()) {
    std::ofstream out(Account::basePath_ + Account::userKeyPath_);
    out.close();
    file.open(Account::basePath_ + Account::userKeyPath_);
  }
  while (!file.eof()) {
    std::getline(file, line);
    size_t query = line.find(username + Account::delimiter_);
    if (query != std::string::npos) {
      size_t idStart = line.find(Account::delimiter_, 1) + 1;
      size_t idLen = (line.length() - 1) - idStart;
      std::string id = line.substr(idStart, idLen);
      if (path) {
        return createPath(id);
      }
      else {
        return id;
      }
    }
  }
  file.close();
  return "";
}

std::string Id::createPath(const std::string& id) {
  return ("user" + id + ".txt");
}

std::string Id::getPath() {
  return Id::createPath(std::to_string(id_));
}