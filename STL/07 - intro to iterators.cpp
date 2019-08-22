#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <map>
#include <deque>

//itertors allow to abstract containers as a sequence of elements (even tought they are not sequential)
//they are object working as pointers by design
//most container classes can be traversed by iterators (except stack, queue, prior_queue)
//implemented as template classes 

//SYNTAX:
//continer_type::iterator_type iterator_name
//std::vector<int>::iterator it; 
//std::map<double, std::string>::iterator it;
//std::set<char>::iterator it;

//TYPES OF ITERATORS:
//begin(), end() --> returns iterator
//cbegin(), cend() --> returns const_iterator (read only access)
//rbegin(), rend() --> returns reverse_iterator (moving from back to front)
//crbegin(), crend() --> returns const_reverse_iterator 

//MOST IMPORTANT:
//container_name.begin(), container_name.end() 

void display_using_while()
{
	//typical usecase: iteration over different containers
	std::vector<int> v{ 1,2,3,4 };
	std::list<int> l{ 11,22,33,44 };
	std::set<int> s{ 111,222,333,444 };
	std::deque<int> d{ 1111,2222,3333,4444 };
	std::map<char, int>	m{ { 'A', 100}, {'B', 200},  {'C',300} };

	std::cout << "\n----------vector displaying----------------\n";
	auto itv = v.begin();
	while (itv != v.end())
	{
		std::cout << *itv << "\n";
		++itv;
	}

	std::cout << "\n----------list displaying----------------\n";
	auto itl = l.begin();
	while (itl != l.end())
	{
		std::cout << *itl << "\n";
		++itl;
	}

	std::cout << "\n----------set displaying----------------\n";
	auto its = s.begin();
	while (its != s.end())
	{
		std::cout << *its << "\n";
		++its;
	}

	std::cout << "\n----------deque displaying----------------\n";
	auto itd = d.begin();
	while (itd != d.end())
	{
		std::cout << *itd << "\n";
		++itd;
	}

	std::cout << "\n----------map displaying----------------\n";
	auto itm = m.begin();
	while (itm != m.end())
	{
		std::cout << itm->first << " - " << itm->second << "\n";
		++itm;
	}
	//the pattern is all the time the same except for the map where first, second pointer access atributes is use
}

void display_using_range_for()
{
	//typical usecase: iteration over different containers, here using range for which is imlemented through iterators
	std::vector<int> v{ 1,2,3,4 };
	std::list<int> l{ 11,22,33,44 };
	std::set<int> s{ 111,222,333,444 };
	std::deque<int> d{ 1111,2222,3333,4444 };
	std::map<char, int>	m{ { 'A', 100}, {'B', 200},  {'C',300} };

	std::cout << "\n----------vector displaying----------------\n";
	for (auto i : v) std::cout << i << "\n";

	std::cout << "\n----------list displaying----------------\n";
	for (auto i : l) std::cout << i << "\n";
	
	std::cout << "\n----------set displaying----------------\n";
	for (auto i : s) std::cout << i << "\n";
	
	std::cout << "\n----------deque displaying----------------\n";
	for (auto i : d) std::cout << i << "\n";
	
	std::cout << "\n----------map displaying----------------\n";
	for (auto i : m) std::cout << i.first << " - " << i.second << "\n";
	
	//the pattern is all the time the same except for the map where first, second pointer access atributes is used
}



int main()
{
	display_using_while();
	display_using_range_for();
	
	return 0;
}