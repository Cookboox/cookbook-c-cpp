#pragma once
#include "Account.h"
#include <string>

class SavingAccount : public Account
{
	friend std::ostream& operator<<(std::ostream& os, SavingAccount const& rhs);
private:
	std::string name;
protected:
	//ballance inherited
	double interest_rate;
public:
	SavingAccount();
	SavingAccount(std::string name, double ballance, double interest_rate);
	~SavingAccount();

	void deposit(double amount);	//this function is redefined here
		
	//withdraw inherited
};

