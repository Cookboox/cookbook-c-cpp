#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>


//double ended queue, expands and contracts as needed
//deque is NOT stored in contiguous memory --> something like a linked list of vectors
//random access in constant time
//insertion and deletion at the front AND the back in constant time
//insertion elswhere in linear time
//all iterators available and may invalidate

//KEYMETHODS:
//push_back, push_front
//emplace_back, emplace_front
//pop_back, pop_front

//WHEN TO USE?
//when u need to insert either at the back or front, not in the middle

template<typename T>
void display(std::deque<T> const & d)
{
	std::cout << "[ ";
	for (auto const& i : d) std::cout << i << " ";
	std::cout << "]\n";
}

//push_back/front, pop_back/front
void foo1()
{
	std::deque<int> d{ 1,2,3,4,5 };
	display(d);

	for (int i = 0; i > -4; --i) d.push_front(i);
	display(d);

	for (int i = 6; i < 10; ++i) d.push_back(i);
	display(d);

	for (int i = 0; i < 4; ++i) d.pop_front();
	display(d);

	size_t size = d.size();
	size_t halfsize = d.size() / 2;

	for (size_t i = size; i > halfsize; --i) d.pop_back();
	display(d);
}

//push vs emplace
void foo2()
{
	std::vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };
	std::deque<int> fd{};
	std::deque<int> bd{};

	std::cout << "------push----------------------\n";
	for (auto const& i : v) fd.push_front(i);
	display(fd);

	for (auto const& i : v) bd.push_back(i);
	display(bd);

	bd.clear();
	fd.clear();

	std::cout << "------emplace----------------------\n";
	for (auto const& i : v) fd.emplace_front(i);
	display(fd);
	
	for (auto const& i : v) bd.emplace_back(i);
	display(bd);
}

//size, resize, erase
void foo3()
{
	std::deque<int> d{ 1,2,3,4,5,6,7,8 };
	
	std::cout << d.size() << "\n";
	d.resize(99);
	std::cout << d.size() << "\n";
	display(d);
	
	d.resize(10);
	std::cout << d.size() << "\n";
	display(d);

	d.erase(d.begin() + 1, d.begin() + 4);
	display(d);
}

int main()
{
	//foo1();
	//foo2();
	foo3();

	return 0;
}