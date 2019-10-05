#include <iostream>

struct Car 
{
	virtual void start() { std::cout << "car started\n"; };
};

struct Skoda : public Car 
{
	void start() { std::cout << "Skoda started\n"; }
};

struct Audi : public Car
{
	void start() { std::cout << "Audi started\n"; }
};

struct BMW : public Car
{
	void start() { std::cout << "BMW started\n"; }
};


int main()
{
	//memory leak checker -- only in debug mode 
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Car* car = nullptr;

	car = new Audi;
	car->start();
	//delete car;

	car = new BMW;
	car->start();
	delete car;

	car = new Skoda;
	car->start();
	delete car;

	return 0;
}