#include <iostream>
#include <string>

//all your getters should be const

class Player
{
private:
	std::string name;
	int health;
public:
	int xp;

	Player(std::string name = " ", int health = 0, int xp = 0) : name{ name }, health{ health }, xp{ xp } { std::cout << "normal constructor\n"; }
	Player(Player const& source) : name{ source.name }, health{ source.health }, xp{ source.xp } { std::cout << "copy constructor\n"; }
	~Player() { std::cout << "destructor\n"; }

	std::string get_name() { return this->name; } //this should be const
	void set_name(std::string name) { this->name = name; }

	int get_health() const { return this->health; } 
	void set_health(int health)  { this->health = health; }
};



int main()
{
	const Player hero("hero", 100, 999);
	Player hero_copy{ hero };

	//non of them will compile since they are const
	//hero.xp = 1;
	//copy_hero.xp = 1;
	
	//not even with a class´s function can be modified because te method is noncost, and i am passing a const
	//hero.set_name("superhero");
	//copy_hero.set_name("superman");

	//moreover i cant even read the value for the same reason
	//hero.get_name();
	//hero_copy.get_name();

	//get health is const method in declaration so i can use it on const objects
	hero.get_health();

	return 0;
}