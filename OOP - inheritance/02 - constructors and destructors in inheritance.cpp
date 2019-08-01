#include <iostream>

class Base
{
private:
	int value;
public:
	Base() : value{0} { std::cout << "base no-arg constructor\n"; }
	Base(int a) : value{ a } { std::cout << "base one-arg constructor\n"; }
	~Base() { std::cout << "~base destructor\n"; }
};

class Derived : public Base
{
	//normaly constructor are not inherited but using this statement allowed me to inherit it
	// but it initialized the value with not specialezed constructor - only the base constructor
	using Base::Base; 
public:
	int doubled_value;
public:
	Derived() : doubled_value {0} { std::cout << "derived no-arg constructor\n"; }
	//Derived(int a) : doubled_value{ a * 2 } { std::cout << "derived one-arg constructor\n"; }
	~Derived() { std::cout << "~derived destructor\n"; }

};


int main()
{
	//Base b;
	//Base b{ 1 };

	//Derived d; 
	//Derived d{ 1 }; // even though this calls base constructor first, it will not initialize "value" to 1;
	Derived d{ 1 };
	


	return 0;

}