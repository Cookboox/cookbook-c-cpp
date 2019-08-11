#pragma once

//now i want to implement:
//operator- that will make the string lowercase
//operator~ that will make the string uppercase
//operator+ that will concatenate the strings
//equality operator (==)

class Mystring
{
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