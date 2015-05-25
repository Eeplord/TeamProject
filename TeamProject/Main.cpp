// main.cpp
// Author: Cameron March

// Remove if not using Visual Studio
#include "stdafx.h"
#include <iostream>
#include <string>
#include "Account.h"
#include "Storage.h"

int main()
{
	Storage storage("Load.txt");

	Account account = storage.load();

	storage.changeFile("Save.txt");

	storage.save(account);

	return 0;
}
