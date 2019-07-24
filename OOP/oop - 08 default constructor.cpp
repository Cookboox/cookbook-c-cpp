#include <iostream>
#include <string>


class Player
{
private:
	std::string name;
	int health;
	int xp;
public:

	// previous bad style way - this is not technically inicialization
	Player() 
	{
		//body of the function
		this->name = "no name";	this->health = 0; this->xp = 0;
	}

	//// good way - evrything after : is real initialization list
	//Player() : name{ "no name" }, health{ 0 }, xp { 0 }
	//{
	//	//body of the function
	//}
};

int main()
{

	Player dan;

	return 0;
}