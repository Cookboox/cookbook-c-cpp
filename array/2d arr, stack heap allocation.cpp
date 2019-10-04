#include <iostream>

//three different ways to create a 2d array

// 1) all on the stack
// 2) partially on the stack, partially on the heap
// 3) all on the heap

// with rising dimensions the posiible combinations rises as well

void all_on_stack()
{
	int A[3][4]; // three rows four columns all on stack, sitting in one memory place


	//fill and display
	int index = 1;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j, ++index)
		{
			A[i][j] = index;
			std::cout << A[i][j] << "\n";
		}
	}
}

void half_on_stack_half_on_heap()
{
	int* A[3]; // array of three pointers sitting on the stack

	for (int i = 0; i < 3; ++i)
	{
		A[i] = new int[4]; // for each of the pointer, allocate new array of four ints on the heap
	}


	//fill and display
	int index = 1;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j, ++index)
		{
			A[i][j] = index;
			std::cout << A[i][j] << "\n";
		}
	}
}

void all_on_heap()
{
	int **A; //double pointer variable A sitting om the stack

	A = new int* [3]; // array of three integer pointer on the heap

	for (int i = 0; i < 3; ++i)
	{
		A[i] = new int[4]; // for each of the pointer, allocate new array of four ints on the heap
	}


	//fill and display
	int index = 1;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j, ++index)
		{
			A[i][j] = index;
			std::cout << A[i][j] << "\n";
		}
	}

}

int main()
{
	all_on_stack();
	half_on_stack_half_on_heap();
	all_on_heap();

	return 0;
}
