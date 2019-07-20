#include <iostream>

void print_values_using_arr_signature()
{
	int arr[]{ 92, 45, 34, 6, 77, 0 };

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
	{
		std::cout << "address: " << arr + i << "\t" << "value: " << *(arr + i) << "\n";
	}

	/*while (*arr != 0)
	{
		std::cout << "address: " << arr << "\t" << "value: " << *arr << "\n";
		arr++;
	}*/
}

void print_values_using_ptr_signature()
{
	int arr[]{ 92, 45, 34, 6, 77, 0 };
	int* arr_ptr{ arr };

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
	{
		std::cout << "address: " << arr_ptr + i << "\t" << "value: " << *(arr_ptr + i) << "\n";
	}


	while (*arr_ptr != 0)
	{
		std::cout << "address: " << arr_ptr << "\t" << "value: " << *arr_ptr << "\n";
		arr_ptr++;
	}
}

void first_derecerence_then_incerement()
{
	int arr[]{ 92, 45, 34, 6, 77, 0 };
	int* arr_ptr{ arr };

	while (*arr_ptr != 0)
	{
		std::cout << "address: " << arr_ptr << "\t" << "value: " << *arr_ptr++ << "\n"; // leaves the last nonprinted
	}
}


void first_increment_then_dereference()
{
	int arr[]{ 92, 45, 34, 6, 77, 0 };
	int* arr_ptr{ arr };

	while (*arr_ptr != 0)
	{
		std::cout << "address: " << arr_ptr << "\t" << "value: " << *++arr_ptr << "\n"; // this will skip the first one, but prints the last
	}
}

#include <string>
#include <vector>
void compare_addreses_and_values()
{
	std::string s1 = { "lukas" };
	std::string s2 = { "petr" };
	std::string s3 = { "marek" };
	std::string s4 = { "frank" };

	std::string *s1_ptr{ &s1 };
	std::string *s2_ptr{ &s2 };
	std::string *s3_ptr{ &s3 };
	std::string *s4_ptr{ &s1 }; // two pointer point to te same object --> potencial danger

	// vector hoding regular values
	std::vector<std::string> v_str{ s1, s2, s3, s4 };
	for (const auto& i : v_str) std::cout << i << "\n";

	// vector hodling pointers
	std::vector<std::string*> v_ptr{ s1_ptr, s2_ptr, s3_ptr, s4_ptr };
	for (const auto& i : v_ptr) std::cout << "address: " << i << " value: " << *i <<"\n";

	std::cout << std::boolalpha;
	std::cout << s1 << "==" << s4 << " --> "<< (s1 == s4)  << "\n";
	std::cout << s1_ptr << "==" << s4_ptr << " --> " << (s1_ptr == s4_ptr) << "\n";

	std::cout << sizeof(std::string) << "\t" << sizeof(s1) << "\t" << sizeof(s1_ptr);

}


int main()
{
	/*print_values_using_arr_signature();
	std::cout << "---------------\n";
	print_values_using_ptr_signature();
	std::cout << "---------------\n";
	first_derecerence_then_incerement();
	std::cout << "---------------\n";
	first_increment_then_dereference();
	*/
	std::cout << "---------------\n";
	std::cout << "---------------\n";


	compare_addreses_and_values();





	return 0;
}