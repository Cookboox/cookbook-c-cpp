#include <iostream>

//non owing "weak" reference to a managed shared object 

//KEYONOTES:
//-they are always made from shared pointers
//-they do not increment or decrement use_count
//-they are used to prevent strong circular reference, or for caching, or for traversing nodes in linked list...


//circular reference:
//A referes to B with share_ptr
//B referes to A with share_ptr

class B;

class A
{
	std::shared_ptr<B> ptr_to_B = nullptr;

public:
	void set_pointer(std::shared_ptr<B>& p) { ptr_to_B = p; }
	A() { std::cout << "constructing A\n"; }
	~A() { std::cout << "destructing A\n"; }
};

class B
{	
	std::shared_ptr<A> ptr_to_A = nullptr;
public:
	void set_pointer(std::shared_ptr<A>& p) { ptr_to_A = p; }
	B() { std::cout << "constructing B\n"; }
	~B() { std::cout << "destructing B\n"; }
};


void strong_circular()
{
	std::shared_ptr<A> pa = std::make_shared<A>();
	std::shared_ptr<B> pb = std::make_shared<B>();

	//estabilishing circular ref --> leak, A will not be deleted
	pa->set_pointer(pb);
	pb->set_pointer(pa);
}





int main()
{
	strong_circular();


	return 0;
}