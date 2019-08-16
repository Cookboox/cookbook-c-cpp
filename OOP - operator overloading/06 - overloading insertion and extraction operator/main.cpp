#include <iostream>
#include "Mystring.h"


int main()
{
	Mystring s1{ "hello" };
	Mystring s2{ "hi" };
	std::cout << s1 << ", " << s2 << "\n";
	   
	Mystring s3;

	std::cin >> s3;
	std::cout << s3 << "\n";

	return 0;
}