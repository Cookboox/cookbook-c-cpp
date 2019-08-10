#include <iostream>
#include <thread>
#include <chrono>

//JOIN
//join() means once a thread is started, we wait for the thread to finish by calling join()
//double join is an error and terminates the program --> better to always check if is joinable()

//DETACH
//the opposite of join, the program doesnt wait for the main tread to be finished
//used to detach newly created thread from parrent thread
//double detach leads to program termination


//on a newly created thread you have to call either JOIN or DETACH. you cannot leave it without

void foo(int a) 
{
	while (a != 0) std::cout << a-- << "\n"; 
	std::this_thread::sleep_for(std::chrono::seconds(5)); //simulationg the thread will do its job for 5 second
	std::cout << "thread finished\n";
}


void use_join()
{

	std::thread t(foo, 10);
	std::cout << "use_join() before thread finished...\n";

	if(t.joinable()) 
		t.join(); //here it will wait 5 seconds

	std::cout << "use_join() after thread finished...\n";

	if(t.joinable())
		t.join(); //would fail --> check if isjoinable()
}

void use_detach()
{
	std::thread t(foo, 20);
	std::cout << "use_detach() before thread finished...\n";
	t.detach();

	if(t.joinable())
		t.detach();
	std::cout << "use_detach() after thread finished...\n";
}


int main()
{
	use_join();  // here we are waiting for the thread so all the work of the thread will be done, the program will not exit before it is completely done;
	
	use_detach(); // here we are not waiting for the thread so the main can actually finish earlier and the work of thread will not be done completely 
	
	for (int i = 0; i < 10; ++i) std::cout << "processing something..\n"; // it really depends how comples is the work in parrent therad
	return 0;
}