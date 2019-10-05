#include <iostream>

struct Car 
{
	virtual void start() = 0;
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
	Car* car = nullptr;

	car = new Audi;
	car->start();

	car = new BMW;
	car->start();

	car = new Skoda;
	car->start();

	return 0;
}