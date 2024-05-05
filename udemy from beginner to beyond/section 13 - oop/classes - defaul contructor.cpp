#include<iostream>
#include<string>

class Player
{
private:
	std::string name;
	int health;
	int xp;

public:
	void set_name(std::string n)
	{
		name = n;
	}
	std::string get_name()
	{
		return name;
	}

	//contructors
	Player()
	{
		name = "none";	
		health = 100;
		xp = 12;
		
	}
	Player(std::string n_val, int h_val, int xp_val)
	{
		name = n_val;
		health = h_val;
		xp = xp_val;
	}



};









int main()
{
	Player frank;
	frank.set_name("Frankie");
	std::cout << frank.get_name() << "\n";

	Player Hero{ "Hero", 100, 9 };



	Player *enemy = new Player{ "Enemy", 1000, 125 };
	std::cout << enemy->get_name() << "\n";






	return 0;
}
