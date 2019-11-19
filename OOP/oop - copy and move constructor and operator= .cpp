#include <iostream>

struct A
{
	std::string name;
	int age;

	A()
	{
		std::cout << "Default ctor. ";
	}

	A(std::string const& s, int x) :name(s), age(x)
	{
		std::cout << "Ctor. ";
	}

	A(A const& a) :name(a.name), age(a.age)
	{
		std::cout << "Copy ctor. ";
	}

	A(A && a) noexcept :name(std::move(a.name)), age(std::move(a.age))
	{
		std::cout << "Move ctor. ";
	}

	A& operator=(A const& a)
	{
		std::cout << "Copy assign. ";
		name = a.name;
		age = a.age;
		return *this;
	}

	A& operator=(A && a) noexcept
	{
		std::cout << "Move assign. ";
		name = std::move(a.name);
		age = std::move(a.age);
		return *this;
	}

	~A() noexcept
	{
		std::cout << "Dtor. ";
	}
};

int main()
{



	return 0;
}