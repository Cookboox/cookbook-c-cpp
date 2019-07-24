#include <iostream>
#include <string>

//static means a function or a data belongs to all the class, not the instance. usefull for creating class wide information (counters, ids etc.)

class Player
{
private:
	std::string name;
	int health;
	int xp;
	static int number_of_players; //can i initialize here?

public:
	Player(std::string name = " ", int health = 0, int xp = 0) : name{ name }, health{ health }, xp{ xp }
	{
		std::cout << "constructing a player " << this->name << "\n";
		++number_of_players;
	}

	Player(Player const& source) : name{ source.name }, health{ source.health }, xp{ source.xp }
	{
		std::cout << "copying a player " << this->name << "\n";
		++number_of_players;
	}

	~Player() 
	{
		std::cout << "destructing a player " << this->name << "\n";
		--number_of_players;
	}

	static int get_number_of_players() { return number_of_players; }
};

//this must be outside class - typically in .cpp where i define member functions
int Player::number_of_players = 0;

int main()
{
	Player one("one", 1, 1);
	Player copy_one{ one };
	std::cout << Player::get_number_of_players() << "\n"; //the static function is called upon a class, not upon a object 
	
	Player two("two", 2);
	std::cout << Player::get_number_of_players() << "\n";

	{
		Player copy_two(two);
		std::cout << Player::get_number_of_players() << "\n";
	}

	Player* heap = new Player("heap", 99, 999);
	std::cout << Player::get_number_of_players() << "\n";
	
	delete heap;
	   
	return 0;
}