#include <iostream>
#include <string>

//three types of methods  implementation
// 1) inline directly in the class
// 2) outside the class in the same file
// 3) oustide the class in a separate file (.h file for declaration .cpp file for implementation)

class Account
{
private:
	std::string name;
	double ballance = 0;

public:
	double get_ballance() { return this->ballance; }; // 1) inline implementation
	void deposit(double amount); 
	void withdraw(double amount);

};

// 2) oustide the class in the same file
void Account::deposit(double amount) { this->ballance += amount; }
void Account::withdraw(double amount) { this-> ballance -= amount; }

int main()
{
	Account my_account;

	std::cout << my_account.get_ballance() << "\n";

	my_account.deposit(1000);
	std::cout << my_account.get_ballance() << "\n";

	my_account.withdraw(300);
	std::cout << my_account.get_ballance() << "\n";

	return 0;
}