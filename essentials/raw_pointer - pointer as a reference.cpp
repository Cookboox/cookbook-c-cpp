#include <iostream>


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



int main()
{
	pointer_as_reference();

	return 0;
}