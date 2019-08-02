#include <iostream>

//if a derived class is destroyed by deleting its storage via base class pointer and the 
//the class has a non-virtual destructor, then the behaviour is undefined in c++ standart.

//derived objects must be destroyed in the correct order starting at the correct destructor

//simply, if we have a class that has virtual functions, then it ALWAYS has to provide virtual destructor
//if base class destructor is virtual, then all derived class destructor are also virtual


class Account
{
public:
	virtual void withdraw(unsigned int amount) { std::cout << "in Account::withdraw\n"; }
	virtual ~Account() { std::cout << "Account destructor\n"; }
};

class CheckingAccount : public Account
{
public:
	virtual void withdraw(unsigned int amount) { std::cout << "in CheckingAccount::withdraw\n"; } //no need to write virtual but better to do so
	virtual ~CheckingAccount() { std::cout << "CheckingAccount destructor\n"; }

};

class SavingAccount : public Account
{
public:
	virtual void withdraw(unsigned int amount) { std::cout << "in SavingAccount::withdraw\n"; } //no need to write virtual but better to do so
	virtual ~SavingAccount() { std::cout << "SavingAccount destructor\n"; }

};

class TrustAccount : public Account
{
public:
	virtual void withdraw(unsigned int amount) { std::cout << "in TrustAccount::withdraw\n"; } //no need to write virtual but better to do s
	virtual ~TrustAccount() { std::cout << "TrustAccount destructor\n"; }

};


int main()
{
	std::cout << "\n----RawPointers--------------\n";
	Account* p1 = new Account();
	Account* p2 = new CheckingAccount();
	Account* p3 = new SavingAccount();
	Account* p4 = new TrustAccount();

	p1->withdraw(1);
	p2->withdraw(1);
	p3->withdraw(1);
	p4->withdraw(1);

	std::cout << "\n-----DeletingPointers--------------\n";
	delete p1;
	delete p2;
	delete p3;
	delete p4;

	return 0;
}