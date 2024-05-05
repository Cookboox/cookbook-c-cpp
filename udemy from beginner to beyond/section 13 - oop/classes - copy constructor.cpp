#include<iostream>
#include<string>

class Player
{
private:
	std::string name;
	int health;
	int xp;

public:
	std::string get_name() { return name; }
	int get_health() { return health; }
	int get_xp() { return xp; };
	//constructor signature
	Player(std::string name_val = "none", int health_val = 0, int xp_val = 0);
	//copy constructor signature
	Player(const Player &source);
	//destructor - inline definition
	~Player() { std::cout << "destructor called for " << name << "\n"; };
};

//implementing constructor
Player::Player(std::string name_val, int health_val, int xp_val) : name{ name_val }, health{ health_val }, xp{ xp_val }
{
	std::cout << "three args constructor for " << name << "\n";
}

//impleenting copy constructor
Player::Player(const Player &source) : name{ source.name }, health{ source.health }, xp{ source.xp }
{
	std::cout << "copy constructor called for " << source.name << "\n";
}

void display_player(Player p)
{
	std::cout << "name: " << p.get_name();
	std::cout << "health: " << p.get_health();
	std::cout << "xp: " << p.get_xp();
	
	return;
}

int main()
{
	Player empty;

	display_player(empty);

	Player frank{ "Frankie", 999, 999 };
	Player another_frank{ frank };
	Player hero{ "Hero", 100 };
	Player vilain{ "Vilain", 100, 10 };

	return 0;
}
