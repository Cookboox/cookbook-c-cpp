#include <iostream>

//when we use raw pointers in a class we need to provide our our version of = operator
//asignemt operator is the only one that the compiler provides default behaviour for
//operator overloading is syntactic sugar, behind the scenes we still call functions
//lets say i have a class Number and i want to do some math with it
//except these five all operators can be overloaded (::, :*, :?, ., sizeof)

//---RULES---
//u cannot change precendence and associativity of operators
//u cannot change "arity" (binary needs to stya binary, unary needs to stay unary)
//u cannot change the bahaviour with build in types (+ stays + with numbers)
//u cannot create new operator that are not used in c++ now
//these four operators must be implemented as member methods only (->, [], (), =)
//all other operators can be implemented either as member methods, or as global functions

int main()
{



	return 0;
}