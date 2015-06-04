// CheckingAccountApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Ui.h"
#include <fstream>
#include <stack>

int main() {
  //Ui ui;
  //ui.start();
  std::ofstream file;
  file.open("Database/test.txt");
  file << "test1";
  file.close();
}