#include <iostream>
#include "Mystring.h"


int main()
{
	Mystring s1{ "hello" };
	Mystring s2{ "hi" };

	std::cout << std::boolalpha << (s2 < s1) << "\n";
	std::cout << std::boolalpha << (s2 <= s1) << "\n";
	std::cout << std::boolalpha << (s2 > s1) << "\n";
	std::cout << std::boolalpha << (s2 >= s1) << "\n";
	
	return 0;
}