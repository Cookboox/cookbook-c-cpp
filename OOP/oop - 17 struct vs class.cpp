#include <iostream>
#include <string>

//members in struct are public by default, in class they are private by default - thats all!

class PlayerClass
{
	std::string name;
	void set_name(std::string name) { this->name = name; }
};

struct PlayerStruct
{
// private: // i can definatelly modify this behaviour
	std::string name;
	void set_name(std::string name) { this->name = name; }

public:
	//whatever, even very complex logic..
};



int main()
{
	PlayerClass one;
	//one.set_name("hero"); //error - inaccesible

	PlayerStruct two;
	two.set_name("markus");


	return 0;
}