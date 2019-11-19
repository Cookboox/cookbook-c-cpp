#include <iostream>
#include <map>

struct A
{
	double age;

	A() 
	{
		std::cout << "Default constructor\n";
	}

	A(double x) : age(x)
	{
		std::cout << "Double constructor taking " << x << "\n";
	}

	A(A const& a) : age(a.age) 
	{
		std::cout << "Copy constructor\n";
	}

	A(A && a) noexcept : age(std::move(a.age)) 
	{
		std::cout << "Move constructor\n";
	}

	A& operator=(A const& a)
	{
		std::cout << "Copy assign\n";
		age = a.age;
		return *this;
	}

	A& operator=(A && a) noexcept 
	{
		std::cout << "Move assign\n";
		age = std::move(a.age);
		return *this;
	}

	~A() noexcept 
	{
		std::cout << "Destructor\n";
	}
};

void fillMapIntDouble()
{
	typedef std::map<int, double> mapIntDouble;
	mapIntDouble m;
	for (int i{}; i < 10; ++i) { m[i] = i * 3.14; }
	for (auto i : m) std::cout << i.first << " " << i.second << "\n";
}


//difference between inserting via operator[] and inserting via insert 
void fillMapIntA()
{
	typedef std::map<int, A> mapIntA;
	mapIntA m;
	std::cout << "--------------------assigning via operator=\n";
	for (int i{}; i < 5; ++i) { m[i] = i * 3.14; }

	std::cout << "---------------------printing\n";
	for (auto &i : m) std::cout << i.first << " " << i.second.age << "\n";

	m.clear();

	std::cout << "--------------------assigning via insert=\n";
	for (int i{}; i < 5; ++i)
	{
		std::pair<mapIntA::iterator, bool> result = m.insert(std::make_pair(i, i*3.14));
	}
	std::cout << "---------------------printing\n";
	for (auto &i : m) std::cout << i.first << " " << i.second.age << "\n";
}

int main()
{
	fillMapIntA();
	return 0;
}
