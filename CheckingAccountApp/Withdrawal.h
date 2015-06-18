#ifndef WITHDRAWAL_H
#define WITHDRAWAL_H

class Withdrawal : public Transaction {
public:
  Withdrawal();
  Withdrawal(double, std::string, Date*);
  ~Withdrawal();
};

#endif