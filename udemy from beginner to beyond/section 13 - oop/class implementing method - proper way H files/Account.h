#pragma once
#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <string>

class Account
{
private:
	double balance;
	std::string name;

public:
	void set_balance(double bal) 
	{
		balance = bal;
	}
	double get_balance()
	{
		return balance;
	}

	//these are declared outside the class
	void set_name(std::string str);
	std::string get_name();
	bool deposit(double x);
	bool withdraw(double x);

};

#endif



