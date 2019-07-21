#include <iostream>
#include <string>
#include <vector>

// two ways to acces
// 1) using .	(if we have an object)
// 2) using ->	(if we have a pointer to an object)
 
class Player
{
public:
	std::string name;
	int health;
	int xp;

	void talk(std::string text)
	{
		std::cout << this->name << " says " << text << "\n";
	}
	bool is_dead()
	{
		if (this->health <= 0) 
			return true;
		return false;
	};
};



int main()
{
	//stack
	Player dan; 

	dan.name = "Dan";
	dan.health = 100;
	dan.xp = 10;
	
	std::cout << dan.health << "\n";
	
	dan.talk("hello");
	std::cout << std::boolalpha << dan.is_dead() << "\n";
	


	//heap
	Player* enemy = new Player;
	enemy->name = "Enemy";
	enemy->health = 300;
	enemy->xp = 100;

	std::cout << enemy->health << "\n";
	
	enemy->talk("I will kill you!");

	delete enemy;



	return 0;
}