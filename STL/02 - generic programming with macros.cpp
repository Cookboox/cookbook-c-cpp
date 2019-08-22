#include <iostream>

//WARNING!! be very carefull when using macros, especially macros that used arguents
//macros is in C-style code, or legacy C++ code

//MACROS (#define)
//preprocessor doesnt know C++, so there is no type checking, it simply replaces text



int main()
{
	//i can define a variable
	#define a 100
	std::cout << a << "\n";

	//or i can define a function`which is basically overloaded and will work with any arguments
	#define max(a , b) ((a) > (b) ? (a) : (b))
	
	std::cout << max(1, 2) << "\n";
	std::cout << max(2.33, 4.444) << "\n";
	std::cout << max('f', 'k') << "\n";

	return 0;
}