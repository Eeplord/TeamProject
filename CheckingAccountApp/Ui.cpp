#include "stdafx.h"
#include "Ui.h"

void Ui::start() {
  std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
  std::string next = mainMenu();
  std::string username = "";
  Account* account = nullptr;

  while (next != "quit") {
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

    if (next == "mainMenu") {
      next = mainMenu();
    }
    else if (next == "accountMenu") {
      next = accountMenu();
    }
    else if (next == "createAccount") {
      username = createAccount();
      next = "mainMenu";
      if (username.length() != 0) {
        next = "loadAccount";
      }
    }
    else if (next == "deleteAccount") {
      deleteAccount();
      next = "mainMenu";
    }
    else if (next == "loadAccount") {
      account = loadAccount(username);
      username = "";
      next = "accountMenu";
      if (account == nullptr) {
        next = "loadAccount";
      }
    }
    else if (next == "updateAccount") {
      updateAccount(account);
      next = "accountMenu";
    }
    else if (next == "getWithdrawals") {
      getWithdrawals(account);
      next = "accountMenu";
    }
    else if (next == "getDeposits") {
      getDeposits(account);
      next = "accountMenu";
    }
    else if (next == "withdraw") {
      withdraw(account);
      next = "accountMenu";
    }
    else if (next == "deposit") {
      deposit(account);
      next = "accountMenu";
    }
    else if (next == "quitAccountMenu") {
      delete account;
      account = nullptr;
      next = "mainMenu";
    }
  }
}

std::string Ui::mainMenu() {
  std::cout << "This is the Checking Account App. ";
  std::cout << "Please choose from the following options:\n\n";
  std::cout << "1) Create new account.\n";
  std::cout << "2) Delete an existing account.\n";
  std::cout << "3) Load an existing account.\n";
  std::cout << "4) Quit\n\n";

  int nChoices = 4;
  int userChose = getUserInput(nChoices);

  switch (userChose) {
  case 1:
    return "createAccount";
  case 2:
    return "deleteAccount";
  case 3:
    return "loadAccount";
  case 4:
    return "quit";
  }
}

std::string Ui::createAccount() {
  std::string username;
  std::string password = "password";
  std::string repassword = "repassword";

  std::cout << "\n***\n";
  std::cout << "* ACCOUNT CREATION\n";
  std::cout << "**********\n\n";

  std::cout << "Please enter new username.\n";
  username = getUserInput("username");

  while (password != repassword) {
    std::cout << "Please enter a password.\n";
    password = getUserInput("password");

    std::cout << "Please reenter password.\n";
    repassword = getUserInput("password");

    if (password != repassword) {
      std::cout << "The password does not match.\n\n";
    }
  }
  if (Account::create(username, password)) {
    return username;
  }
  return "";
}

void Ui::deleteAccount() {
  std::string username;
  std::string actualPassword;
  std::string password;

  std::cout << "\n***\n";
  std::cout << "* ACCOUNT DELETION\n";
  std::cout << "**********\n\n";

  std::cout << "Please enter the username of the account to be deleted.\n";
  username = getUserInput("username");
  if (!Account::validate(username)) {
    return;
  }

  std::cout << "Please enter password.\n";
  password = getUserInput("password");
  if (!Account::authenticate(username, password)) {
    return;
  }

  Account::remove(username);
}

Account* Ui::loadAccount(const std::string& username) {
  Account* account;

  if (username.length() == 0) {
    std::string username;
    std::string actualPassword;
    std::string password;

    std::cout << "\n***\n";
    std::cout << "* LOAD ACCOUNT\n";
    std::cout << "**********\n\n";

    std::cout << "Please enter the username of the account.\n";
    username = getUserInput("username");
    if (!Account::validate(username)) {
      return nullptr;
    }

    std::cout << "Please enter password.\n";
    password = getUserInput("password");
    if (!Account::authenticate(username, password)) {
      return nullptr;
    }
     account = Account::load(username);
  }
  else {
    account = Account::load(username);
  }
  return account;
}

std::string Ui::accountMenu() {
  std::cout << "This is the account options menu. ";
  std::cout << "Please choose from the following options:\n\n";
  std::cout << "1) Update account information.\n";
  std::cout << "2) Show withdrawals.\n";
  std::cout << "3) Show deposits.\n";
  std::cout << "4) Make a new withdrawal\n";
  std::cout << "5) Make a new deposit\n";
  std::cout << "6) Go back to main menu\n";

  int nChoices = 6;
  int userChose = getUserInput(nChoices);

  switch (userChose) {
  case 1:
    return "updateAccount";
  case 2:
    return "getWithdrawals";
  case 3:
    return "getDeposits";
  case 4:
    return "withdraw";
  case 5:
    return "deposit";
  case 6:
    return "quitAccountMenu";
  }
}

