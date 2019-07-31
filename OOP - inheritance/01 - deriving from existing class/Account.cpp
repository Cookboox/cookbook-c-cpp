#include "Account.h"
#include <iostream>

Account::Account() : ballance{0}, name{"an account"} {}
Account::~Account(){}
void Account::deposit(double amount) { std::cout << "depositing to account " << amount << "\n"; }
void Account::withdraw(double amount) { std::cout << "witdrawing from account " << amount << "\n"; }