#include <iostream>

class Account
{
public:
	virtual void withdraw(int x) { std::cout << "Account withdraw\n"; }
	virtual ~Account() {}
};

class CheckingAccount : public Account
{
public:
	virtual void withdraw(int x) override { std::cout << "CheckingAccount withdraw\n"; }
	virtual ~CheckingAccount() {}
}; 

class SavingAccount : public Account
{
public:
	virtual void withdraw(int x) override { std::cout << "SavingAccount withdraw\n"; }
	virtual ~SavingAccount() {}
}; 

class TrustAccount : public Account
{
public:
	virtual void withdraw(int x) override { std::cout << "TrustAccount withdraw\n"; }
	virtual ~TrustAccount() {}
};

void do_withdrawals(Account& acc, int amount)
{
	acc.withdraw(amount);
}

int main()
{
	Account a;
	Account &a_ref = a;

	a.withdraw(9);
	a_ref.withdraw(9);

	SavingAccount sa;
	TrustAccount ta;
	CheckingAccount ca;

	do_withdrawals(sa, 10);
	do_withdrawals(ca, 10);
	do_withdrawals(ta, 10);


	return 0;
}