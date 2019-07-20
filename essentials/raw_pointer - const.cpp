#include <iostream>

// three options
// pointer to constance
// constant pointer
// constant pointer to constance



void ptr_to_constance()
{
	int a = 1;
	int b = 2;

	int const* ptr = &a; //identical to const int *ptr = &a
	std::cout << "address: " << ptr << " value: " << *ptr << "\n"; // i can read both the address and the value
	
	ptr = &b; // i can change the address --> change where the pointer points
	std::cout << "address: " << ptr << " value: " << *ptr << "\n"; 

	//*ptr = 9999; // i cannot change the value
}

void constant_pointer()
{
	int a = 1;
	int b = 2;

	int *const ptr = &a;
	std::cout << "address: " << ptr << " value: " << *ptr << "\n"; // i can read both the address and the value

	//ptr = &b; // i cannot change the address -->  cannot change where the pointer points

	*ptr = 9999; // i can change the value, but the address stays the same
	std::cout << "address: " << ptr << " value: " << *ptr << "\n";
}


void constant_pointer_to_constance()
{
	int a = 1;
	int b = 2;

	int const * const ptr = &a;
	std::cout << "address: " << ptr << " value: " << *ptr << "\n"; // i can read both the address and the value

	//ptr = &b; // i cannot change the address -->  cannot change where the pointer points

	//*ptr = 9999; // i cannot change the value either
}

int main()
{
	ptr_to_constance();
	std::cout << "---------------\n";
	constant_pointer();
	std::cout << "---------------\n";
	constant_pointer_to_constance();
	
	return 0;
}