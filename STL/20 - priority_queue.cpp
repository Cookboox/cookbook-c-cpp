#include <iostream>
#include <queue>
#include <string>

//used very often for prioritizing schedule, tasks etc.. very efficient, stored in a vector but implemented as heap data structure
//the idea is that the highest value is always first (at the top) and when retrieved it goes first

template<typename T>
void display(std::priority_queue<T> pq) //destructive display so no reference
{
	std::cout << "[ ";
	while (!pq.empty())
	{
		std::cout << pq.top();
		pq.pop();
		std::cout << " ";
	}
	std::cout << "]\n";
}

class Person
{
	friend std::ostream& operator<<(std::ostream& os, Person const& rhs)
	{
		os << rhs.name << " : " << rhs.age << "\n";
		return os;
	}
private:
	std::string name;
	int age;
public:
	Person(std::string name, int age) : name{ name }, age{ age } {}
	~Person() = default;

	bool operator<(Person const& other) const
	{
		return (this->age < other.age);
	}
	bool operator==(Person const& other) const
	{
		return (this->age == other.age && this->name == other.name);
	}
};

void foo1()
{
	std::priority_queue<int> pq;
	std::priority_queue<int> pq2;

	for (int i : {3, 4, 5, 29, 45, 99, 1000, 11, 1, 3, 4, 5})
		pq.push(i);

	display(pq);

	pq.pop();
	display(pq);

	std::cout << pq.top() << "\n";

	pq.emplace(0);
	display(pq);

	for (int i : {0, 0, 0, 0, 0})
		pq2.push(i);

	pq.swap(pq2);

	display(pq);
	display(pq2);
}

void foo2()
{
	std::priority_queue<Person> pq;
	pq.push(Person{"Adam", 34});
	pq.push(Person{ "Bob", 21});
	pq.push(Person{ "Charlie", 30 });
	pq.push(Person{ "Dave", 46 });
	pq.push(Person{ "Elien", 64 });
	pq.push(Person{ "Frank", 14 });
	pq.push(Person{ "Gabriel", 33 });
	pq.push(Person{ "Hugo", 24 });

	display(pq);
}

int main()
{
	//foo1();
	foo2();

	return 0;
}