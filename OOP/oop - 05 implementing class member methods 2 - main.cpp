#include <iostream>
#include "oop - 05 implementing class member methods 2.h"


int main()
{
	Account my_account;

	std::cout << my_account.get_ballance() << "\n";

	my_account.deposit(1111);
	std::cout << my_account.get_ballance() << "\n";

	my_account.withdraw(333);
	std::cout << my_account.get_ballance() << "\n";

	return 0;
}