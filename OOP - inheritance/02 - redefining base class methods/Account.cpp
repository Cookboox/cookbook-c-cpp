#include "Account.h"
#include <iostream>

std::ostream& operator<<(std::ostream& os, Account const& rhs)
{
	os << "ballance of the " << rhs.name << " account is: " << rhs.ballance << "\n";
	return os;
}

Account::Account() : ballance{ 0 }, name{"default"} {}
Account::Account(double ballance, std::string name) : ballance{ ballance }, name{name} {}
Account::~Account() {}

void Account::deposit(double amount) { this->ballance += amount; }
void Account::withdraw(double amount)
{
	if (this->ballance - amount < 0) std::cout << "sorry not enought funds!\n";
	else this->ballance -= amount;
}