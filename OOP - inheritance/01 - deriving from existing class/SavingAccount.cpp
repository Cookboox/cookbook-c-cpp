#include "SavingAccount.h"
#include <iostream>

SavingAccount::SavingAccount() : interest{ 3.0 } {}
SavingAccount::~SavingAccount() {}
void SavingAccount::deposit(double amount) {std::cout << "depositing to saving account " << amount << "\n";}
void SavingAccount::withdraw(double amount) { std::cout << "withdrawing from saving account " << amount << "\n"; }