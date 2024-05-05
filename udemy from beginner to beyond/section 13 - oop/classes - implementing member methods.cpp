#include<iostream>
#include<string>

class Account
{
private:
	std::string name;
	double balance;

public:
	void set_balance(double bal) { balance = bal; }
	double get_balance() { return balance; }

	//these are declared outside the class
	void set_name(std::string str);
	std::string get_name();
	bool deposit(double x);
	bool withdraw(double x);
};


int main()
{
	Account frank_acc;
	frank_acc.set_balance(1000);
	frank_acc.set_name("Frakie account");

	if (frank_acc.deposit(200))
	{
		std::cout << "deposition on " << frank_acc.get_name() << " ok. Balance is " << frank_acc.get_balance() << "\n";
	}else 
	{
		std::cout << "deposition on " << frank_acc.get_name() << " failed" << "\n";
	}

	if (frank_acc.withdraw(500))
	{
		std::cout << "withdraw on " << frank_acc.get_name() << " ok. Balance is " << frank_acc.get_balance() << "\n";
	}else
	{
		std::cout << "withdraw on " << frank_acc.get_name() << " failed" << "\n";
	}

	if (frank_acc.withdraw(100))
	{
		std::cout << "withdraw on " << frank_acc.get_name() << " ok. Balance is " << frank_acc.get_balance() << "\n";
	}
	else
	{
		std::cout << "withdraw on " << frank_acc.get_name() << " failed" << "\n";
	}

	if (frank_acc.withdraw(800))
	{
		std::cout << "withdraw on " << frank_acc.get_name() << " ok. Balance is " << frank_acc.get_balance() << "\n";
	}
	else
	{
		std::cout << "withdraw on " << frank_acc.get_name() << " failed" << "\n";
	}

	 
	 
	return 0; 
}

//here i implement the methods for the class 
void Account::set_name(std::string str) 
{
	name = str;
}

std::string Account::get_name()
{
	return name;
}

bool Account::deposit(double x)
{
	balance += x;
	return true;
}

bool Account::withdraw(double x)
{	
	if (balance - x > 0)
	{
		balance -= x;
		return true;
	}
	return false;
}
