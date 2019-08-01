#include "Account.h"
#include <iostream>

std::ostream& operator<<(std::ostream& os, Account const& rhs)
{
	os << "[Account " << rhs.name << " has now ballance: " << rhs.ballance << "]\n";
	return os;
} 

//no default args in the definition of the function!!
Account::Account(std::string name, double ballance) : name{name}, ballance{ballance} {}

bool Account::deposit(double amount)
{
	if (amount < 0) return false;
	else
	{
		this->ballance += amount;
		return true;
	}
}

bool Account::withdraw(double amount)
{
	if (this->ballance - amount < 0)
	{
		//std::cout << this->name << " has insufficient funds - WITHDRAW FAILED!!\n";
		return false;
	}
	else
	{
		this->ballance -= amount;
		//std::cout << this->name << " has withdrawn " << amount << " and current ballance is : " << this->ballance << " \n";
		return true;
	}
}

double Account::get_ballance() const //might not be used anywhere..
{
	return this->ballance;
}