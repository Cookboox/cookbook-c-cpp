
#include <iostream>
#include <thread>
#include <mutex>

//mutex::lock() is a blocking call, if a mutex is already locked, the other thread is blocked and WAITS
//mutex::try_lock() is a nonblocking call, if a mutex is already locked, the other thread is non blocked but tries to lock it again in some time
//it returns immediatelly, meaning it will not get blocekd. on succesfull lock returns true, else returns false
//locking the mutext again by the same thread leads to undefined behaviour --> if you need to lock it again with the same thread, go for recursive mutex
//try_lock is generaly used at loops when there is the need to repeatedly try to lock the thread and it should always be in if()
//lock should never be used in if, since it is not convertible to booltype

int x{ 0 };
std::mutex m;

//if both threads are incrementing 1000 times, it looks obvioous the result should be 2000 but it is not, because they are not waiting to each other.
//so if one thread locked the data and was incrementing, the other thread skiped the cycle and tried again in the next cyckle, maybe it got the lock,
//maybe not,.. but this way both threads were locking and unlocking while and skiping the cycles --> that is why the final increment is les than the sum of each
void increment_1000_times_trylock()
{
	for (int i = 0; i < 1000; ++i)
	{
		if (m.try_lock()) // try_lock is convertible to booltype --> used in if
		{
			++x;
			m.unlock();	
		}
	}
}


//if i use lock, the increment will be the sum of both
void increment_1000_times_lock()
{
	for (int i = 0; i < 1000; ++i)
	{
		m.lock(); // lock is not convertible to booltype --> not used in if
		++x;
		m.unlock();
	}
}



int main()
{
	std::thread t1(increment_1000_times_lock);
	std::thread t2(increment_1000_times_lock);

	t1.join();
	t2.join();

	std::cout << x;
	return 0;
}