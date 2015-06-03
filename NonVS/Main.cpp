// main.cpp
// Author: Cameron March

// Remove if not using Visual Studio
//#include "stdafx.h"
#include <iostream>
#include <string>
#include "Account.h"

void accountMenu(Account *account);
Account createAccount();
Account loadAccount();
void display(Account *account);
void withdraw(Account *account);
void deposit(Account *account);

int main()
{
	std::string mainCommands =  "[1] Create New Account\n[2] Load Account\n"
	"[q] Quit";

	bool quit = false;
	char input;
	Account account(0);

	while(!quit)
	{

		std::cout << mainCommands << std::endl;
		std::cin >> input;

		switch(input)
		{

			case '1':
				account = createAccount();
				accountMenu(&account);
				break;

			case '2':
				account = loadAccount();
				accountMenu(&account);
				break;

			case 'q':
				quit = true;
				break;

			default:
				std::cout << input << " is not a recognized command" <<
				std::endl;
				break;
		}
	}

	return 0;
}

void accountMenu(Account *account)
{
	std::string accountCommands = "[1] Show Account Information\n"
		"[2] Withdraw\n[3] Deposit\n[q] Logout";

	bool quit = false;
	char input;

	while(!quit)
	{
		std::cout << accountCommands << std::endl;
		std::cin >> input;

		switch(input)
		{
			case '1':
				display(account);
				break;

			case '2':
				withdraw(account);
				break;

			case '3':
				deposit(account);
				break;

			case 'q':
				quit = true;
				break;

			default:
				std::cout << input << " is not a recognized command" <<
				std::endl;
				break;
		}
	}
}

Account createAccount()
{

	int id;
	std::string name;
	double balance;
	double interest;

	std::cout << "Enter your id: ";
	std::cin >> id;

	std::cout << "Enter your name: ";
	std::cin >> name;

	std::cout << "Enter starting balance: ";
	std::cin >> balance;

	std::cout << "Enter annual interest rate: ";
	std::cin >> interest;

	Account account(id, name, balance, interest);
	account.save();
	return account;
}

Account loadAccount()
{
	int id;

	std::cout << "Enter your id: ";
	std::cin >> id;

	Account account(id);
	account.load();
	return account;
}

void withdraw(Account *account)
{
	double amount;

	std::cout << "Amount to withdraw: ";
	std::cin >> amount;

	double balance = account->withdraw(amount);

	std::cout << "Current balance: " << balance << std::endl;

	account->save();
}

void deposit(Account *account)
{
	double amount;

	std::cout << "Amount to deposit: ";
	std::cin >> amount;

	double balance = account->deposit(amount);

	std::cout << "Current balance: " << balance << std::endl;

	account->save();
}

void display(Account *account)
{
	std::cout << "ID: " << account->getId() << std::endl;
	std::cout << "Name: " << account->getName() << std::endl;
	std::cout << "Balance: " << account->getBalance() << std::endl;
	std::cout << "Interest Rate: " << account->getInterestRate() << std::endl;
}