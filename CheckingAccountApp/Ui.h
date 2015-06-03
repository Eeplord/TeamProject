#ifndef UI_H
#define UI_H

#include "Account.h"
// #include "Withdrawal.h"
// #include "Deposit.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <regex>

class Ui {
private:
  const int USERNAME_LEN_MIN_ = 5;
  const int USERNAME_LEN_MAX_ = 25;
  const int PASSWORD_LEN_MIN_ = 5;
  const int PASSWORD_LEN_MAX_ = 255;
  const int DESCRIPTION_LEN_MAX_ = 255;
  const int DATE_LEN_ = 8;

public:

  // Flow control function for menus.
  void start();

	// Menu that displays account options for the user.
	// Returns the name of the action to be performed.
	std::string mainMenu();

	// Menu for creating a new account.
	// Creates a new account and saves it to database.
  // Returns the new account's username.
	std::string createAccount();

  // Menu for deleting an existing account.
  // Deletes the account with username provided by user.
  void deleteAccount();

  // Menu for loading an existing account.
  // Argument: username of account to be loaded.
  // Returns the loaded account.
  Account* loadAccount(const std::string&);

  // Menu for displaying account options.
  // Returns the name of the action to be performed.
  std::string Ui::accountMenu();

  // Menu for updating account information.
  void updateAccount(Account* const& account);

  // Menu for displaying balance.
  void getBalance(Account* const& account);

  // Menu for displaying previous withdrawals.
  void getWithdrawals(Account* const& account);

  // Menu for displaying previous deposits.
  void getDeposits(Account* const& account);

  // Menu for making a new withdraw.
  void withdraw(Account* const& account);

  // Menu for making a new deposit.
  void deposit(Account* const& account);

	// Get user input, parse it, and returns it to the caller.
  // Returns the expected input to the caller.
  double Ui::getUserInput();
	int getUserInput(const int&);
	std::string getUserInput(const std::string&);
};

#endif