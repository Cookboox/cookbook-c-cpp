#include<iostream>
#include<vector>
#include<string>

class Player
{
	//attributes
	std::string name{ "Player" };
	int health{ 100 };
	int xp{ 3 };

	//methods
	void talk(std::string);
	bool is_dead();
};

class Account
{
	//attr
	std::string name{"Account"};
	double balance{0.0};

	//method
	bool deposit(double);
	bool withdraw(double);

};












int main()
{
	//on the stack
	Player frank;
	Player hero;
	
	//on the heap
	Player *enemy{ nullptr };
	enemy = new Player;	
		
	Player players[]{ frank, hero, *enemy };

	std::vector<Player> player_vec{ frank };
	player_vec.push_back(hero);

	delete enemy;



	Account frank_account;
	Account jim_account;








    return 0;
}