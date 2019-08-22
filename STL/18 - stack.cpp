#include <iostream>
#include <stack>
#include <deque>
#include <list>
#include <vector>

//LIFO data structure, stack of books
//container adapter --> implemeted in already existing container
//all the operation happens at the back only (at the top), underlying container is that one having back (list, deque, vector)
//no iterators or algorithms supported

//METHODS:
// - push - insert an element at the top
// - pop - removes the elements from the top
// - top - access the top by reference
// - empty/size


std::stack<int> s;
std::stack<int, std::deque<int>> sd; //default
std::stack<int, std::vector<int>> sv;
std::stack<int, std::list<int>> sl;

//destructive iteration --> no reference
template<typename T>
void display(std::stack<T> s)
{
	std::cout << "[ ";
	while (!s.empty())
	{
		std::cout << s.top() << " ";
		s.pop();
	}
	std::cout << "]\n";
}

int main()
{
	for (int i : {1, 2, 3, 4, 5}) s.push(i);
	display(s);

	std::cout << s.top();

	s.push(100);
	s.push(100);
	display(s);

	s.pop();
	s.pop();
	display(s);

	return 0;
}