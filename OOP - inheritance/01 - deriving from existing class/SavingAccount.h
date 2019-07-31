#pragma once
#include "Account.h"

class SavingAccount : public Account
{
public:
	SavingAccount();
	~SavingAccount();
	void withdraw(double amount);
	void deposit(double amount);
	double interest{};
};

