// Storage.cpp
// Author: Cameron March

#include "Storage.h"

Storage::Storage(std::string filename)
{
  filename_ = filename;
}

void Storage::save(Account account)
{

}

Account Storage::load()
{
  Account account(10.0, 2.0);
  return account;
}

void Storage::changeFile(std::string filename)
{
  filename_ = filename;
}
