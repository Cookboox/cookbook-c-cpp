#include "SavingAccount.h"
#include <iostream>

std::ostream& operator<<(std::ostream& os, SavingAccount const& rhs) 
{
	os << "ballance of this saving account " << rhs.name << " is " << rhs.ballance << ". Its interest rate is " << rhs.interest_rate <<"\n";
	return os;
}

SavingAccount::SavingAccount() : Account{}, interest_rate{0.05} {}
SavingAccount::SavingAccount(std::string name, double ballance, double interest_rate) : Account{ballance, name}, interest_rate{interest_rate} {}
SavingAccount::~SavingAccount() {}

//redefinition of deposit function
void SavingAccount::deposit(double deposited_amount) 
{
	deposited_amount += deposited_amount * this->interest_rate;
	this->ballance += deposited_amount;
	
	//or i could delegate the fucntion by calling 
	//Account::deposit(amount);
}