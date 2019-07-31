#include <iostream>
#include "Account.h"
#include "SavingAccount.h"

int main()
{
	std::cout << "----Account----------------------------------\n";
	Account acc{};
	acc.deposit(1000);
	acc.withdraw(300);

	Account* acc_ptr = new Account{};
	acc_ptr->deposit(2000);
	acc_ptr->withdraw(600);
	delete acc_ptr;

	std::cout << "\n----SavingAccount----------------------------\n";
	SavingAccount sacc{};
	sacc.deposit(10000);
	sacc.withdraw(3000);

	SavingAccount* sacc_ptr = new SavingAccount{};
	sacc_ptr->deposit(20000);
	sacc_ptr->withdraw(6000);
	delete sacc_ptr;

	return 0;
}