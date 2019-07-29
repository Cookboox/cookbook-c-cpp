#include <iostream>
#include "Mystring.h"


int main()
{
	Mystring s1{ "hello" };
	Mystring s2;
	s1.display();

	s2 = s1; // operator= will be called
	s2.display();

	s2 = "i am a new string";
	s2.display();

	return 0;
}