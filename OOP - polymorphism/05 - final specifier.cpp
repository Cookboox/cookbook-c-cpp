#include <iostream>

//keyword final can be used in two contexts:
// 1) on a class level --> saying this class cannot be subclassed
// 2) on a method level --> saying this virtual method cannot be overriden


/*

class ClassZero final					// ClassZero cannot be inherited from
{};

class ClassTwo final : public ClassOne	 // ClassTwo cannot be inherited from
{};

-------------------------------------------------------------------------------------




*/

class A
{
public:
	virtual void do_stuff();
};

class B : public A
{
public:
	virtual void do_stuff() final; //cannot be overriden anylonger
};

class C : public B
{
public:
	virtual void do_stuff(); // compiler error
};