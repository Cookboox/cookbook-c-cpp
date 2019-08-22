#include <iostream>
#include <list>
#include <algorithm>
#include <string>
#include <iterator>   //std::advance

//LIST
//sequence container, non contiguous memory
//no direct access to element
//constant time for inserting and deleting wherever needed
//all itertor available and may invalidate when element is deleted using iterator obtained from find()
//bi-directional (++, --) 

//KEY METHODS:
//l.size()
//l.front(), l.back()
//push_back(), push_front()
//pop_back(), pop_front()
//emplace(), emplace_back(), emplace_front()
//insert() //inserts before particular iterator

//--------------------------------------------------------------//

//FORWARD LIST
//sequence container, non contiguous memory
//no direct access to element
//constant time for inserting and deleting wherever needed
//only some itertors available (no reverse iterators) and may invalidate when element is deleted using iterator obtained from find()
//uni-directional (++) 
//less overhead then list

//KEY METHODS:
//fl.size() //NOT AVAILABLE
//fl.back() //NOT AVAILABLE
//front(), pop_front(), push_front(), emplace_front() 
//insert_after() //

//WHEN USE?
//when u will need ot add and remove elements very often --> iphone contact list

class Person
{
	friend std::ostream& operator<<(std::ostream& os, Person const& p)
	{
		os << p.name << ":" << p.age;
		return os;
	}
private:
	std::string name;
	unsigned int age;
public:
	Person(std::string name = "unknown", unsigned int age = 0) : name{ name }, age{ age } {} //default constructor
	~Person() = default;
	bool operator<(Person const& other) const { return this->age < other.age; }
	bool operator==(Person const& other) const { return this->age == other.age && this->name == other.name; }
	unsigned int get_age() { return age; }
};

template<typename T>
void display(std::list<T> const& l)
{
	std::cout << "[ ";
	for (auto const& i : l) std::cout << i << " ";
	std::cout << "]\n";
}

//common methods
void foo()
{
	std::list<int> l1{ 1,2,3,4,5 };
	std::list<int> l2{ 11,22,33,44,55 };
	display(l1);

	l1.push_back(6);
	l1.push_front(0);
	display(l1);

	l1.emplace_back(7);
	l1.emplace_front(-1);
	display(l1);

	l1.emplace(std::find(l1.cbegin(), l1.cend(), 3), 99);
	display(l1);

	l1.insert(std::find(l1.cbegin(), l1.cend(), 3), 88);
	display(l1);

	l1.reverse();
	display(l1);

	l1.remove(99);
	l1.remove(88);
	display(l1);

	l1.remove_if([](int a) {return a > 0; });
	display(l1);

	l1.splice(l1.begin(), l2);
	display(l1);

}

//resize -> calling default constructor for objects
void foo2()
{
	std::list<int> l1{ 1,2,3,4,5,6,7,8,9,10 };
	l1.resize(5);
	l1.resize(10);
	display(l1);

	std::list<Person> l2;
	l2.resize(4);
	display(l2);
}

//findind, inserting..
void foo3()
{
	std::list<int>l{ 1,2,3,4,5,6,7,8 };

	auto it = std::find(l.cbegin(), l.cend(), 5);
	if (it != l.cend())
		l.insert(it, 99);
	display(l);

	std::advance(it, +2); //move two elems front 

	if (it != l.cend())
		l.insert(it, 99);
	display(l);

	std::advance(it, -4); //move 4 elems back 

	if (it != l.cend())
		l.insert(it, 10000);
	display(l);

	l.erase(it); //now iterator invalidated
	display(l);
}

//emplacing custom objects, sorting
void foo4()
{
	std::list<Person> l{ Person{"paul",21}, Person{"mark", 32}, Person{"joe", 31} };
	display(l);

	l.emplace_front("ayse", 32);
	l.emplace_back("senna", 21);
	display(l);


	std::string name;
	unsigned int age;
	std::cout << "enter name of another guy to the list\n";
	std::cin >> name;
	std::cout << "enter age of another guy to the list\n";
	std::cin >> age;
	l.emplace_back(name, age);
	display(l);

	std::cout << "enter name of another guy to the list\n";
	std::cin >> name;
	std::cout << "enter age of another guy to the list\n";
	std::cin >> age;
	l.emplace_front(name, age);
	display(l);

	std::cout << "enter name of another guy to the list\n";
	std::cin >> name;
	std::cout << "enter age of another guy to the list\n";
	std::cin >> age;
	auto it = std::find(l.begin(), l.end(), Person{ "mark", 32 });
	l.emplace(it, name, age);
	display(l);

	l.remove_if([](Person a) {return a.get_age() > 50; });
	display(l);	

	l.sort();
	display(l);
}

//merging two sorted lists
void foo5()
{
	std::list<int> l1{ 8,3,2,5,1,3,5,2 };
	std::list<int> l2{ 48,43,32,25,21,13,5,12 };
	
	//l1.merge(l2);// error --> need to be sorted first

	l1.sort();
	l2.sort();
	l1.merge(l2);

	display(l1);
}

int main()
{
	//foo();
	//foo2();
	//foo3();
	//foo4();
	foo5();
	return 0;
}