#include <iostream>
#include <thread>


//6 different ways to create thread using callable objects:
//1) function pointer
//2) lambda functions
//3) using functor
//4) using nonstatic member function
//5) using static memebr function



//if we create multiple threads at the same time, there is no guarrantee which one will start first --why?? 


void foo() { std::cout << "i am in a thread using function pointer..\n"; }

class SomeClass
{
public:
	void operator() () { std::cout << "i am in a thread using functor..\n"; } //overloading operator () creates functor
	void some_nonstatic_function() { std::cout << "i am in a thread using non static member function..\n"; } //just some regular class function
	static void some_static_function() { std::cout << "i am in a thread using static member function..\n"; } //static class function
};



int main()
{
	std::cout << "--------1)function pointer-----------\n";
	std::cout << "i am in main before join..\n";
	std::thread t(foo); //function taking no parameter
 	t.join();
	std::cout << "i am in main after join..\n";
	
	std::cout << "\n--------2)lambda functions-----------\n";
	std::cout << "i am in main before join..\n";
	std::thread t2([] { std::cout << "i am in a thread using lambda expresion..\n"; }); //directly injection lambda into thread creating
	t2.join();
	std::cout << "i am in main after join..\n";

	std::cout << "\n--------3)functor-----------------\n";
	std::cout << "i am in main before join..\n";
	std::thread t3((SomeClass())); //using functor
	t3.join();
	std::cout << "i am in main after join..\n";

	std::cout << "\n--------4)nonstatic member function-----------\n";
	SomeClass x;
	std::cout << "i am in main before join..\n";
	std::thread t4(&SomeClass::some_nonstatic_function, &x); //using non static member function. in fact i am passing the address of the particular function (that is the ref sign) + object
	t4.join();
	std::cout << "i am in main after join..\n";

	std::cout << "\n--------5)static member function-----------\n";
	std::cout << "i am in main before join..\n";
	std::thread t5(&SomeClass::some_static_function); //the same as previous except i dont need any object..
	t5.join();
	std::cout << "i am in main after join..\n";

	return 0; 
}