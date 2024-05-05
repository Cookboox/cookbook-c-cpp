#include<iostream>
#include<string>



class Player
{
private:
	std::string name;
	int health;
	int xp;

public:
	//inline defualt constructor
	Player(std::string n_val = "None", int h_val = 0, int xp_val = 0) : name{ n_val }, health{ h_val }, xp(xp_val)
	{
		std::cout << "3 args defualt constructor" << "\n";
	}
};


int main()
{
	Player frank;
	Player hero("Hero");
	Player seri{ "Seri", 99, };
	Player morfus("Morfeus", 100, 12);
	
	Player *enemy = new Player{ "Enemy", 1000, 0 };

	return 0;
}

