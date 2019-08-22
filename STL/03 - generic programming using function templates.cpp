#include <iostream>
#include <string>

//support for function and class templates
//templates is about writing a blueprint
//this is done at COMPILE TIME, the code for each T version is generated when the particular version is needed

template<typename T>
T max(T a, T b) { return (a > b) ? a : b; }


struct Person
{
	std::string name;
	int age;
	bool operator>(Person const& rhs)
	{
		if (rhs.age > this->age) return true;
		else return false;
	}
};

std::ostream& operator<<(std::ostream &os, Person const& rhs)
{
	os << rhs.name << " " << rhs.age;
	return os;
}

Person p1{ "Lukas", 32 };
Person p2{ "Marek", 43 };




int main()
{
	std::cout << "-----primitive types one type-------------------\n";

	std::cout << max<int>(1, 2) << "\n"; // the code for int is generated here NOT EARLIER
	std::cout << max<float>(1.11f, 2.22f) << "\n"; // the code for float is generated here NOT EARLIER
	std::cout << max(1.11, 2.22) << "\n"; // the code for doubl is generated here NOT EARLIER
	std::cout << max('s', 'f') << "\n"; // the code for char is generated here NOT EARLIER
	
	std::cout << "-----nonprimitive types one type-------------------\n";

	Person p3 = (p1, p2);
	std::cout << p3 << "\n";


	return 0;
}