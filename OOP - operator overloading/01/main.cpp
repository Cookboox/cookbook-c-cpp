#include <iostream>
#include "Mystring.h"


int main()
{
	Mystring s1{ "The program is now permitted to do anything whatsoever" };
	Mystring s2{ s1 };
	Mystring empty("");
	Mystring noarg;

	empty.display();
	empty.get_length();

	s1.display();
	s1.get_length();

	s2.display();
	s2.get_length();



	return 0;
}