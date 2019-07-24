#include <iostream>
#include <string>

class Player
{
private:
	std::string name;
	int health;
	int xp;
public:
	////overloading constructors
	//Player() : name{ " " }, health{ 0 }, xp{ 0 } {}
	//Player(std::string name) : name{ name }, health{ 0 }, xp{ 0 } {}
	//Player(std::string name, int health) : name{ name }, health{ health }, xp{ 0 } {}
	//Player(std::string name, int health, int xp) : name{ name }, health{ health }, xp{ xp } {}

	//better way to use delegation
	Player(std::string name, int health, int xp) : name{ name }, health{ health }, xp{ xp } { std::cout << "3 args\n"; } //everything will be delegated to this three args constructor

	Player() : Player(" ", 0, 0) { std::cout << "0 args\n"; } // zero arg constructor delegates to the three args constructor
	Player(std::string name) : Player{ name, 0, 0 } { std::cout << "1 arg\n"; } //one arg constructor
	Player(std::string name, int health) : Player{ name, health, 0 } { std::cout << "2 args\n"; } //two args constructor
};



int main()
{
	Player zero;
	Player one("one");
	Player two("two", 2);
	Player three("three", 3, 3);


	return 0;
}