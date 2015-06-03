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

int main()
{
	std::string mainCommands =  "[1] Create new Account\n[2] Load Account\n"
	"[q] Quit";

	std::string accountCommands = "[1] Withdraw\n[2] Deposit\n[q] Quit";

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
	std::string accountCommands = "[1] Withdraw\n[2] Deposit\n[q] Quit";

	bool quit = false;
	char input;

	while(!quit)
	{
		std::cout << accountCommands << std::endl;
		std::cin >> input;

		switch(input)
		{

			case '1':
				break;

			case '2':
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