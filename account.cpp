#include <iostream>
#include <iomanip>
#include "account.h"
using namespace std;


Account::Account(int no, double b) : accountNumber(no), balance(b) {

}


void Account::print() const {
  cout << fixed << setprecision(2);
  cout << "A/C no: " << accountNumber << " Balance=R$" << balance << endl;
}


int Account::getAccountNumber() const {
  return accountNumber;
}


double Account::getBalance() const {
  return balance;
}


void Account::setBalance(double b) {
  balance = b;
}

void Account::credit(double amount) {
  if (amount > 0) {
    balance += amount;
  }
}


void Account::debit(double amount) {
  if (amount < balance) {
    balance -= amount;
  }
}


int  Account::getPriority() const{
  return accountNumber;
}

Account::Account(const Account &obj) {
  balance       = obj.balance;
  accountNumber = obj.accountNumber;
}
