#include<iostream>
#include<string>

class Player
{
private:
	std::string name;
	int healt;
	int xp;

public:
	void set_name(std::string x) { name = x; }
	std::string get_name() { return name; }

	//contructors - overloaded
	Player() { std::cout << "no args constructor " << "\n"; };
	Player(std::string name, int health, int xp) { std::cout << "three args constructor " << "\n"; };
	Player(std::string name, int xp) { std::cout << "two arg contructor for " < "\n"; };
	Player(std::string name) { std::cout << "two arg contructor for " << "\n"; };

	//destructor
	~Player() { std::cout << "destructor for " << name << " called" << "\n"; };
};  

int main()
{
	{
		Player zeal; //using no args constructor
		zeal.set_name("Zeal");
	}

	{
		Player morfeus("Morfeus", 100, 25);
		morfeus.set_name("Morfeus");


		Player viliar("Villiar", 12);
		viliar.set_name("villiar");	
		
		Player hero("Hero");
		hero.set_name("Hero");
	}

	Player *enemy = new Player();
	enemy->set_name("Enemy");

	Player *big_boss = new Player();
	big_boss->set_name("Big Boss");

	delete enemy;
	delete big_boss;

	return 0;
}
