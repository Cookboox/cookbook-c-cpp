#include<iostream>

class String
{
	friend std::ostream& operator<<(std::ostream& os, const String& rhs);
	friend std::istream& operator>>(std::istream& is, String& rhs);

private:
	char* s;
	int x;
public:
	String() = default;
	//..
	~String() { delete s; }
};

std::ostream& operator<<(std::ostream& os, const String& rhs)
{
	os << rhs.s << " " << rhs.x;
	return os;
}

std::istream& operator>>(std::istream& is, String& rhs)
{
	char *buff = new char[10];
	is >> buff >> rhs.x;	
	rhs.s = buff;
	//delete[] buff; // i cant delete here, the destructor is responsible for deleting 
	return is;
}

int main()
{
	String one;

	std::cin >> one;
	std::cout << one;

	return 0;
}