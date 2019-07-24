#include <iostream>
#include <string>


class Player
{
private:
	std::string name;
	int health;
	int xp;
public:
	//previous bad style way - this is not technically inicialization
	//Player()
	//{
	//	//body of the function
	//	this->name = "no name";	
	//	this->health = 0; 
	//	this->xp = 0;
	//}

	// good way - evrything after : is real initialization list
	Player() : name{ "no name" }, health{ 0 }, xp { 0 } { }

	Player(std::string name) :name(name), health{ 0 }, xp{ 0 } { }
	Player(std::string name, int health) :name(name), health{ health }, xp{ 0 } { }
	Player(std::string name, int health, int xp) :name(name), health{ health }, xp{ xp } { }
};

int main()
{

	Player no_arg;
	Player one("one");
	Player two("two", 2);
	Player three("three", 3, 3);
	return 0;
}