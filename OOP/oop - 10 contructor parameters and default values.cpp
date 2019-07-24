#include <iostream>
#include <string>

//instsead of having overloaded constructor and delagation it is sometimes handy to use default params for constructor
//works the same way as default params in functions

class Player
{
private:
	std::string name;
	int health;
	int xp;

public:
	Player(std::string name = "none", int health = 0, int xp = 0) : name{name}, health{health}, xp{xp} 
	{ 
		std::cout << "3 args constructor called for name: " << this->name << " health " << this->health << " xp " << this->xp << "\n";
	}
};


int main()
{
	Player zero;
	Player one("One");
	Player two("Two", 2);
	Player three("Three", 3, 3);





	return 0;
}