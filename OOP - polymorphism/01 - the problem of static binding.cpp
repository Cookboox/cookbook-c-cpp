#include <iostream>
#include <memory>

class Base
{
public:
	void say_hello() const { std::cout << "hello i am Base\n"; }

};

class Derived : public Base
{
public:
	void say_hello() const { std::cout << "helo i am Derived\n"; }
};


void greet(Base const& x)
{
	std::cout << "Greeting: ";
	x.say_hello(); //which function will ba called here?
}

int main()
{
	Base b;
	b.say_hello();

	Derived d;
	d.say_hello(); // obvious - Derived::say_hello will be called 

	//references - the problem
	greet(b); // obvious - Base::say_hello will be called
	greet(d); // not so obvious - also Base::say_hello will be called - why? becase there is static binding and function is called based on the reference (pointer)

	//raw pointers - the probem
	Base* p1 = new Base;
	p1->say_hello(); // obvious - Base::say_hello will be called

	Base* p2 = new Derived;
	p2->say_hello(); // not so obvious - also Base::say_hello will be called - why? becase there is static binding and function is called based on the pointer

	//smart pointers - the same problem
	std::unique_ptr<Base> bs1 { std::make_unique<Base>() };
	bs1->say_hello();

	std::unique_ptr<Base> bs2 { std::make_unique<Derived>() };
	bs2->say_hello();





	return 0;
}