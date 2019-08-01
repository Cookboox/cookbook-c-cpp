#include <vector>
#include <iostream>
#include "Account.h"
#include "SavingAccount.h"
#include "CheckingAccount.h"
#include "TrustAccount.h"

//accounts
void display_all(std::vector<Account> &vec_acc)
{
	std::cout << "\n----displaying Accounts---------------------\n";
	for (auto const& i : vec_acc) std::cout << i;
}
void deposit_to_all(std::vector<Account> &vec_acc, double const& amount)
{
	std::cout << "\n----depositing to Accounts---------------------\n";
	for (auto& i : vec_acc)	
		if (i.deposit(amount)) 
		{
			std::cout << "succesfull deposit of " << amount << " to " << i;
		}
		else 
		{
			std::cout << "failed deposit of " << amount << " to " << i;
		}
		
}
void withdraw_from_all(std::vector<Account> &vec_acc, double const& amount)
{
	std::cout << "\n----withdrawing from Accounts---------------------\n";
	for (auto& i : vec_acc)	
		if(i.withdraw(amount))
		{
			std::cout << "succesfull withdraw of " << amount << " from " << i;
		}
		else
		{
			std::cout << "failed withdraw of " << amount << " from " << i;
		}
}

//saving accounts
void display_all(std::vector<SavingAccount> &vec_sacc)
{
	std::cout << "\n----displaying SavingAccounts---------------------\n";
	for (auto const& i : vec_sacc) std::cout << i;
}
void deposit_to_all(std::vector<SavingAccount> &vec_sacc, double const& amount)
{
	std::cout << "\n----deposing to SavingAccounts---------------------\n";
	for (auto& i : vec_sacc) 
		if(i.deposit(amount))
			{
				std::cout << "succesfull deposit of " << amount << " to " << i;
			}
			else
			{
				std::cout << "failed deposit of " << amount << " to " << i;
			}

}
void withdraw_from_all(std::vector<SavingAccount>& vec_sacc, double const& amount)
{
	std::cout << "\n----withdrawing from SavingAccounts---------------------\n";
	for (auto& i : vec_sacc)
		if(i.withdraw(amount))
			{
				std::cout << "succesfull withdraw of " << amount << " from " << i;
			}
			else
			{
				std::cout << "failed withdraw of " << amount << " from " << i;
			}
}

//checking accounts
void display_all(std::vector<CheckingAccount>& vec_sacc)
{
	std::cout << "\n----displaying CheckingAccounts---------------------\n";
	for (auto const& i : vec_sacc) std::cout << i;
}
void deposit_to_all(std::vector<CheckingAccount>& vec_sacc, double const& amount)
{
	std::cout << "\n----deposing to CheckingAccounts---------------------\n";
	for (auto& i : vec_sacc)
		if (i.deposit(amount))
		{
			std::cout << "succesfull deposit of " << amount << " to " << i;
		}
		else
		{
			std::cout << "failed deposit of " << amount << " to " << i;
		}

}
void withdraw_from_all(std::vector<CheckingAccount>& vec_sacc, double const& amount)
{
	std::cout << "\n----withdrawing from CheckingAccounts---------------------\n";
	for (auto& i : vec_sacc)
		if (i.withdraw(amount))
		{
			std::cout << "succesfull withdraw of " << amount << " from " << i;
		}
		else
		{
			std::cout << "failed withdraw of " << amount << " from " << i;
		}
}


//trust accounts
void display_all(std::vector<TrustAccount>& v)
{
	std::cout << "\n----displaying TrustAccounts---------------------\n";
	for (auto const& i : v) std::cout << i;
}
void deposit_to_all(std::vector<TrustAccount>& vec_sacc, double const& amount)
{
	std::cout << "\n----deposing to TrustAccounts---------------------\n";
	for (auto& i : vec_sacc)
		if (i.deposit(amount))
		{
			std::cout << "succesfull deposit of " << amount << " to " << i;
		}
		else
		{
			std::cout << "failed deposit of " << amount << " to " << i;
		}

}
void withdraw_from_all(std::vector<TrustAccount>& vec_sacc, double const& amount)
{
	std::cout << "\n----withdrawing from TrustAccounts---------------------\n";
	for (auto& i : vec_sacc)
		if (i.withdraw(amount))
		{
			std::cout << "succesfull withdraw of " << amount << " from " << i;
		}
		else
		{
			std::cout << "failed withdraw of " << amount << " from " << i;
		}
}