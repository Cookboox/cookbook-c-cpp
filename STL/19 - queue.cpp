#include <iostream>
#include <list>
#include <queue>
#include <vector>

//FIFO data structure, basicallz a waiting line
//implemented as an adapter to underlying container that support front and back (list or deque)
//elements are pushed at the back and popped at the front
//no iterators are supported

//methods similar to stack:
// - push -insert elem at the back
// - pop - removes elem from the front
// - front - access the element at the 
// - back - acces at the back
// - empty, size

//it is used for scheduling, job scheduling, task scheduling in OS

template<typename T>
void display(std::queue<T> q)
{	
	std::cout << "[ ";
	while (!q.empty())
	{
		std::cout << q.front();
		q.pop();
		std::cout << " ";
	}
	std::cout << "]\n";
}


std::queue<int> q; //defaults to deque underlying container 
std::queue<int, std::list<int>> ql; //i can choose the underlying container explicitly
std::queue<int, std::deque<int>> qd; //i can choose the underlying container explicitly

//BEWARE - cant be initialized directy !!
//std::queue<int> q1{ 1,2,3,4 }; //error cannot convert initialize list..

int main()
{
	//inicialisatuion only via push
	for (int i : {1, 2, 3, 4, 5}) q.push(i);
	display(q);

	std::cout << "first is: " << q.front() << "\n";
	std::cout << "last is: " << q.back() << "\n";

	q.push(100);
	display(q);

	//since i have access to front and back i can change them
	q.front() = 99;
	q.back() = 99;
	display(q);

	//clearing out happens poping each after another
	while (!q.empty()) q.pop();
	display(q);

	//inicialize from vector
	std::vector<int> v(10); 
	for (const auto& i : v) q.push(i);
	display(q);

	std::cout << "size of queue is: " << q.size() << "\n";
	return 0;
}