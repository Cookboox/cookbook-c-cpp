#include <string>
#include "oop - 05 implementing class member methods 2.h"

double Account::get_ballance() { return this->ballance; }
void Account::deposit(double amount) { this->ballance += amount; }
void Account::withdraw(double amount) { this->ballance -= amount; }