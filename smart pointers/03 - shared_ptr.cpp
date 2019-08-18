#include <iostream>
#include <vector>

//provides a shared ownership model of the heap object
//one object on heap can be referenced by multiple shared pointers

//KEYNOTES:
//-they can be assigned
//-they can be copied
//-they also support move semantic
//-they have reference counter --> overhead


struct A
{
	int value = 99;
	std::string method() {  return "hello\n"; }
	A(int a) { std::cout << "constructing A with value " << a << "\n"; }
	~A() { std::cout << "destructing A\n"; }
};


void ways_to_crate_ptr()
{
	std::shared_ptr<int> p1{ new int(33) }; //good
	std::shared_ptr<int> p2 = std::make_shared<int>(100); //better

	auto pa = std::make_shared<A>(12221);
}


void careful()
{
	std::shared_ptr<int> p1 = std::make_unique<int>(0); //this is actually shared pointer!!
	std::shared_ptr<int> p2 = nullptr;
	std::cout << p1.use_count() << "\n";
	p2 = p1;
}
 
void usefull_methods()
{
	//use_count
	std::shared_ptr<int> p1 = std::make_shared<int>(0);
	std::cout << p1.use_count() << "\n"; // 1 

	std::shared_ptr<int> p2 = p1;
	std::cout << p1.use_count() << "\n"; // 2 

	//reset
	p2 = nullptr; //same as p2.reset();
	std::cout << p1.use_count() << "\n"; // 1

	//swap and operator dereference *
	std::shared_ptr<int> p3 = std::make_shared<int>(10);
	std::cout << *p1 << " - " << *p3 << "\n";
	p3.swap(p1);
	std::cout << *p1 << " - " << *p3 << "\n";

	//member operator dereference ->
	std::shared_ptr<A> pa = std::make_shared<A>(42);
	std::cout << pa->value << " - " << pa->method();

}

void shared_ptr_in_collections()
{
	std::vector<std::shared_ptr<A>> va;
	std::shared_ptr<A> pa1 = std::make_shared<A>(67);
	std::shared_ptr<A> pa2 = std::make_shared<A>(68);

	//is allowed
	va.push_back(pa1);
	va.push_back(pa2);

	std::cout << pa2.use_count() << "\n"; //will show 2 since it copied into vector!!!
}



int main()
{
	//ways_to_crate_ptr();
	//careful();
	//usefull_methods();
	
	shared_ptr_in_collections();
	return 0;
};