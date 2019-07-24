#include <iostream>
#include <string>

// move constructor fo a class looks similar like copy constructor, but there is no const and we use &&. 
// there cannot be const because we null-out the pointer of the source object
// what move constructor actually does is that it steals the data from the source and null-out source´s pointer - that is all!!
// so it basicaly like a shallow copy except it nulls out the source pointer - that is all!

// general signature
// T::T(T &&source) { }
// 
// Player::Player(Player &&source) { }
// Account::Account(Account &&source) { }

class Move
{
private:
	int* ptr;
public:
	//normal constructor
	Move(int number) : ptr{ new int(number) }
	{
		std::cout << "constructing, allocating data: " << *this->ptr << " at address: " << this->ptr << "\n";
	}
	////copy constructor (shallow copy)
	//Move(Move const& source) : ptr{ source.ptr }
	//{
	//	std::cout << "copying object, data: " << *this->ptr << " at address: " << this->ptr << "\n";
	//}
	//move constructor (very similar to shallow copy, just nulling out source´s pointer
	Move(Move&& source) : ptr{ source.ptr }
	{
		source.ptr = nullptr;
		std::cout << "object moved, data: " << *this->ptr << " at address: " << this->ptr << "\n";
	}
	//destructor
	~Move()
	{
		if (this->ptr == nullptr) { std::cout << "object destroyed, nullptr freed\n"; }
		else { std::cout << "object destroyed " << *this->ptr << " dealocated\n"; }
	}
};


#include <vector>
int main()
{
	std::vector<Move> m;

	for (int i =1; i < 10; ++i)
	{
		m.push_back(Move{ i });
	}
	return 0;
}