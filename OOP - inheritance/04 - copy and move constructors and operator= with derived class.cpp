#include <iostream>

/***************************************************

- often no need to provide my own copy/move costructors and overloaded operator=

1) if i DO NOT define them in Derived:
	-> the compiler will create them automatically and call the Base´s version of them

2) if i DO define them in Derived:
	-> then i MUST invoke the Base´ s version explicitly

------------------------------
when each Base and Derived have raw pointers and heap memory
i need to use deep copy semantic for both Base and Derived

********************************************************/

class Base
{
private:
	int value;
public:
	Base() : value{ 0 } { std::cout << "no arg constructor base\n"; }
	Base(int x) : value{ x } { std::cout << "int constructor base\n"; }
	Base(Base const& source) : value{ source.value } { std::cout << "copy constructor base\n"; }
	~Base() { std::cout << "destructor base\n"; }

	//operator= in this case there is no need because the compiler would provide one, but i just need to see what is happening
	Base& operator=(Base const& rhs)
	{
		std::cout << "operator= base\n";
		if (this == &rhs) { return *this; } //check against self-asignement
		else
		{
			this->value = rhs.value;
			return *this;
		}
	}

};

//in derived class "slicing will happen"
class Derived : public Base
{
private:
	int double_value;
public:
	Derived() : Base{}, double_value{0} { std::cout << "no arg constructor derived\n"; }
	Derived(int x) : Base{ x }, double_value{ x * 2 }  { std::cout << "int constructor derived\n"; }
	//this is where the slicing takes place, first i initialize Base part --> Base{source}, then the derived part --> double_values{source.double_value}
	Derived(Derived const& source) : Base{ source }, double_value{ source.double_value } {std::cout << "copy constructor derived\n"; }
	~Derived() { std::cout << "derived destructor\n"; }

	//operator= again, in this case there is no need because the compiler would provide one, but i just need to see what is happening
	//again here slicing will happen
	Derived& operator=(Derived const& rhs)
	{
		std::cout << "operator= derived\n";
		if (this == &rhs) return *this;
		else
		{
			//the slicing
			Base::operator=(rhs); // first base part of derived will be assigned using operator= of base class
			this->double_value = rhs.double_value; // then my own part will be added
			return *this;
		}
	}


};




int main()
{
	/*Base b_noarg;
	Base b_int{10};
	Base b_int_copy{ b_int };
	b_noarg = b_int;*/


	Derived d_noarg;
	Derived d_int{ 10 };
	Derived d_int_copy{ d_int };
	d_noarg = d_int;


	return 0;
}