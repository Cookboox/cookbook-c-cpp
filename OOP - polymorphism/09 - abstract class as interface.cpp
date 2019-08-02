#include <iostream>

//interface is:
//abstract class that has only pure virtual functions
//provides a general set of services (trough the virtual functions) to the user of the class
//these virtual functions must be public
//each subclass can implement the functions as needed
//each subclass must implement these methods

class Account
{	
	// ----THE PROBLEM----//
	// i want to implement cout method for all Accounts and use it as dynamic binding but:
	// 1) friend function cannot be virtual
	// 2) operator<< cannot be implemented as memeber function

	// ----THE SOLUTION IS TO MAKE ABSTRACT BASE CLASS AS PRINTABLE INTERFACE----//
	// implementation is in new file (see 09 - abstract base class as interface - solution.cpp)

	friend std::ostream& operator<<(std::ostream& os, Account const& rhs) { return os << "displaying Account\n"; }
public:
	virtual void withdraw(unsigned int amount) { std::cout << "witdrawing from Account\n"; }
	virtual ~Account() {}

};

class CheckingAccount :public Account
{
	friend std::ostream& operator<<(std::ostream& os, CheckingAccount const& rhs) { return os << "displaying CheckingAccount\n"; }
public:
	virtual void withdraw(unsigned int amount) override { std::cout << "witdrawing from CheckingAccount\n"; }
	virtual ~CheckingAccount() {}

};

class SavingAccount :public Account
{
	friend std::ostream& operator<<(std::ostream& os, SavingAccount const& rhs) { return os << "displaying SavingAccount\n"; }
public:
	virtual void withdraw(unsigned int amount) override { std::cout << "witdrawing from SavingAccount\n"; }
	virtual ~SavingAccount() {}

};

class TrustAccount :public Account
{
	friend std::ostream& operator<<(std::ostream& os, TrustAccount const& rhs) { return os << "displaying TrustAccount\n"; }
public:
	virtual void withdraw(unsigned int amount) override { std::cout << "witdrawing from TrustAccount\n"; }
	virtual ~TrustAccount() {}
};

int main()
{
	std::cout << "\n------OnTheStack---------------------\n";
	Account a;
	std::cout << a;

	CheckingAccount ca;
	std::cout << ca;

	SavingAccount sa;
	std::cout << sa;

	TrustAccount ta;
	std::cout << ta;

	std::cout << "\n------OnTheHeap---------------------\n";

	Account* ptra = new Account;
	Account* ptrca = new SavingAccount;
	
	std::cout << *ptra;
	std::cout << *ptrca;	//here is the problem - based class pointer and derived class object on the heap. operator<< is not virtual. will display Account

	return 0;
}