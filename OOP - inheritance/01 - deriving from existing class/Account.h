#pragma once
#include <string>

class Account
{
//private:
//	std::string name;
//	double ballance;
public:
	Account();
	~Account();
	void deposit(double ammount);
	void withdraw(double ammount);
	std::string name{};
	double ballance{};
};

