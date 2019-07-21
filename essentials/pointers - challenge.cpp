#include <iostream>


void display(int const *const arr, size_t const size) //nebo void display(int []arr, int size)
{
	for (size_t i = 0; i < size; ++i) std::cout << arr[i] << "\n";
}


int* apply_all(int const *const arr1, size_t const size_arr1, int const *const arr2, size_t const size_arr2)
{
	size_t new_array_size{size_arr1 * size_arr2};
	int* new_array = new int[new_array_size];
	unsigned int index = 0;

	for (size_t i = 0; i < size_arr1; ++i)
	{
		for (size_t j = 0; j < size_arr2; ++j)
		{
			new_array[index++] = arr1[i] * arr2[j]; // 
		}
	}
	return new_array;
}





int main()
{
	int arr1[]{ 1,2,3,4,5 };
	int arr2[]{ 11,22,33,44,55 };

	size_t arr1_size = sizeof(arr1) / sizeof(arr1[0]);
	size_t arr2_size = sizeof(arr2) / sizeof(arr2[0]);

	int* my_array{ nullptr };


	display(arr1, arr1_size);
	std::cout << "----------------------\n";
	display(arr2, arr2_size);
	std::cout << "----------------------\n";
		
	apply_all(arr1, arr1_size, arr2, arr2_size);
	my_array = apply_all(arr1, arr1_size, arr2, arr2_size);
	display(my_array, arr1_size * arr2_size);

	delete [] my_array;

	return 0;
}