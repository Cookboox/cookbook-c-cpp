#include "SavingAccount.h"
#include <iostream>

std::ostream& operator<<(std::ostream& os, SavingAccount const& rhs)
{ 
	os << "[Account " << rhs.name << " has now ballance " << rhs.ballance << " and interest rate " << rhs.interest_rate * 100 << "%] \n";
	return os;
}

//first i delegate to construct Account part to Account constructor, then i add interest rate to it
SavingAccount::SavingAccount(std::string name, double ballance, double interest_rate) : Account{name, ballance}, interest_rate{interest_rate} {}

bool SavingAccount::deposit(double amount) //will be overriden in such a way that it adds the interest rate to each deposit
{
	amount += amount * interest_rate;
	return Account::deposit(amount); //delegating to process it by Account´s function
} 

