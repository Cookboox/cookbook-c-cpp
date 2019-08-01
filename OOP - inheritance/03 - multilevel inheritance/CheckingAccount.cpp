#include <string>
#include "CheckingAccount.h"

//delegating to construct CheckingAccount from Account
CheckingAccount::CheckingAccount(std::string name, double ballance) : Account{ name, ballance } {}

bool CheckingAccount::withdraw(double amount) 
{
	amount += this->default_fee;
	return Account::withdraw(amount);
}