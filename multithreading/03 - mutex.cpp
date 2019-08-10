#include <iostream>
#include <thread>
#include <mutex>

//mutex is MUTual EXclusion
// first thread works on a particular data, then second thread, then again first thread, then again second  etc..
// mutext is used to avoid race condition
// we use lock() and unock()


//RACE condition:
//one piece of common data and two or more threads -- these are racing to MODIFY these data.. if htey just want to acces that data,
//there is no race condition

//the problem with changing common data by two or more threads is due to the process how values are changes 
// the stages:
// 1) load
// 2) increment
// 3) store
// if both threads load the original value at the same time, the processing of the data will be innacurate


int x{0}; //common data
std::mutex m;

void increment() 
{ 
	//first thread will lock the data, the other thread is blocked
	m.lock();
	++x; //critical section --> mutex is needed to wrap it
	m.unlock();
	//after unlock, the other thread can lock it
} 

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