// account.h
// Author: Cameron March

#ifndef ACCOUNT_H
#define ACCOUNT_H

// account simulates a person's bank account. It stores balance,
// interest rate, charges, and running counts of deposits and withdraws.
// Money can be withdrawn and deposited, and monthly interest can
// be applied.
class account {
  
 private:

  double balance;
  double annualInterestRate;
  double charges;
  int deposits;
  int withdraws;
  
 public:
  
  // Constructor
  account(double startingBalance, double interestRate);

  double getBalance();
  double deposit(double money);
  double withdraw(double money);

  // Calculates monthly interest and adds it to balance
  double calcInterest();

};

#endif
