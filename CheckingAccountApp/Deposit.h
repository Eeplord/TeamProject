#ifndef DEPOSIT_H
#define DEPOSIT_H

class Deposit : public Transaction {
public:
  Deposit();
  Deposit(double, std::string, Date*);
  ~Deposit();
};

#endif