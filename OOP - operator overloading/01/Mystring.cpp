#include "Mystring.h"
#include <iostream>
#include <cstring>

Mystring::Mystring() : str{ nullptr } 
{
	std::cout << "empty arg constructor - allocating 1 byte\n";
	str = new char{ '\0' };  // on the heap i am creating empty string which is represented one null character
	//*str = '\0';
} 

Mystring::Mystring(const char* s) : str{ nullptr }
{
	if(s != nullptr) // if someone initializes it with a regular string that is not empty
	{
		std::cout << "one arg constructor - allocating " << std::strlen(s) +  1 << " bytes\n";
		str = new char[std::strlen(s) + 1]; // allocate the array of chars on the heap such, that the length is length of string + terminanting char
		std::strcpy(str, s); // now copy the string that was passed in construction, to the newly allocated array
	}
	else // is someone passess empty string
	{
		std::cout << "one arg constructor - allocating 1 byte\n";
		str = new char{ '\0' }; //return empty string just as above
		//*str = '\0';
	}
}

//copy constructor making deep copy 
Mystring::Mystring(Mystring const& source) : str{ nullptr } 
{
	std::cout << "copy constructor - allocating " << std::strlen(source.str) + 1 << " bytes\n";
	str = new char[std::strlen(source.str) + 1]; // again i need to allocate new array (deep copy) and need to get member source
	std::strcpy(str, source.str);
}

Mystring::~Mystring() 
{	
	std::cout << "dealocating\n";
	delete[] str; //  shouldnt this crash when no arg constructor will be used or if somebody passes empty string to initialize
};

const char* Mystring::get_string() const
{
	return this->str;
}

size_t Mystring::get_length() const 
{
	return std::strlen(this->str);
};

void Mystring::display() const
{
	std::cout << this->str << " : " << std::strlen(this->str) << "\n";
}