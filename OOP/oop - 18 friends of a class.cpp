#include <iostream>
#include <string>

//friends are functions of objects having access to all (even private) data of a class, while being defined outside of the class itself

// ---RULES---
//friendship must be granted NOT taken, declared explicitly in the class granting friendship
//friendship is not symetric, A friend to B doesnt imply B friend to A
//friendship is not transitive, A friend to B and B friend to C does not imply A is freind to C 
//friendship is not inherited

class Player 
{
private:
	std::string name;
	int health;
	int xp;
	friend void display_player_details(Player& p); //grantig friendship to the function that does not belong to the class itsel 
	friend void OtherClass::do_something(Player& p); //granting access to other class method
	friend class YetAnotherClass; //granting access to a whole new class
public:
	//.
};

class OtherClass
{
	void do_something(Player &p) //this function of different class has full access to Players private members
	{
		//..
	}
};

void display_player_details(Player& p) //this function has direct access to every member, even private

{
	std::cout << p.name << ", " << p.health << ", " << p.xp << "\n";
}

int main()
{
	Player one;
	display_player_details(one);


	return 0;
}