#include <iostream>
#include <string>

class ObjectPtr
{
	friend std::ostream& operator<<(std::ostream &os, ObjectPtr const& rhs);

private:
	std::string* m_ps;
	int m_value;
public:
	ObjectPtr(std::string const &s, int value) :
		m_ps{ new std::string(s) }, m_value{ value }
	{}

	//deep copy constructor
	ObjectPtr(ObjectPtr const& source) :
		m_ps{ new std::string(*source.m_ps) }, m_value{ source.m_value }
	{}

	//deep copy assignement operator
	ObjectPtr& operator=(ObjectPtr const& rhs);

};




std::ostream& operator<<(std::ostream &os, ObjectPtr const& rhs)
{
	os << "string address is: " << rhs.m_ps << " string value is: " << *rhs.m_ps <<  " int address is: " << &rhs.m_value << " int value is: " << rhs.m_value;
	return os;
}


//first version without self assignement check
ObjectPtr& ObjectPtr::operator=(ObjectPtr const& rhs)
{
	//1. copy the rhs's data to newly created temporary object
	std::string* temp{ new std::string(*rhs.m_ps) };

	//2. delete the lhs's data
	delete m_ps;

	//3. copy the data from the temporary object to lhs
	m_ps = temp;
	m_value = rhs.m_value;

	//4. return this object
	return *this;
}



//second version with self assignement check
//ObjectPtr& ObjectPtr::operator=(ObjectPtr const& rhs)
//{
//	if (this == &rhs)
//		return *this;
//	else
//	{
//		delete m_ps;
//		m_ps = new std::string(*rhs.m_ps);
//		m_value = rhs.m_value;
//		return *this;
//	}
//}

int main()
{
	ObjectPtr a{ "hello", 42 };
	ObjectPtr b{ a };
	ObjectPtr c{"xxxxx", 23214 };

	c = c;

	std::cout << c << "\n";
	std::cout << a << "\n";

	return 0;
}