void Ui::updateAccount(Account* const& account) {
  std::string firstName;
  std::string lastName;
  std::string polar = "no";
  std::string username = account->getUsername();
  std::string oldPassword;
  std::string newPassword = "new";
  std::string renewPassword = "renew";

  std::cout << "\n***\n";
  std::cout << "* UPDATE ACCOUNT INFORMATION\n";
  std::cout << "**********\n\n";

  while (polar == "no") {
    std::cout << "Please enter your first name.\n";
    firstName = getUserInput("all");

    std::cout << "Please enter your last name.\n";
    lastName = getUserInput("all");

    std::cout << "Your full name is " << firstName << ' ' << lastName;
    std::cout << ". Is this correct (Y/N)?\n";
    polar = getUserInput("polar");
  }

  std::cout << "Do you want to change your password (Y/N)?\n";
  polar = getUserInput("polar");
  if (polar == "no") {
    account->update(firstName, lastName);
    return;
  }

  std::cout << "Please enter password.\n";
  oldPassword = getUserInput("password");
  if (!Account::authenticate(username, oldPassword)) {
    return;
  }

  while (newPassword != renewPassword) {
    std::cout << "Please enter a new password.\n";
    newPassword = getUserInput("password");

    std::cout << "Please reenter password.\n";
    renewPassword = getUserInput("password");

    if (newPassword != renewPassword) {
      std::cout << "The password does not match.\n\n";
    }
  }
  account->update(firstName, lastName, newPassword);
}

void Ui::getBalance(Account* const& account) {
  std::cout << "\n***\n";
  std::cout << "* BALANCE\n";
  std::cout << "**********\n\n";

  account->getBalance();
}

void Ui::getWithdrawals(Account* const& account) {
  std::cout << "\n***\n";
  std::cout << "* HISTORY OF WITHDRAWALS\n";
  std::cout << "**********\n\n";

  // TODO: Add choices for sorting and single month display.
  account->getWithdrawals();
}

void Ui::getDeposits(Account* const& account) {
  std::cout << "\n***\n";
  std::cout << "* HISTORY OF DEPOSITS\n";
  std::cout << "**********\n\n";

  // TODO: Add choices for sorting and single month display.
  account->getDeposits();
}

void Ui::withdraw(Account* const& account) {
  double amount = 0;
  std::string description = "";
  std::string date = "";
  std::string polar;

  std::cout << "\n***\n";
  std::cout << "* MAKE A NEW WITHDRAWAL\n";
  std::cout << "**********\n\n";

  std::cout << "Please enter amount to withdraw.\n";
  amount = getUserInput();

  std::cout << "Do you want to describe your withdrawal (Y/N)?\n";
  polar = getUserInput("polar");

  if (polar == "no") {
    account->withdraw(amount, description, date);
    return;
  }

  std::cout << "Please describe your withdrawal.\n";
  description = getUserInput("description");

  std::cout << "Please enter the date.\n";
  date = getUserInput("date");
  account->withdraw(amount, description, date);
}

void Ui::deposit(Account* const& account) {
  double amount = 0;
  std::string description = "";
  std::string date = "";
  std::string polar;

  std::cout << "\n***\n";
  std::cout << "* MAKE A NEW DEPOSIT\n";
  std::cout << "**********\n\n";

  std::cout << "Please enter amount to deposit.\n";
  amount = getUserInput();

  std::cout << "Do you want to describe your deposit (Y/N)?\n";
  polar = getUserInput("polar");

  if (polar == "no") {
    account->deposit(amount, description, date);
    return;
  }

  std::cout << "Please describe your deposit.\n";
  description = getUserInput("description");

  std::cout << "Please enter the date.\n";
  date = getUserInput("date");
  account->deposit(amount, description, date);
}

