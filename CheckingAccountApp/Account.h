#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "stdafx.h"

class Account {
private:
  const static std::string infoPath_;
  const static std::string withdrawalsPath_;
  const static std::string depositsPath_;
  const static std::string tempPath_;
  const static std::string cryptoKey_;

  std::string accountPath_;

  Id* id_;
  std::string firstName_;
  std::string lastName_;
  std::string username_;
  std::string password_;
  std::stack<Withdrawal*> withdrawals_;
  std::stack<Deposit*> deposits_;
  double balance_;

public:
  const static std::string basePath_;
  const static std::string userKeyPath_;

  // Used for creating output file and parsing it.
  const static char delimiter_;

  //////////
  // Constructor / Destructor
  /////////////////////////////

  // Used by the create method to create a new Account object.
  // Arguments: username, password
  Account(const std::string&, const std::string&);

  // Used by the load method to create a new Account object.
  // Arguments: id, username, password, balance, firstName, lastName.
  Account(const int&, const std::string&, const std::string&, const double&,
          const std::string&, const std::string&, const std::string&);

  ~Account();

  //////////
  // Static functions
  //////////////////////

  // Validates if a username exists in the database.
  // Argument: username.
  // Returns true if found.
  static bool validate(const std::string&);

  // Authenticates a username and password.
  // Arguments: username, password.
  // Returns true if password matches username.
  static bool authenticate(const std::string&, const std::string&);

  // Creates a new Account object with data from database.
  // Argument: username.
  // Returns const pointer to Account object.
  static Account* const load(const std::string&);

  // Creates a new Account object with provided information.
  // Argument: username, password.
  static bool create(const std::string&, const std::string&);

  // Removes all information related to provided username.
  // Argument: username.
  static void remove(const std::string&);

  //////////
  // Class methods
  ///////////////////

  // Update the account with new information.
  // Arguments: First name, last name, optional password
  void update(const std::string&, const std::string&);
  void update(const std::string&, const std::string&, const std::string&);

  // Make a new withdrawal.
  // Prints error or new balance.
  // Adjusts balance and add to withdrawals.txt.
  void withdraw(const double&, const std::string&, Date*);

  // Make a new deposit.
  // Prints error or new balance.
  // Adjusts balance and add to deposits.txt.
  void deposit(const double&, const std::string&, Date*);

  // Update username:id list
  // Saves all account information in basePath_/
  // Saves to accountInfo_/, withdrawals_/, and deposits_/
  void save(const bool&);
  void saveId(const std::string&);
  void saveInfo(const std::string&);
  void saveUserKey(const std::string&);
  void saveWithdrawals(const std::string&);
  void saveDeposits(const std::string&);

  //////////
  // Getter functions
  /////////////////////

  std::string getUsername() { return username_; }
  void getWithdrawals();
  void getDeposits();
  template <typename T> void get(std::stack<T*>);
  void getBalance();

  //////////
  // Helper functions
  //////////////////////

  // Helper function for parsing account information from text file.
  // Arguments: line to be searched, query, query type.
  // Returns true if found.
  static bool find(const std::string&, const std::string&, const std::string&);

  // Helper function for parsing account information from text file.
  // Arguments: line to be searched, query type.
  // Returns the found query.
  static std::string find(const std::string&, const std::string&);
};

#endif