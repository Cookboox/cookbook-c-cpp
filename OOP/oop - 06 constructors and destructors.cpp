#include <iostream>
#include <string>

class Player
{
private:
	std::string name;
	int health;
	int xp;
public:
	//overloaded constructors (all defined inline)
	Player() { this->name = "noname"; this->health = 0; this->xp = 0; }
	Player(std::string name) { this->name = name; this->health = 0; this->xp = 0; }
	Player(std::string name, int health) { this->name = name; this->health = health; this->xp = 0; }
	Player(std::string name, int health, int xp) { this->name = name; this->health = health; this->xp = xp; }

	//destructor cant be overloaded, cant take any params (defined inline)
	~Player() { std::cout << "destructor for " << this->name << " " << this->health << " " << this->xp << "\n"; };
};



int main()
{
	Player no_args;
	Player brian("brian");
	Player charlie("charlie", 10);
	Player dave("dave", 200, 99);

	{
		Player in_curly("in_curly", 33, 444);
	}

	if (true)
	{
		Player in_if("in_if");
	}

	for (int i = 0; i < 5; ++i)
	{
		Player in_for("in_for", i, i*i);
	}


	Player* on_heap = new Player("on_heap", 99, 999);
	Player* leak = new Player("leak");

	delete on_heap;


	return 0;
}