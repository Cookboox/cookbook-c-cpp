#pragma once
#include "Account.h"
#include <string>


//1. Add a Checking account class to the Account hierarchy
//A Checking account has a name and a balance and has a fee of $1.50 per withdrawal transaction.
//Every withdrawal transaction will be assessed this flat fee.


class CheckingAccount :	public Account
{
private:
	static constexpr char const* default_name = "unnamed chacking account";
	static constexpr double default_ballance{ 0 };
	static constexpr double default_fee{ 1.50 };
protected:
	//std::string name inherited
	//double ballance inherited
public:
	CheckingAccount(std::string name = default_name, double ballance = default_ballance);
	//void deposit() is completely inherited, no need to change anything
	bool withdraw(double amount);
};

