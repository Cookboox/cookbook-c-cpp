#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <map>

//dynamically sized array, handled automatically, expands and contracts as needed
//elements are stored in contiguous memory as with array
//constant time for direct access and insertion and deletion at the back
//linear time when inserting or removing -->ineficient
//all iteratores available, may invalidate

//KEY METHODS:
//v.push_back(x) --> makes a copy of x
//v.emplace_back(x) --> constructs it in the container --> more efficient

class Person
{
	friend std::ostream& operator<<(std::ostream& os, Person const& p)
	{
		os << p.name << ":" << p.age;
		return os;
	}
private:
	std::string name;
	int age;

	std::pair<std::string, int> pair;
public:
	Person(std::string name, int age) :name{ name }, age{ age } {pair.first = name, pair.second = age; }
	~Person() = default;
	bool operator<(Person const& other) const noexcept { return this->age < other.age; }
	bool operator==(Person const& other) const noexcept { return (this->age == other.age && this->name == other.name); }

	void get_pair() { std::cout << pair.first << "|" << pair.second << "\n"; };
};

template<typename T>
void display_using_foreach(std::vector<T> const& v)
{
	std::cout << "[ ";
	std::for_each(v.begin(), v.end(), [](T a) {std::cout << a << " "; });
	std::cout << "]\n";
}

template<typename T>
void display(std::vector<T> const& v)
{
	std::cout << "[ ";
	for (auto& i : v) std::cout << i << " ";
	std::cout << "]\n";
}

//basic operations
void foo1()
{
	std::vector<int> v{ 1,2,3 };
	display(v);

	v.assign({ 1,2,3,4,5, });
	display(v);

	v = { 10,20,30 }; //same as above
	display(v);

	std::cout << "capacity: " << v.capacity() << "\n";
	std::cout << "size: " << v.size() << "\n";

	v.push_back(1);
	v.push_back(1);
	v.push_back(v.at(0));
	display(v);
	
	std::cout << "capacity: " << v.capacity() << "\n";
	std::cout << "size: " << v.size() << "\n";
	
	v.reserve(100);
	display(v);
	std::cout << "capacity: " << v.capacity() << "\n";
	std::cout << "size: " << v.size() << "\n";

	v.shrink_to_fit();
	display(v);
	std::cout << "capacity: " << v.capacity() << "\n";
	std::cout << "size: " << v.size() << "\n";
}

//getting pointer from underlying array
void foo2()
{
	std::vector<int> v{ 1,2,3 };

	int* ptr = v.data(); //returns a pointer
	std::cout << ptr << ":" << *ptr << "\n";

	//now i can use it as raw array
	for (unsigned int i = 0; i < v.size(); ++i)
	{
		*ptr = 99;
		std::cout << ptr[i] << "\n";
	}

	display(v);
}

//working with custom classes
void foo3()
{
	std::vector<Person> v;
	Person p1{ "mike", 32 };
	display(v);

	v.push_back(p1); //using copy constructor from already existing object
	display(v);

	v.push_back(Person{ "paul",35 }); //using move semantics <-- construction of unnamed object
	display(v);

	v.emplace_back("lary", 34); //directly constructs the element in place at the back of container
	display(v);

	v.emplace(v.cbegin() + 1, Person{ "mark", 39 }); //directly constructs the element in place at the particular position of container 
	display(v);

	//just checking if the  datas are stored correctly..
	for (auto i : v) i.get_pair();
}

//inserting 
void foo4()
{
	std::vector<int> v1{ 1,2,3,4,5 };
	std::vector<int> v2{ 11,22,33,44,55 };
	display(v1);
	display(v2);

	//insert v2 after 3 in v1
	//auto it = std::find(v1.begin(), v1.end(), 3);
	v1.insert(std::find(v1.begin(), v1.end(), 3), v2.begin(), v2.end()); //one-liner :-)
	display(v1);
}

//copying, copy_ifing
void foo5()
{

	std::vector<int>v1{ 1,2,3,4,5,6,7 };
	std::vector<int>v2{ 10,20 };

	//copy all v1 into v2
	std::copy(v1.begin(), v1.end(), std::back_inserter(v2));
	display(v2);


	v1 = { 1,2,3,4,5,6,7 };
	v2 = { 10,20 };

	//copy odd elements into v2
	std::copy_if(v1.begin(), v1.end(), std::back_inserter(v2), [](int a) {return a % 2 != 0; });
	display(v2);
}

//transforming --> created zip function :-)
void foo6()
{
	std::vector<int> v1{ 1,2,3,4,5 };
	std::vector<int> v2{ 11,22,33,44,55 };
	std::vector<std::pair<int, int>> pairs;

	std::transform(v1.begin(), v1.end(), v2.begin(), std::back_inserter(pairs), [](int a, int b) {return std::make_pair(a, b); });

	for (auto const &i : pairs)  std::cout << "(" << i.first << ":" << i.second << ")" <<  " ";
}

int main()
{
	//foo1();
	//foo2();
	//foo3();
	//foo4();
	//foo5();
	foo6();
	return 0;
}