#ifndef TRANSACTION_H
#define TRANSACTION_H

class Transaction {
public:
  Transaction();
  Transaction(double, std::string, Date*);
  std::string getEntry();
  void print();
  template <typename T> static std::stack<T*> load(std::string);

protected:
  Date* date_;
  double amount_;
  std::string description_;
};

#endif