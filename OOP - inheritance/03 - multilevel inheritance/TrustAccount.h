#pragma once
#include "SavingAccount.h"


//2. Add a Trust account class to the Account hierarchy
//A Trust account has a name, a balance, and an interest rate
//The Trust account deposit works just like a savings account deposit.
//However, any deposits of $5000.00 or more will receive a $50.00 bonus deposited to the account.
//
//The Trust account withdrawal should only allow 3 withdrawals per year
//and each of these must be less than 20 % of the account balance.
//You don't have to keep track of calendar time for this application, just make sure the 4th withdrawal fails :)


class TrustAccount : public SavingAccount
{
private:
	static constexpr char const* default_name = "unnamed trust account";
	static constexpr double default_ballance{ 0 };
	static constexpr double default_interest_rate{ 0 };
	static constexpr unsigned int bonus{ 50 };
	static constexpr unsigned int bonus_threshold{ 5000 };
	static constexpr double max_limit_withdraw = 0.2;
protected:
	//double ballance is inherited
	//std::string name is iheriterd
	//double interest_rate inherited
	unsigned int withdrawals{ 0 };
public:
	TrustAccount(std::string name = default_name, double ballance = default_ballance, double interest_rate = default_interest_rate);
	
	bool deposit(double amount);
	bool withdraw(double amount);
};