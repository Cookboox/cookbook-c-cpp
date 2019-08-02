#include <iostream>

//we can override base class virtual functions, but the function signature and return type must be EXACTLY the same
//if they are not, we have redefinition NOT overriding.
//redefined functions are statically bound
//overrided functios are dynamically bound
//c++11 provides override specifier to have the ensure overriding (it is for error checking only)

class Base
{
public:
	virtual void say_hi() const { std::cout << "hi i am Base\n"; }
	virtual ~Base() {};
};

class Derived : public Base
{
public:
	virtual void say_hi() const override { std::cout << "hi i am Derived\n"; } //using the word override to reassure that i put the signature correct
	virtual ~Derived() {};
};


int main()
{
	Base* pb = new Base;
	Base* pd = new Derived;

	pd->say_hi();
	pb->say_hi();
	
	return 0;
}