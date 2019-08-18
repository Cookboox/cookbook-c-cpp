#include <iostream>
#include <vector>

//used when there is a typical usage of a pointer - allocate, use, delete (but all is automatic)

//Keynotes:
//-points to a class object on the heap
//-can be only one
//-is owing
//-cannot be assigned or moved (its copy constructor and copy assignement operator are deleted)
//-automatically destroys what it points to when out of scope

//ALERT:
//it is possible to initialize unique_ptr from a raw pointer but then you point to one object with two pointers -very bad!!


struct A
{
	A(int a) { std::cout << "constructing A with value " << a << "\n"; }
	~A() { std::cout << "destructing A\n"; }
};


void ways_to_crate_ptr()
{
	std::unique_ptr<int> p1{ new int(33) }; //good
	std::unique_ptr<int> p2 = std::make_unique<int>(100); //better

	auto pa = std::make_unique<A>(111);
}


void usefull_methods()
{
	std::unique_ptr<int> p{ new int(42) };
	std::cout << *p << "\n";

	//usefull methods
	std::cout << p.get() << "\n"; //gets the address of raw pointer
	p.reset(); //nulls out
	if (p) std::cout << *p << "\n"; //check
}

void no_copy_but_move()
{
	auto p = std::make_unique<A>(22);
	std::unique_ptr<A> pp = nullptr;
	if (!p) std::cout << "p is nullptr\n";
	if (!pp) std::cout << "pp is nullptr\n";
	
	//pp = p; //not allowed
	//pp{ p }; //also not allowed

	pp = std::move(p); //allowed
	if (!p) std::cout << "p is nullptr\n";
	if (!pp) std::cout << "pp is nullptr\n";
	
}

void pointers_in_collections_one()
{
	std::unique_ptr<double> pd{ new double{3.14} };
	std::vector<std::unique_ptr<double>> v_double;
	//v_double.push_back(pd);// error --> since pushback implies copying
	v_double.push_back(std::move(pd)); //fine
	std::cout << *v_double.at(0) << "\n";

	auto pa = std::make_unique<A>(99);
	std::vector<std::unique_ptr<A>> v_A;
	v_A.emplace_back(std::move(pa));

}//vector dealocates all its elements correctly

void pointers_in_collections_two()
{
	std::vector<std::unique_ptr<A>> va;
	va.push_back(std::make_unique<A>(1));
	va.push_back(std::make_unique<A>(2));
	va.push_back(std::make_unique<A>(3));

}//vector dealocates all its elements correctly

int main()
{	
	ways_to_crate_ptr();
	usefull_methods();
	no_copy_but_move();
	pointers_in_collections_one();
	pointers_in_collections_two();
	   
	return 0;
}
