#include <iostream>
#include "Mystring.h"

// copy assignement operator from previous section works wil lvalue reference
// move assignemnet works with rvalue refrences

// if we dnt provide move assignement, c++ will provide copy constructor by default
// but move semantic can be much more efficient


int main()
{
	Mystring s1{ "hello" };
	s1.display();

	s1 = Mystring{ "bonjour" }; //this is where the move asignement will be called - the string needs to be constructed and has no name --> can be moved, not copied, into s2;
	s1.display();
	
	s1 = "goodbye"; // this is where the move assignement comes into play - the string needs to be constructed and has no name --> can be moved, not copied, into s2;
	s1.display();

	return 0;
}