#include <iostream>
#include <string>

//private -- only the members of the class can access it
//protected -- quite the same except for inheritance
//public -- accesible outside


class Player
{
private:
	std::string name;
	int health;
	int xp;

public:
	void talk(std::string text) { std::cout << this->name << " says " << text; }
};


int main()
{
	Player dan;
	dan.name = "Dan"; //innacessible toset!!
	std::cout << dan.name; // innacessible to get!!


	return 0;
}