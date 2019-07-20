#include <iostream>

class Foo
{
public:
	Foo() { std::cout << "construct Foo\n"; }
	~Foo() { std::cout << "destruct Foo\n"; }
};

struct Bar
{
	Bar() { std::cout << "construct Bar\n"; }
	~Bar() { std::cout << "destruct Bar\n"; }
};

void no_leak()
{
	int* int_ptr{ new int{32} };
	// use int__ptr
	delete int_ptr;

	Bar* bar_ptr{ new Bar };
	// use bar
	delete bar_ptr;

	Foo* foo_ptr{ new Foo };
	// use Foo
	delete foo_ptr;
}

void leak_memo()
{
	int* int_ptr{ new int{33} };
	// use int_ptr
	
	Bar* bar_ptr{ new Bar };
	// use bar

	Foo* foo_ptr{ new Foo };
	// use Foo

} // no delete -->leak all!! int and Bar and Foo

void no_leak_arr()
{
	int size = 5;
	int* int_ptr_arr{ new int[size] };
	// use int_ptr_arr
	for (int i = 0; i < size; ++i) 
	{
		int_ptr_arr[i] = 0;  
		std::cout << int_ptr_arr[i] << "\n";
	}
	delete[] int_ptr_arr;	



	Foo* foo_ptr_arr{ new Foo[5] };
	// use foo_ptr_arr
	delete[] foo_ptr_arr;
}

void leak_memo_arr()
{
	int size = 5;
	int* int_ptr_arr{ new int[size] };
	// use int_ptr_arr
	for (int i = 0; i < size; ++i)
	{
		int_ptr_arr[i] = 0;
		std::cout << int_ptr_arr[i] << "\n";
	}


	Foo* foo_ptr_arr{ new Foo[5] };
	// use foo_ptr_arr
}// --> no delete, no destructor called --> leak





int main()
{
	no_leak();;
	leak_memo();
	
	no_leak_arr();
	leak_memo_arr();
	
	return 0;
}