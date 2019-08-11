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
		str = new char{ '\0' }; //return empty string just as above
		//*str = '\0';
		std::cout << " one arg constructor - allocating " << std::strlen(str) + 1 << " bytes\n";
	}
}

////copy constructor making shallow copy - WILL NOT BE USED THIS IS PURELY FOR EDUCATIONAL PURPOSE TO SEE THE SYNTAX
//Mystring::Mystring(Mystring const& source) : str{ source.str } // copy the pointer
//{
//	std::cout << "shallow copy constructor\n";
//}

//copy constructor making deep copy 
Mystring::Mystring(Mystring const& source) : str{ nullptr } 
{
	str = new char[std::strlen(source.str) + 1]; // i need to allocate new array (deep copy) and need to get member source
	std::strcpy(str, source.str); // and copy the data into newly allocated array
	std::cout << " deep copy constructor - allocating " << std::strlen(source.str) + 1 << " bytes\n";
}

//move constructor - very similar to shallow copy constructor except nulling out the source pointer
Mystring::Mystring(Mystring&& source) noexcept : str{ source.str }  // copy the pointer
{
	source.str = nullptr; // and null it out
	std::cout << "move constructor\n";
}

Mystring::~Mystring() 
{	
	if (this->str == nullptr)
	{
		std::cout << "deleting nullptr\n";
	}
	else
	{
		std::cout << "deleting " << this->str << "\n";
		delete[] str; //  shouldnt this crash when no arg constructor will be used or if somebody passes empty string to initialize
	}
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

// COPY ASSIGNEMENT is basically a deep copy constructor with some extension
// 1) check against self - asignement
// 2) delete the memory previously pointed to by the lhs
// 3) create the space for the new object --> this is the copy constructor part!!
// 4) return the object
Mystring& Mystring::operator=(Mystring const& rhs)
{
	if (this == &rhs) // if the address of this object (which is held in this pointer is equal to the address of object to passed --> they are the same
		return *this; // return this object
	else
	{
		std::cout << "using COPY ASIGNEMENT\n";
		delete[] this->str; //first dealocate what is pointed to by the str pointer

		//from here it is in fact the same as deep copy constructor - so i am basically doing a deep copy construcotr in = operator function
		str = new char[std::strlen(rhs.str) + 1]; // allocate enough space just like normally
		std::strcpy(str, rhs.str); // copy the passed string into newly allocated space
		return *this;
	}
}

// MOVE ASSIGNEMENT is basically a move constructo with some extension
// 1) check agains self asignement
// 2) delete the memory previously pointed to by the lhs to prevent memory leak
// 3) copy the source´s pointer and null it out --> this is the move constructor part!!
// 4) return the object
Mystring& Mystring::operator=(Mystring&& rhs) noexcept
{
	if (this == &rhs) return *this; // 1)
	else
	{
		std::cout << "using MOVE ASIGNEMENT\n";
		delete[] this->str; // 2)
		str = rhs.str; // 3)
		rhs.str = nullptr; // 3) this is the critial part
		return *this; // 4)
	}
}