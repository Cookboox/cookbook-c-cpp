#pragma once
#include <iostream>

class I_Printable
{
	friend std::ostream& operator<<(std::ostream& os, I_Printable const& rhs); //implemented in I_Printable.cpp
public:
	virtual void print(std::ostream& os) const = 0; //all subclasses need to implement it
	virtual ~I_Printable() = default;
};