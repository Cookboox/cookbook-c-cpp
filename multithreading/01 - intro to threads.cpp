

// thread needs a callable object, there are 5 ways to create threads in c++ - all have their own syntax
// 1. function poinbters
// 2. lambda function
// 3. functors
// 4. member functions
// 5. static member function



// EXAMPLE: find the sum of all even numbers and all odd number in the given range (0-1000000) 

#include <iostream>
#include <thread>
#include <chrono> //for measuring benchmarks

typedef unsigned long long ull;
ull sum_odd{};
ull sum_even{};

//function calculating sum of even numbers
ull get_sum_even(unsigned int start, unsigned int stop)
{
	for (size_t i = start; i <= stop; ++i)
	{
		if (i % 2 == 0)	{ sum_even += i; }		
	}
	return sum_even;
}

//function calculating sum of odd numbers
ull get_sum_odd(unsigned int start, unsigned int stop)
{
	for (size_t i = start; i <= stop; ++i)
	{
		if (i % 2 != 0) { sum_odd += i; }
	}
	return sum_odd;
}


int main()
{
	//--------- without threading -----------
	auto t1 = std::chrono::high_resolution_clock::now();

	unsigned int start = 0;
	unsigned int stop = 1000000;

	get_sum_even(start, stop);
	get_sum_odd(start, stop);

	auto t2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> elapsed = t2 - t1;
	 
	std::cout << "without threading \n";
	std::cout << "sum even: " << sum_even << " sum odd: " << sum_odd << "\n";
	std::cout << "operation took: " << elapsed.count() << " milieconds. \n";


	
	//--------- with threading ---------

	auto tt1 = std::chrono::high_resolution_clock::now();

	std::thread first_thread(get_sum_even, 1, 10); // here i am constructing a thread, passing function pointer as a parametr
	std::thread second_thread(get_sum_odd, 1, 10);

	first_thread.join(); // join() means the main thread waits till all work from first_thread is finished
	second_thread.join(); 

	auto tt2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> elapsed_threading = tt2 - tt1;

	std::cout << "with threading \n";
	std::cout << "sum even: " << sum_even << " sum odd: " << sum_odd << "\n";
	std::cout << "operation took: " << elapsed_threading.count() << " milieconds. \n";

	   



	return 0;
} 