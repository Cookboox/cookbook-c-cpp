#include <iostream>


struct foo
{
	foo() { std::cout << "construct foo\n"; }
	~foo() { std::cout << "destruct foo\n"; }
};

void dangling_pointer_one_stack()
{
	foo one;
	foo two;
	foo three;

	foo* ptr_one{ &one };
	foo* ptr_two{ &two };
	foo* ptr_tree{ &one }; //two pointer pointing to the same object!! 
	   
	std::cout << ptr_one << ", " << ptr_two << ", " << ptr_tree <<  "\n";
}


void pointer_as_reference()
{
	int a = 1;

	int* a_ptr1 = &a;
	int* a_ptr2 = &a;
	int* a_ptr3 = &a;
	int* a_ptr4 = &a;
	int* a_ptr5 = &a;
	
	std::cout << a_ptr1 << "\t" << a_ptr2 << "\t" << a_ptr3 << "\t" << a_ptr4 << "\t" << a_ptr5 << "\n";
	std::cout << *a_ptr1 << "\t" << *a_ptr2 << "\t" << *a_ptr3 << "\t" << *a_ptr4 << "\t" << *a_ptr5 << "\n";

	*a_ptr4 = 999;

	std::cout << a_ptr1 << "\t" << a_ptr2 << "\t" << a_ptr3 << "\t" << a_ptr4 << "\t" << a_ptr5 << "\n";
	std::cout << *a_ptr1 << "\t" << *a_ptr2 << "\t" << *a_ptr3 << "\t" << *a_ptr4 << "\t" << *a_ptr5 << "\n";
}



void func()
{
	int* p = { nullptr };

	if (true)
	{
		int a = 1;	
		int* ptr = &a;
		std::cout << *ptr << "\n";
	}
	p = ptr;
	std::cout << *p << "\n";
	   
}



int main()
{

	pointer_as_reference();
	func();

	return 0;
}