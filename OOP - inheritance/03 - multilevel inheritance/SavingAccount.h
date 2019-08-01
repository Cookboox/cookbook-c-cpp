#pragma once
#include "Account.h"
#include <string>

class SavingAccount : public Account
{
	friend std::ostream& operator<<(std::ostream& os, SavingAccount const& rhs);
private:
	static constexpr char const*  default_name = "unnamed saving account";
	static constexpr double default_ballance{ 0 };
	static constexpr double default_interest_rate{ 0.00 };
protected:
//	//double ballance is inherited
//	//std::string name is iheriterd
	double interest_rate;
public:
	SavingAccount(std::string name = default_name, double ballance = default_ballance, double interest_rate = default_interest_rate);
	bool deposit(double amount); //will be overriden

	//bool withdraw() is inherited
};

