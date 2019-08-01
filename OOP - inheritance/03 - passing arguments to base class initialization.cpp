#include <iostream>

//in order to initialize all the members of the derived class 
//i can use bas class constructor in the initialization list of the derived class
//and pass some arguments there

class Base
{
private:
	int value;
public:
	Base() : value{ 0 } { std::cout << "base class no args constructor\n"; }
	Base(int x) : value{ x } { std::cout << "base class int constructor\n"; }
	~Base() { std::cout << "base class destructor\n"; }
};

class Derived : public Base
{
private:
	int double_value;
public:
	Derived() : Base{}, double_value { 0 } { std::cout << "derived class no args constructor\n"; } 
	Derived(int x) : Base{x}, double_value { x * 2 } { std::cout << "derived class int constructor\n"; }
	~Derived() { std::cout << "derived class destructor\n"; }
};


int main()
{
	//Derived d; //both value and double_value = 0

	Derived d{ 10 };


	return 0;
}