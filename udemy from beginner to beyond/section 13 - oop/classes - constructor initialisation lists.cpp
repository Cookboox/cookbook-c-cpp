#include<iostream>
#include<string>

class Player
{
private:
	std::string name;
	int health;
	int xp;

public:
	void set_name(std::string n_val) { name = n_val; }
	std::string get_name() { return name; }


	//Signatury construktoru - defined vne classy
	Player();
	Player(std::string n_val);
	Player(std::string name_val, int health_val, int xp_val);

};


//Constructors - the old way
//Player::Player() 
//{
//	name = "none";
//	health = 0;
//	xp = 0;
//}
//
//Player::Player(std::string n_val) 
//{
//	name = n_val;
//	health = 0;
//	xp = 0;
//}
//
//Player::Player(std::string name_val, int health_val, int xp_val) 
//{
//	name = name_val;
//	health = health_val;
//	xp = xp_val;
//}



//constructors - the new way using initialization list 

Player::Player() 
	: name{ "NONE" }, health{ 100 }, xp{ 12 } {};

Player::Player(std::string name_val) 
	: name(name_val), health(100), xp(12) {};

Player::Player(std::string name_val, int health_val, int xp_val) 
	: name(name_val), health(health_val), xp(xp_val) {};



int main()
{
	Player empty;
	Player frank{ "Frankie" };
	Player villian{ "Vilda", 100, 12 };




	return 0;
}

