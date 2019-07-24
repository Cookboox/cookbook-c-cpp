#include <iostream>
#include <string>

// use cases for copying an object
// 1) passing into a function by value
// 2) returning from a function by value
// 3) copying one object to construct a new one

// if no copyconstructor is provided, C++ will generate a default one that will do memberwise copy
// - all the members will be copied into the target object
// - pointers will be copied, but the data that pointer points to will be NOT (shallow copy)
   
// best practises:
// - always use your own copy constructor if you use raw pointers (if u use smart pointers it is not needed)
// - always use const ref
// - use STL data members where possible - they have their copy constructors

//general signature:
//T::T(T const& source)
//
//examples:
//Player::Player(Player const& source)
//Account::Account(Account const& soure)

class Player
{
private:
	std::string name;
	int health;
	int xp;
public:
	// normal constructor with default values
	Player(std::string name = " ", int health = 0, int xp = 0) : name{ name }, health{ health }, xp{ xp }
	{
		std::cout << "normal constructor for: " << this->name << "\n";
	}
	// copy constructor
	Player(Player const& source) : name{ source.name }, health{ source.health }, xp{ source.xp }
	{
		std::cout << "copy constructor for: " << this->name << "\n";
	}
	//copy constructor can also use delegation
	Player(Player const& source) : Player { source.name, source.health, source.xp } // delegating to make a copy to normal constructor
	{
		std::cout << "copy constructor for: " << this->name << "\n";
	}
	// destructor
	~Player() {	std::cout << "destructor for: " << this->name << "\n"; }
};

void do_something(Player p)
{
	// some work with p
}

Player make_player()
{
	Player pepa("pepa", 10, 20);
	return pepa;
}

int main()
{
	//Player one("one");
	//Player copy_one{ one };

	//Player two("two", 2);
	//Player copy_two{ two };

	//Player three("three", 3, 3);
	//do_something(three); // here also copy constructor will be called
	
	Player pepa = make_player();



	return 0;
}