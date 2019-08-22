#include <iostream>
#include <set>
#include <unordered_set>

//ASSOCIATIVE CONTAINERS
//collections alowing fast retrieval using key, implemeted as binary trees or hashmaps
//very efficient operations

//4 types of SETS:
//set, multiset, unordered_set, unordered_multiset

//SET KEYNOTES
//all iterators available and may invalidate
//is sorted
//no duplicates
//no direct access to element
//no front and back
//elements cannot be modified, but erased and added new one

//KEY METHODS:
//s.insert() --> returns std::pait<iterator, bool> indicating where the inserted element was added (or previously was if not added) and true/false if it was or wasnt added
//s.erase(element) //particular element, or iterator
//s.find(element) //not std::find() !!!
//s.count(element) //0,1 is there or not? --> much more useful for multisets

//MULTISET KEYNOTES
//ordered, allowes duplicates

//UNORDERED_SET KEYNOTES
//no reverse iterarots
//elements cannot be modified

//UNORDERED_MULTISET KEYNOTES

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
public:
	Person(std::string name = "unknown", int age = 0) :name{ name }, age{ age }{}
	bool operator<(Person const& other) const noexcept { return this->age < other.age; }
	bool operator==(Person const& other) const noexcept { return this->age == other.age && this->name == other.name; }
};

template<typename T> 
void display(std::set<T>& s)
{
	std::cout << "[ ";
	for (auto const& i : s) std::cout << i << " ";
	std::cout << "]\n";
}

template<typename T>
void display(std::multiset<T>& s)
{
	std::cout << "[ ";
	for (auto const& i : s) std::cout << i << " ";
	std::cout << "]\n";
}

template<typename T>
void display(std::unordered_set<T>& s)
{
	std::cout << "[ ";
	for (auto const& i : s) std::cout << i << " ";
	std::cout << "]\n";
}

template<typename T>
void display(std::unordered_multiset<T>& s)
{
	std::cout << "[ ";
	for (auto const& i : s) std::cout << i << " ";
	std::cout << "]\n";
}


//basic methods
void foo()
{
	std::set<int> s{ 3,4,3,2,6,1,0,101 };
	std::unordered_set<int> us{ 3,4,3,2,6,1,0,1 };
	std::multiset<int> ms{ 3,4,3,2,6,1,0,1 };
	std::unordered_multiset<int> ums{ 3,4,3,2,6,1,0,1 };

	std::cout << "set contains: "; display(s);
	std::cout << "unoredered set contains: "; display(us);
	std::cout << "multiset contains: "; display(ms);
	std::cout << "unordered multiset contains: "; display(ums);

	//check if elem is there
	auto it = s.find(4); //returns iterator
	it != s.end() ? std::cout << "element found\n" : std::cout << "element not found\n";
	s.erase(it); //now i invalidated the iterator
	std::cout << "set contains: "; display(s);
	//it != s.end() ? std::cout << "element found\n" : std::cout << "element not found\n"; //error becaue it is invalid
	
	int count = ms.count(1);
	std::cout << "1 appears " << count << " times\n";


	std::set<int> ss{ 10,20,30,40 };

	//lower_bound
	auto lower = ss.lower_bound(15); //returns iterator pointing to the value not less then the value provided
	std::cout << *lower << "\n";
	
	//upper bound
	auto upper = ss.upper_bound(35); //returns iterator pointing to the first higher value then the value provided
	std::cout << *upper << "\n";

	//equal_range
	auto e_range = ss.equal_range(15); //return std::pair of iterators represented by lower_bound(), upper_bound(),
	std::cout << "lower: " << *e_range.first << " upper: " << *e_range.second << "\n";
}

//custom class emplacing and findind --> possible problems with < == operators
void foo2()
{
	std::set<Person> s{ Person{"joe", 34}, Person{"kayleigh", 32}, Person{"anna", 19} };
	display(s); //sorted by age singe it uses <operator

	s.emplace(Person{ "mark", 20 });
	display(s);

	//here comes the weird part - paul is obviously not the same guy as mark, but since he has the same age, it is treated as same objet (operator< is what comes into play here)
	s.emplace(Person{ "paul", 20 }); 
	display(s);

	//the same problem, no person called pepa --> the guy with teh age 20 witll be returned
	auto it = s.find(Person{ "pepa", 20 });
	if (it != s.end())
		s.erase(it);
	display(s);
}

//inserting --> returnig std::pair
void foo3()
{
	std::set<int> s{ 12,14,27,22 };

	auto check = s.insert(16);
	if (check.second)
		std::cout << "number " << *(check.first) << " inserted \n";
	else
		std::cout << "not inserted, number  " << *(check.first) << " was already there\n";

	check = s.insert(16); //one more time
	if (check.second)
		std::cout << "number " << *(check.first) << "inserted \n";
	else
		std::cout << "not inserted, number  " << *(check.first) << " was already there\n";
}

int main()
{
	//foo();
	//foo2();
	foo3();


	return 0;
}