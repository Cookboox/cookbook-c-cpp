#include <iostream>
#include "SavingAccount.h"
#include "Account.h"
#include  "TrustAccount.h"

//2. Add a Trust account class to the Account hierarchy
//A Trust account has a name, a balance, and an interest rate
//The Trust account deposit works just like a savings account deposit.
//However, any deposits of $5000.00 or more will receive a $50.00 bonus deposited to the account.
//
//The Trust account withdrawal should only allow 3 withdrawals per year
//and each of these must be less than 20 % of the account balance.
//You don't have to keep track of calendar time for this application, just make sure the 4th withdrawal fails :)

TrustAccount::TrustAccount(std::string name, double ballance, double interest_rate) : SavingAccount{name, ballance, interest_rate} {}

bool TrustAccount::deposit(double amount)
{
	if (amount > bonus_threshold)
	{
		//amount += amount * interest_rate;
		amount += bonus;
		return SavingAccount::deposit(amount);
	}
	else
	{
		//amount += amount * interest_rate;
		return SavingAccount::deposit(amount);
	}
	
}

bool TrustAccount::withdraw(double amount)
{
	if (amount > this->ballance * max_limit_withdraw)
	{
		std::cout << "sorry, u cant withdraw more then 20% of your ballance\n";
		return false;
	}
	else if(withdrawals > 3)
	{
		std::cout << "sorry, u exceeded the number of allowed withdrawals (3)\n";
		return false;
	}
	else
	{
		withdrawals++;
		return SavingAccount::withdraw(amount);
	}
}