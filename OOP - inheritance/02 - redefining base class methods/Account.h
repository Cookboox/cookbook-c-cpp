#pragma once
#include <string>

class Account
{
	friend std::ostream& operator<<(std::ostream& os, Account const&);
private:
	std::string name;
protected:
	double ballance;
public:
	Account();
	Account(double ballance, std::string name);
	~Account();

	void deposit(double amount);
	void withdraw(double amount);
};
