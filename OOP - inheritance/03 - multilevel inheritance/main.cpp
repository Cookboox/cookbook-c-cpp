#include <iostream>
#include <vector>
#include "Account.h"
#include "SavingAccount.h"
#include "CheckingAccount.h"
#include "TrustAccount.h"

#include "handler_functions.h"


int main()
{
	std::vector<Account> vec_acc;

	vec_acc.push_back(Account {});
	vec_acc.push_back(Account {"One"});
	vec_acc.push_back(Account{"Two", 2000});

	display_all(vec_acc);
	deposit_to_all(vec_acc, 1000);
	withdraw_from_all(vec_acc, 2000);

	std::cout << "\n============================\n";

	std::vector<SavingAccount> vec_sacc;

	vec_sacc.push_back(SavingAccount{});
	vec_sacc.push_back(SavingAccount { "OneSaving" });
	vec_sacc.push_back(SavingAccount { "TwoSaving", 20000 });
	vec_sacc.push_back(SavingAccount { "ThreeSaving", 30000, 0.03 });

	display_all(vec_sacc);
	deposit_to_all(vec_sacc, 10000);
	withdraw_from_all(vec_sacc, 20000);

	std::cout << "\n============================\n";

	std::vector<CheckingAccount> checking_accounts;
	checking_accounts.push_back(CheckingAccount{});
	checking_accounts.push_back(CheckingAccount{"OneChecking", 1000});
	checking_accounts.push_back(CheckingAccount{"TwoChecking", 2000});

	display_all(checking_accounts);
	deposit_to_all(checking_accounts, 1000);
	withdraw_from_all(checking_accounts, 2000);

	std::cout << "\n============================\n";

	std::vector<TrustAccount>  trust_accounts;
	trust_accounts.push_back(TrustAccount{});
	trust_accounts.push_back(TrustAccount{"OneTrust", 10000});
	trust_accounts.push_back(TrustAccount{"TwoTrust", 20000, 0.05});
	trust_accounts.push_back(TrustAccount{"ThreeTrust", 50000, 0.10});

	display_all(trust_accounts);
	deposit_to_all(trust_accounts, 10000);
	withdraw_from_all(trust_accounts, 2000);
	withdraw_from_all(trust_accounts, 200);
	withdraw_from_all(trust_accounts, 200);
	withdraw_from_all(trust_accounts, 300);
	withdraw_from_all(trust_accounts, 300);
	withdraw_from_all(trust_accounts, 300);
	withdraw_from_all(trust_accounts, 300);

	TrustAccount a{ "a", 10000, 0.1 };
	TrustAccount b{ "b", 10000, 0.2 };
	TrustAccount c{ "c", 10000, 0.02 };

	a.deposit(1000);
	b.deposit(1000);
	c.deposit(1000);

	std::cout << a;
	std::cout << b;
	std::cout << c;
	
	a.deposit(10000);
	b.deposit(10000);
	c.deposit(10000);

	std::cout << a;
	std::cout << b;
	std::cout << c;

	for(int i = 0; i <= 3; ++i) a.withdraw(100);

	std::cout << a;
	a.withdraw(1);
	//a.withdraw(1);

	return 0;
}