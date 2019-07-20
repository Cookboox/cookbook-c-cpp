#include <iostream>

//function dynamically allocating an array
int* allocate_array(int const size, int const init_value = 0)
{
	int* ptr = new int[size];
	for (int i = 0; i < size; ++i) { ptr[i] = init_value; }
	return ptr;
}

void display_array(int const arr[], int const size)
{
	for (int i = 0; i < size; ++i) std::cout << arr[i] << "\n";
}

int main()
{
	std::cout << "how many ints do u want?\n";
	int SIZE{};
	std::cin >> SIZE;

	std::cout << "what init value should they be?\n";
	int INIT_VALUE{};
	std::cin >> INIT_VALUE;

	auto* ptr_to_dynamic_arr = allocate_array(SIZE, INIT_VALUE);
	display_array(ptr_to_dynamic_arr, SIZE);
	
	delete[]ptr_to_dynamic_arr;

	return 0;
}