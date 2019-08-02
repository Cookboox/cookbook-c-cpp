#include <iostream>

//interface is:
//abstract class that has only pure virtual functions
//provides a general set of services (trough the virtual functions) to the user of the class
//these virtual functions must be public
//each subclass can implement the functions as needed
//each subclass must implement these methods


class I_Printable //I - Interface for printable objects
{
	friend std::ostream& operator<<(std::ostream& os, I_Printable const& rhs)
	{
		rhs.print(os); // will "delegate" the displaying to each class in the hierarchy
		return os;
	}

public:
	virtual void print(std::ostream& os) const = 0; //pure virtual function that takes return value from operator<< as a parameter
};

class Account : public I_Printable
{
public:
	virtual void withdraw(unsigned int amount) { std::cout << "witdrawing from Account\n"; }
	virtual void print(std::ostream& os) const { std::cout << "display Account\n"; }
	virtual ~Account() {}

};

class CheckingAccount :public Account
{
public:
	virtual void withdraw(unsigned int amount) override { std::cout << "witdrawing from CheckingAccount\n"; }
	virtual void print(std::ostream& os) const { std::cout << "display CheckingAccount\n"; }
	virtual ~CheckingAccount() {}

};

class SavingAccount :public Account
{
public:
	virtual void withdraw(unsigned int amount) override { std::cout << "witdrawing from SavingAccount\n"; }
	virtual void print(std::ostream& os) const { std::cout << "display SavingAccount\n"; }
	virtual ~SavingAccount() {}

};

class TrustAccount :public Account
{
	friend std::ostream& operator<<(std::ostream& os, TrustAccount const& rhs) { return os << "displaying TrustAccount\n"; }
public:
	virtual void withdraw(unsigned int amount) override { std::cout << "witdrawing from TrustAccount\n"; }
	virtual void print(std::ostream& os) const { std::cout << "display trustAccount\n"; }
	virtual ~TrustAccount() {}
};



// now i can use this interface with whatever class i want
// all i need to do is 
// 1) inherit i
// 2) implement the pure virtual function

class Whatever : public I_Printable
{
public:
	virtual void print(std::ostream& os) const { std::cout << "displaying whatever\n"; }

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

	std::cout << "\n-------------------------------------\n";

	Whatever x;
	std::cout << x;
	return 0;
}

