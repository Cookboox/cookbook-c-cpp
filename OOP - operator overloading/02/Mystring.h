#pragma once

class Mystring
{
private:
	char* str;
public:
	Mystring();
	Mystring(const char* s);
	Mystring(Mystring const& source);
	~Mystring();

	const char* get_string() const;
	size_t get_length() const;
	void display() const;

	//=operator overload to make deep copy
	Mystring& operator=(Mystring const& rhs); // i will return reference to avoid extra copy
};