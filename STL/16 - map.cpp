#include <iostream>
#include <map>
#include <unordered_map>
#include <set>

//fast retrieval based on key
//stored as std::pair<T,U>;
//no concept of front, back
//default sortin by key. how to sort a map based on values?

//KEY METHODS:
//m.insert()
//m.erase()
//m.find(key)
//m.erase(it)

template<typename T, typename U>
void display(std::map<T, U> const& m)
{
	std::cout << "[ ";
	for (auto const& i : m) 
		std::cout << i.first << ":" << i.second << " ";
	std::cout << "]\n";
}

//common methods
void foo()
{
	std::map<std::string, int> m{ {"paul",10},{"mike",23},{"fero",29} };
	display(m);//default display based on keys

	//3 ways to insert

	//using std::pair
	std::pair<std::string, int> p{ "mario", 76 };
	m.insert(p);
	display(m);

	//using std::make_pair
	m.insert(std::make_pair("richard", 32));
	display(m);

	//using subscript
	m["ayse"] = 36;
	display(m);

	//modify a value using subscript
	m["ayse"] = 45;
	display(m);

	//similarly using a method
	m.insert_or_assign("ayse", 38); //returs std::pait<it,bool>
	display(m);

	m.insert_or_assign("amelie", 34);
	display(m);

	for (auto& i : m)
		if (i.first.at(0) == 'a')
			i.second = 0;
		else
			i.second = 999;
	display(m);
	
	//extract is the only way to change a key of a map element without reallocation:
	auto x = m.extract("ayse");
	x.key() = "ayshwaria";
	m.insert(std::move(x));
	display(m);

}

void display(std::map<std::string, std::set<int>> const& m)
{
	std::cout << "[ ";
	for (auto const &i : m)
	{
		std::cout << i.first << ":[ ";
		for (auto const &j : i.second)
			std::cout << j << " ";			
		std::cout << "]  ";
	}		
	std::cout << "]\n";
}

//nested structures
void foo2()
{
	std::map<std::string, std::set<int>> m{ {"mike", {30,40,58}},
											{"luke", {59, 43, 32}},
											{"steve", {45, 32,58}} };
	display(m);

	m.at("mike").insert(99);
	display(m);
	
	m["mike"].erase(99);
	display(m);

	std::pair<std::string, std::set<int>> p{ "vardan", {99, 93, 92} };
	m.insert(p);
	display(m);

	auto it = m.find("vardan");
	if (it != m.end())
		it->second.insert(100);
	display(m);

	m.clear();
	display(m);
}

int main()
{
	//foo();
	foo2();

	return 0;
};