#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>

//fixed size array (size must be known at compile time)
//it is an object and all iterators and algorithms are accessible. iterators never invalidate because it is fixed sized structure
//doesnt decay to a pointer when we pass it as an argument to a function
//raw pointer can be obtained when needed
//constant time for element access!! 
//always use std::array instead of raw array

void display(std::array<int, 5> const& arr)
{
	std::cout << "[";
	for (int const& i : arr) std::cout << i << " ";
	std::cout << "]\n";
}

void foo1()
{
	std::array<int, 5> arr1{ 1, 2, 3, 4, 5 };
	std::array<int, 5> arr2{ }; //all will be zero

	display(arr1);
	display(arr2);

	arr2 = { 1,1,1,1,1 }; //assignement using initialization list
	display(arr2);

	std::cout << "size of array 1: " << arr1.size() << "\n";
	std::cout << "size of array 2: " << arr2.size() << "\n";

	//direct access returns reference --> i can change the value
	arr1[0] = 99; //low level no bound checking
	arr2.at(0) = 99; //bound checking
	arr1.back() = 1000; //direct access to the last one
	
	display(arr1);
	display(arr2);

	arr1.swap(arr2);
	display(arr1);
	display(arr2);

}

void foo2()
{
	std::array<int, 5> arr1{ 1, 2, 3, 4, 5 };
	std::array<int, 5> arr2{ }; //all will be zero

	arr2.fill(44);
	display(arr1);
	display(arr2);
}

//transposing std::array into raw array
void foo3() 
{
	std::array<int, 5> arr{ 1,2,3,4,5 };

	int* const ptr = arr.data(); //this method returns raw array (const pointer)

	std::cout << ptr << " : " << *ptr << "\n";

	*ptr = 99;

	std::cout << ptr << " : " << *ptr << "\n";

	for (int i = 0; i < arr.size(); ++i)
	{
		ptr[i] = 108;
		std::cout << *ptr << "\n";
	}

	display(arr);
}

//using some algorithms with array
void foo4()
{
	std::array<int, 5> arr{ 3,94,94,32,41 };
	display(arr);

	//inplace sort from highest to lowest
	std::sort(arr.rbegin(), arr.rend());
	display(arr);

	//highest and lowest element
	auto min = std::min_element(arr.begin(), arr.end());
	std::cout << "minimum element: " <<*min << "\n";
	std::array<int, 5>::iterator max = std::max_element(arr.begin(), arr.end());
	std::cout << "maximum element: "<< *max << "\n";

	//returns the greater of the two values 
	auto x = std::max(*arr.begin(), *(arr.end() - 1));
	std::cout << "greater of the two: " << x << "\n";

	//find adjacement values
	auto adj = std::adjacent_find(arr.begin(), arr.end());
	std::cout << "first adjacemenet values are: " << *adj << "\n";
}

int main()
{
	//foo1();
	//foo2();
	//foo3();
	foo4();

	return 0;
}