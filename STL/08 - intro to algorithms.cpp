#include <iostream>
#include <algorithm>
#include <vector>

//stl algorithms work on sequence of elements provided them by an iterator
//many algorithms require extra information in order to do their work, it can be passed via:
//1) function pointer
//2) function object
//3) lambda expresion (preferable)

//all STL algorithms expect iterators as arguments determining the sequence obtained from the container

//BEWARE of iterator invalidation
//-it is possible that an iterator becomes invalid during processing
//-for exaple clear() during processing a contianer will make iterators pointing to invalid locations
//every STL container has a documentations saying when an iterator gets invalid

//THE PATTERN:
//std::name_of_algorithm(name_of_container.begin(), name_of_container.end(), possibly_some_other_parameter)

//REMEMBER:
//in order to use algorithm with custom data types, the operators < and  == must be overloaded

class Player
{
private:
	int health;
	std::string name;
public:
	Player(int health, std::string name) : health{health}, name{name} {}
	~Player() = default;
	//bool operator<(Player const& other) { return this->health < other.health; }
	bool operator==(Player const& other) const noexcept { return (this->health == other.health && this->name == other.name); } //this is needed for find algorithm
};

void find_player(Player &&p)
{
	std::vector<Player> vp{ Player{10, "mike"}, Player{20, "paul"}, Player{12, "adam"} };
	auto it = std::find(vp.begin(), vp.end(), p);

	if (it != vp.end())
		std::cout << "element found" << "\n";
	else
		std::cout << "element not found" << "\n";
}

void find_int(int &&value)
{
	std::vector<int> v{ 10,20,30,40,50 };
	auto it = std::find(v.begin(), v.end(), value);

	if (it != v.end())
		std::cout << "element found" << "\n";
	else
		std::cout << "element not found" << "\n";
}

template<typename T>
void find_it(T&& value , std::vector<T> const &v)
{
	auto it = std::find(v.begin(), v.end(), value);

	if (it != v.end())
		std::cout << "element found" << "\n";
	else
		std::cout << "element not found" << "\n";
}


//if an algorithm needs extra param as a function , it can be done in three ways
//1) functor

class Square
{
public:
	void operator()(int a) { std::cout << a * a <<"\n"; }
};

Square square;

//2) function pointer
void square_function(int a) { std::cout << a * a << "\n"; }

int main()
{
	find_int(21);
	find_player(Player{ 10, "mike" });

	std::cout << "\n----------using template function-----------------\n";
	std::vector<int> v{ 10,20,30,40,50 };
	std::vector<Player> vp{ Player{10, "mike"}, Player{20, "paul"}, Player{12, "adam"} };
	find_it(21, v);
	find_it(Player{ 10, "mike" }, vp);

	std::cout << "\n----------using functor-----------------\n";
	for_each(v.begin(), v.end(), square);
	std::cout << "\n----------using function ptr-----------------\n";
	for_each(v.begin(), v.end(), square_function);
	std::cout << "\n----------using lambda-----------------\n";
	for_each(v.begin(), v.end(), [](int a) { std::cout << a * a << "\n"; });


	return 0;
}