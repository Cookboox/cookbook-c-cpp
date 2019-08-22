#include <iostream>

//implement a fixed size array that would :
//-hold any elements
//-be a replacement for raw array
//-support operators
//-be staticly sitting on the stack --> we need to know the number of elements in the compile time, so i want to write like this:  Array<size,type> name;

//instead of template Typename parametr i can pass size as int

template<typename T, size_t N>
class Array
{
	friend std::ostream& operator<<(std::ostream &os, Array<T, N> const& rhs)
	{ 
		os << "[ ";
		for (auto const& i : rhs.values) os << i << " ";
		os << " ]\n" ;
		return os;
	}

private:
	static constexpr size_t size{ N };
	T values[N];
	
public:
	Array<T, N>() = default;
	Array<T, N>(T value) 
	{
		for(int i = 0; i < this->size; ++i) 
			values[i] = value;
	}

	int get_size() const { return this->size; }
	void fill(T value)
	{
		for (int i = 0; i < this->size; ++i) 
			values[i] = value;
	}
	
	T& operator[](int index)
	{
		return values[index];
	}
};




int main()
{
	Array<int, 5> arr;
	std::cout << "size of the array is: " <<  arr.get_size() << "\n";
	std::cout << arr;

	arr.fill(99);
	std::cout << arr;

	arr.fill(88);
	std::cout << arr;

	//using overloaded operator[]
	arr[0] = 100;
	arr[1] = 100;
	std::cout << arr;
	std::cout << arr[1];
	std::cout << "\n";

	//using overloaded constructor taking a value as a parametr
	Array<double, 10> arr10{99.99};
	std::cout << arr10;
	std::cout << "size of the array is: " << arr10.get_size() << "\n";

	Array<std::string, 10> arr_str(std::string{ "xxx" });
	std::cout << arr_str;
	std::cout << "size of the array is: " << arr_str.get_size() << "\n";


	return 0;
}