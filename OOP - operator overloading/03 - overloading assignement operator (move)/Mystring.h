#pragma once

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
};