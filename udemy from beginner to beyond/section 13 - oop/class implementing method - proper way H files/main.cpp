#include<iostream>
#include"Account.h"

int main()
{
	Account frank_acc;
	frank_acc.set_balance(1000);
	frank_acc.set_name("Frakie account");

	if (frank_acc.deposit(200))
	{
		std::cout << "deposition on " << frank_acc.get_name() << " ok. Balance is " << frank_acc.get_balance() << "\n";
	}
	else
	{
		std::cout << "deposition on " << frank_acc.get_name() << " failed" << "\n";
	}

	if (frank_acc.withdraw(500))
	{
		std::cout << "withdraw on " << frank_acc.get_name() << " ok. Balance is " << frank_acc.get_balance() << "\n";
	}
	else
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
