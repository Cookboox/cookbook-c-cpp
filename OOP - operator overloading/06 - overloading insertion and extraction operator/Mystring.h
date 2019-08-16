#pragma once
#include <iostream>

//now i want to implement:
// << and >>
// i need implement them as non member functions because otherwise i would have to use them the other way around (myobject << cout, myobject >> cin) 

class Mystring
{
	friend bool operator<(Mystring const& lhs, Mystring const& rhs);
	friend bool operator<=(Mystring const& lhs, Mystring const& rhs);
	friend bool operator>=(Mystring const& lhs, Mystring const& rhs);
	friend bool operator>(Mystring const& lhs, Mystring const& rhs);

	friend std::ostream& operator<<(std::ostream& lhs, Mystring const& rhs);
	friend std::istream& operator>>(std::istream& lhs, Mystring & rhs);

private:
	char* str;
public:
	Mystring();
	Mystring(const char* s);
	Mystring(Mystring const& source);
	Mystring(Mystring&& source) noexcept;
	~Mystring();

	const char* get_string() const;
	size_t get_length() const;
	void display() const;

	//=operator overload to make deep copy assignement
	Mystring& operator=(Mystring const& rhs); // returns reference to avoid extra copy
	//=operator overload to make move assignement
	Mystring& operator=(Mystring&& rhs) noexcept; // returns reference to avoid extra copy

	Mystring operator-() const; //make lowercase
	Mystring operator~() const; //make uppercase
	Mystring operator+(Mystring const& rhs) const; //concatenate
	bool operator==(Mystring const& rhs) const; //is equal?
};