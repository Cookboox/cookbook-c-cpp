#include <iostream>
#include <vector>
#include <string>
// the goal of a class is to provide easy to use public interface (to a programmer who will use the class)

class Player
{
	//data
	std::string name; // in c++ 11 i can inicialize data on the level of class
	int health;
	int xp;

	//methods
	void talk(std::string);
	bool is_dead();
};



int main()
{
	//creating objects on the stack
	Player hero;
	Player dan;
	
	//creating an array of Player objects
	Player player_arr[]{ hero, dan };

	//creating vector of Players
	std::vector<Player> player_vec {hero};
	player_vec.push_back(dan);




	//creating objects on the heap
	Player* enemy{ nullptr };
	enemy = new Player;

	Player* stranger = new Player;

	//creating an array of Player objects
	//Player players2[]{ hero, dean, enemy }; // enemy is a pointer and not a Player object --> cannot be with the same array --> how to add it?? cast??


	

	delete enemy;
	delete stranger;

	return 0;
}