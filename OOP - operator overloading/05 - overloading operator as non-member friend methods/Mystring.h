#pragma once

//now i want to implement:
// comparative operators  based on the length of the string
// i want to implement them as friend functins outside the class

class Mystring
{
	friend bool operator<(Mystring const& lhs, Mystring const& rhs);
	friend bool operator<=(Mystring const& lhs, Mystring const& rhs);
	friend bool operator>=(Mystring const& lhs, Mystring const& rhs);
	friend bool operator>(Mystring const& lhs, Mystring const& rhs);

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