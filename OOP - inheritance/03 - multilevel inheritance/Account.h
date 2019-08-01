#pragma once
#include <string>

class Account
{
	friend std::ostream& operator<<(std::ostream& os, Account const& rhs);
private:
	static constexpr char const* default_name = "unnamed account"; 
	static constexpr double default_ballance{ 0 };
protected:
	std::string name;
	double ballance;
public:
	Account(std::string name = default_name, double ballance = default_ballance);
	bool deposit(double amount);
	bool withdraw(double amount);

	double get_ballance() const; //might not be used anywhere..
};

