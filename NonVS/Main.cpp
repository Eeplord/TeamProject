// main.cpp
// Author: Cameron March

// Remove if not using Visual Studio
#include "stdafx.h"
#include <iostream>
#include <string>
#include "Account.h"
#include "Storage.h"

Account createAccount();

int main()
{
	std::string commands =  "[1] Create new Account\n[2] Load Account\n"
				"[q] Quit";
	bool quit = false;
	char input;

	while(!quit) {

		std::cout <<  commands << std::endl;
		std::cin >> input;

		switch(input) {

			case '1':
				createAccount();
				break;

			case '2':
				std::cout << input << std::endl;
				break;

			case 'q':
				std::cout << input << std::endl;
				quit = true;
				break;

			default:
				std::cout << input <<
					" is not a recognized command"
					<< std::endl;
				break;
		}
	}

	return 0;
}

Account createAccount() {

	std::string name;
	double balance;
	double interest;

	std::cout << "Enter your name: ";
	std::cin >> name;

	std::cout << "Enter starting balance: ";
	std::cin >> balance;

	std::cout << "Enter annual interest rate: ";
	std::cin interest;

	
}
