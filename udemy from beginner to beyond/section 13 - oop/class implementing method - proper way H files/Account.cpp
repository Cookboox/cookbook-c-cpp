#include "Account.h"

void Account::set_name(std::string str)
{
	name = str;
}

std::string Account::get_name()
{
	return name;
}

bool Account::deposit(double x)
{
	balance += x;
	return true;
}

bool Account::withdraw(double x)
{
	if (balance - x > 0)
	{
		balance -= x;
		return true;
	}
	return false;
}

bool Account::withdraw(double x)
{
	return false;
}
