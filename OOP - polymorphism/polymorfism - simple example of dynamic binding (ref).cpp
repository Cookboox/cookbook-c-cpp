#include <iostream>


struct Car 
{
	virtual void start() { std::cout << "car started\n"; };
};

struct Skoda : public Car 
{
	virtual void start() { std::cout << "Skoda started\n"; }
	
};

struct Audi : public Car
{
	virtual void start() { std::cout << "Audi started\n"; }
	//Audi() = default;
};

struct BMW : public Car
{
	virtual void start() { std::cout << "BMW started\n"; }
	//BMW() = default;
};

void f()
{
	Car car;
	Car& ref_car  = car;

	Skoda octavia;
	Car& ref_skoda = octavia;

	Audi monmgo;
	Car& ref_audi = monmgo;



	ref_car.start();
	ref_audi.start();
	ref_skoda.start();

		
}

int main()
{
	f();


	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	return 0;
}