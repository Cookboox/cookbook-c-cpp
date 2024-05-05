#include<iostream>
#include<vector>
#include<string>

class Player
{
public:
	//attributes
	std::string name;
	int health;
	int xp;

	//methods
	void talk(std::string txt) { std::cout << name << " says " << txt << "\n"; };
	bool is_dead();
};

class Account
{
public:
	//attr
	std::string name;
	double balance;

	//method
	bool deposit(double x) 
	{
		balance += x; 
		std::cout << name << " deposits " << x << "\n";
		return true;
	};

	bool withdraw(double x)
	{
		balance -= x;
		std::cout << name << " withdraws " << x << "\n";
		return true;
	}
};



int main()
{
	//on the stack
	Player frank;
	frank.name = "Frank";
	frank.health = 100;
	frank.xp = 12;
	frank.talk("hi there");

	//on the heap enemy IS NOT an object, it is a POINTER to the object
	Player *enemy = new Player;
	(*enemy).name = "Enemy"; //first dereference the pointer to GET THE OBJECT and then access with . operator
	(*enemy).health = 999;
	enemy->xp = 99;
	enemy->talk("I WILL KILL U");





	Account frank_acc;
	frank_acc.balance = 5000.0;
	frank_acc.name = "Franks account";
	frank_acc.deposit(1000);
	frank_acc.withdraw(500);

	Account *jim_account = new Account;
	jim_account->name = "Jims account";
	jim_account->balance = 0.00;
	jim_account->deposit(100);
	jim_account->deposit(200);
	jim_account->withdraw(45);
	

	return 0;

}
