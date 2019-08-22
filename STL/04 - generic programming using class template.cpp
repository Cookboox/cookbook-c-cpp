#include <iostream>
#include <string>
#include <vector>

//std::vector is a generic class template
//template clsses are typically completelly contianed in header files,
//so we would have the template class in Item.h and NO CPP Item.cpp file associated with it
//-->it makes sense because it is a blueprint
//model class holding an item name and value(that can be any numeric value)

template<typename T>
class Item
{
private:
	char const* name;
	T value;
public:
	Item(char const* name, T value) :name{ name }, value{ value } {}
	~Item() = default;
	char const* get_name() const { return this->name; }
	T get_value() const { return this->value; }
};

template<typename T1, typename T2>
struct Pair
{
	T1 first;
	T2 second;
};




int main()
{
	Item<int> one{ "One", 1 }; // i need to provide the <T>
	std::cout << one.get_name() << " - " << one.get_value() << "\n";

	Item<std::string> two{ "Two", "some string..." };
	std::cout << two.get_name() << " - " << two.get_value() << "\n";

	Item<Pair<int, int>> three{ "Three", {1,1} };
	std::cout << three.get_name() << " - " << three.get_value().first << " - " << three.get_value().first << "\n";

	std::cout << "\n--------------------------------\n";

	Pair<int, std::string> first{ 1, "hello" };
	Pair<int, std::string> second{ 2, "hi" };
	Pair<int, std::string> third{3, "buenos dias" };
	std::vector<Pair<int, std::string>> v;
	v.push_back(first);
	v.push_back(second);
	v.push_back(third);

	for (const auto& i : v) std::cout << i.first<< " " << i.second <<"\n";

	return 0;
}