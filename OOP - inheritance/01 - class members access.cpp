#include <iostream>

class Base
{
public:
	int a{ 0 };
	void display() { std::cout << a << ", " << b << ", " << c << "\n"; }
protected:
	int b{ 0 };
private:
	int c{ 0 };
};

class Derived : public Base
{
	//a --> accesible, will become public
	//b --> accesible, will become protected
	//c --> innacessible
public:
	void display() { std::cout << a << ", " << b << "\n"; }
};

int main()
{
	Base base;
	base.a = 100;
	//base.b = 100; //protected innacessible upon object
	//base.c = 100; //private innacessible upon object and upon derived class
	base.display();

	Derived derived;
	derived.a = 200;
	//derived.b = 200; //protected innacessible upon object
	//derived.c = 200; //private innacessible upon object and upon derived class
	derived.display();

	return 0;
}