#include <iostream>
#include "Mystring.h"


int main()
{
	Mystring s1{ "HELLO" };
	Mystring s2 = -s1;
	s2.display();

	Mystring s3 = s1 + s2;
	s3.display();

	Mystring s4 = ~s3;
	s4.display();


	return 0;
}