#include <iostream>



void multiply(int* const int_ptr) // this is making a COPY of the address - how to make it non-copying? 
{
	*int_ptr *= 2;
}


void mult(int&  int_ptr) // reference to  pointer is not allowed --> i need to pass normal reference
{
	int_ptr *= 2;
}

#include <string>
#include <vector>

std::vector<std::string> names{ "petr", "paul", "marc" };
int arr[]{ 23,4,54,32,5,90,0 };


void display(std::vector<std::string>* v)
{
	for (const auto i : *v) { std::cout << i << "\n"; };
}

void display(int* arr)
{
	while (*arr != 0) { std::cout << *arr++ << "\n"; }
}



int main()
{
	int a = 10;
	int* a_ptr = &a;

	std::cout << "before calling multiply: " << a << "\n";
	multiply(a_ptr); 
	std::cout << "after calling multiply: " << a << "\n";
	multiply(&a); //same as previous - no need to initialize a_ptr - RAII
	std::cout << "after second calling multiply: " << a << "\n";
	
	std::cout << "-------------------------\n";

	int b = 100;
	int& b_ref = b;

	std::cout << "before calling mult: " << b << "\n";
	std::cout << "before calling mult: " << b_ref << "\n";
	mult(b); // here i can pass either b_ref, or b itself
	std::cout << "after calling mult: " << b << "\n";

	std::cout << "-------------------------\n";

	display(&names);
	display(arr);

	return 0;
}