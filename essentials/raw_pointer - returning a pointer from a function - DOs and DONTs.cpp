#include <iostream>

//------DOs-------//


// global variables - could be even in main - all is ok
int a = 10;
int b = 10;

int* ptr_to_largest()
{
	int* aptr = &a;
	int* bptr = &b;
	return(*aptr > * bptr ? aptr : bptr);
}


//------DONTs-------//


// potential disaster - a and b are local and this returns pointer to local var, that willcease to exist
int* dont_do_this(int a, int b)
{
	int* aptr = &a;
	int* bptr = &b;

	return (*aptr > * bptr ? aptr : bptr);
}

// potencial disaster - again, local variable never do this!!
int dont_do_this()
{
	int a = 10;
	int* aptr = &a;

	return *aptr;
}


int main()
{
	std::cout << ptr_to_largest() << "\n";
	std::cout << *ptr_to_largest() << "\n";

	std::cout << "------------------\n";

	std::cout << *dont_do_this(11, 12) << "\n";
	std::cout << dont_do_this() << "\n";

	return 0;
}