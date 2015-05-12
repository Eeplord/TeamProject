// Storage.h
// Author: Cameron March

#ifndef STORAGE_H
#define STORAGE_H

#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include "Account.h"

// Storage will handle the persistent data required for our project.
// It holds the path to a file, and can either save or load data to
// or from the file. It can change its stored location, so only one
// of these objects is required, saving memory.

class Storage
{
 public:
  
  // Constructor
  Storage(std::string filename);

  // I/O Methods
  void save(Account account);
  Account load();

  // Change file storage is editing
  void changeFile(std::string filename);

 private:

  // Filepath
  std::string filename_;
};

#endif