std::string Ui::getUserInput(const std::string& query) {
  std::string userInput;
  int len;
  std::string argErr;
  std::string lenErr;
  std::cout << "> ";

  if (query == "username") {
    argErr = "A username can only contain alphanumeric characters. "
             "Please enter valid username.\n> ";
    lenErr = "Username must be between " + std::to_string(USERNAME_LEN_MIN_) + 
             " and " + std::to_string(USERNAME_LEN_MAX_) + " characters long.\n> ";
    std::regex notWords("[^[:alnum:]]");

    while (true) {
      std::getline(std::cin, userInput);
      len = userInput.length();
      try {
        if (std::regex_search(userInput, notWords)) {
          throw argErr;
        }
        else if (len < USERNAME_LEN_MIN_ || len > USERNAME_LEN_MAX_) {
          throw lenErr;
        }
        return userInput;
      }
      catch (const std::string& err) {
        std::cout << err;
      }
    }
  }

  else if (query == "password") {
    lenErr = "Password must be between " + std::to_string(PASSWORD_LEN_MIN_) +
             " and " + std::to_string(PASSWORD_LEN_MAX_) + " characters long.\n> ";
    argErr = "Password cannot contain '" + std::to_string(Account::delimiter_) + "' .\n> ";
    while (true) {
      // Remove: If Error.
      HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
      DWORD mode = 0;
      GetConsoleMode(hStdin, &mode);
      SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));
      ////////

      std::getline(std::cin, userInput);

      // Remove: If Error.
      SetConsoleMode(hStdin, mode);
      ////////

      len = userInput.length();
      try {
        if (len < PASSWORD_LEN_MIN_ || len > PASSWORD_LEN_MAX_) {
          throw lenErr;
        }
        else if (userInput.find(Account::delimiter_) != std::string::npos) {
          throw argErr;
        }
        std::cout << std::endl;
        return userInput;
      }
      catch (const std::string& err) {
        std::cout << err;
      }
    }
  }

  else if (query == "description") {
    lenErr = "Description must be between shorter than " + std::to_string(DESCRIPTION_LEN_MAX_) +
             " characters long.\n> ";
    while (true) {
      std::getline(std::cin, userInput);
      len = userInput.length();
      try {
        if (len > DESCRIPTION_LEN_MAX_) {
          throw lenErr;
        }
      }
      catch (const std::string& err) {
        std::cout << err;
      }
    }
  }

  else if (query == "date") {
    std::regex notNumbers("[^[:num:]]");
    int month;
    int day;
    int year;

    argErr = "Date must be in a MMDDYYYY format.\n> ";
    lenErr = argErr;

    while (true) {
      std::getline(std::cin, userInput);
      len = userInput.length();
      try {
        if (len != DATE_LEN_) {
          throw lenErr;
        }
        else if (std::regex_search(userInput, notNumbers)) {
          throw argErr;
        }
        month = std::stoi(userInput.substr(0, 2));
        day = std::stoi(userInput.substr(2, 2));
        year = std::stoi(userInput.substr(4, 4));

        if (month <= 0 || month > 12) {
          throw argErr;
        }
        else if (day <= 0 || day > 31) {
          throw argErr;
        }
        else if (year <= 2014) {
          throw argErr;
        }
      }
      catch (const std::string& err) {
        std::cout << err;
      }
    }
  }

  else if (query == "polar") {
    lenErr = "Please enter Y/N (not case sensitive).\n> ";
    argErr = lenErr;
    std::regex yYnN("[yYnN]");

    while (true) {
      std::getline(std::cin, userInput);
      len = userInput.length();
      try {
        if (len == 0 || len > 1) {
          throw lenErr;
        }
        else if (!std::regex_search(userInput, yYnN)) {
          throw argErr;
        }
        else if (userInput == "N" || userInput == "n") {
          return "no";
        }
        return "yes";
      }
      catch (const std::string& err) {
        std::cout << err;
      }
    }
  }

  else if (query == "all") {
    std::getline(std::cin, userInput);
    return userInput;
  }
}

int Ui::getUserInput(const int& nChoices) {
  std::cout << "> ";
  std::string userInput;
  int userChose = -1;

  while (userChose <= 0 || userChose > nChoices) {
    std::getline(std::cin, userInput);
    try {
      userChose = std::stoi(userInput);
      if (userChose <= 0 || userChose > nChoices) {
        throw std::invalid_argument("Out of range");
      }
    }
    catch (const std::invalid_argument& ia) {
      std::cout << "Please enter an integer between 1 and " << nChoices << std::endl;
      std::cout << "> ";
    }
  }
  return userChose;
}

double Ui::getUserInput() {
  std::cout << "> ";
  double amount;
  std::string userInput;

  while (true) {
    std::getline(std::cin, userInput);
    try {
      amount = std::stod(userInput);
      if (amount < 0) {
        throw "Please enter a value greater than 0.\n> ";
      }
      return amount;
    }
    catch (const std::invalid_argument& ia) {
      std::cout << "Please enter a double.\n> ";
    }
    catch (const std::string& argErr) {
      std::cout << argErr;
    }
  }
}