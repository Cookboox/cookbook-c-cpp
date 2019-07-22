#pragma once
#include <string>

class Account
{
private:
	std::string name;
	double ballance = 0;
public:
	double get_ballance();
	void deposit(double amount); 
	void withdraw(double amount);
};