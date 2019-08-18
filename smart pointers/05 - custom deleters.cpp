#include <iostream>

//sometimes when we delete smart pointer we need more than just to delete heap object
//this is where custom deleters comes in --> these are special use cases
//works for both unique and shared pointers
//BUT make_shared and make_unique dont support that, becaue if you need a specialied way to make and object, you need also a specialized way to make them too

//lots of ways to achiver custom deleters
//1) functions
//2) lambdas
//3) others

/***************************************************

	//this is my custom deleter
	void my_deleter(MyClass* raw_ptr)
	{
		//deleter code here
		delete raw_ptr;
	} 

	//when creating a pointer to a managed object, i am passing the deleter alongside with it
	//when the pointer is destroyed, it will call my deleter
	shared_ptr<MyClass> ptr{ new MyClass{}, my_deleter }; //i am passing a function pointer actually

***************************************************/ 


struct A
{
	A(int x) { std::cout << "constructing A with value " << x << "\n"; }
	~A() { std::cout << "destructing A\n"; }
};

void A_deleter(A* ptr)
{
	std::cout << "calling A deleter using function\n";
	delete ptr;
}




int main()
{
	{
		std::shared_ptr<A> ptr{ new A(32), A_deleter }; //passing both
	}

	{
		std::shared_ptr<A> ptr{ new A(32),
								[](A* ptr)
								{
									std::cout << "calling A deleter using lambda\n";
									delete ptr;
								}
							  }; 
	} 


	return 0;
}