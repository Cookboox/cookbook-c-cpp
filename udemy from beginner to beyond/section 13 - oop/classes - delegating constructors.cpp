#include<iostream>
#include<string>



class Player 
{
private:
	std::string name;
	int health;
	int xp;

public:
	
	Player(std::string n_val, int h_val, int xp_val);
	Player(std::string n_val);
	Player();

};


Player::Player(std::string n_val)
	: Player{n_val, 0, 0} //delegating to 3 args constructor with these values
{
	std::cout << "1 args constructor" << "\n";
}

Player::Player() 
	: Player{"none", 0, 0}//delegating to 3 args constructor with these values
{
	std::cout << "0 args constructor" << "\n";
}


Player::Player(std::string n_val, int h_val, int xp_val)
	: name{ n_val }, health{ h_val }, xp(xp_val)
{
	std::cout << "3 args constructor" << "\n";
}

int main()
{
	Player frank;
	Player hero("Hero");
	Player morfus("Morfeus", 100, 12);

	Player *enemy = new Player{ "Enemy", 1000,0 };

	return 0;
}

