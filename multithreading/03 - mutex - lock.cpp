#include <iostream>
#include <thread>


//mutex is MUTual EXclusion
// first thread works on a particular data, then second thread, then again first thread, then again second  etc..


//RACE condition:
//one piece of common data and two or more threads -- these are racing to MODIFY these data.. if htey just want to acces that data,
//there is no race condition



int x{0}; //common data

void increment() { ++x; } //thread function

int main()
{
	//race condition
	std::thread t1(increment); 
	std::thread t2(increment);

	t1.join();
	t2.join();

	std::cout << x << "\n";
	return 0;
}