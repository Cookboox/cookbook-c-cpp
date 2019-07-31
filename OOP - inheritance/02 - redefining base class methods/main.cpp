#include <iostream>
#include "Account.h"
#include "SavingAccount.h"

// make two classes 
// 1) account with normal withdraw and deposit functions
// 2) saving account with the same two functions except that savings account adds interest rate (5%) from each deposit
// overload << operator for both to display the name and the ballance of the particular account


int main()
{
	//std::cout << "--------Account------------------\n";
	//Account acc;
	//std::cout << acc;

	//Account lukas_acc{ 1000, "lukas account" };
	//std::cout << lukas_acc;
	//lukas_acc.deposit(1000);
	//lukas_acc.withdraw(300);
	//std::cout << lukas_acc;

	//std::cout << "--------SavingAccount------------------\n";

	//SavingAccount sacc;
	//std::cout << sacc;

	SavingAccount lukas_sacc{ "lukas saving", 1000, 0.05 };
	std::cout << lukas_sacc;
	lukas_sacc.deposit(1000);
	//lukas_sacc.withdraw(500);
	std::cout << lukas_sacc;

	return 0;
}