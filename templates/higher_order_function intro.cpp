#include <iostream>
#include <vector>
#include <string>
#include <chrono>

std::vector<int> vi{ 1,2,3,4,5 };
std::vector<std::string> vs{ "ja", "ty", "my", "vy" };

template<typename T>
void print_without_ened_coma(const std::vector<T>& v)
{
	if (std::empty(v)) { return; }
	std::cout << *v.begin(); //printing

	for (auto it = std::next(v.begin()); it != v.end(); ++it)
	{
		std::cout << ", ", //separating
		std::cout << *it; //separating
	}
}

template<typename T>
void print(const std::vector<T>& v) 
{
	for (auto i : v)
		std::cout << i << ", ";
}

// making it more generalized with this template
// this will abstract out the control flow logic
// it is reusable
template<typename Range, typename Printing, typename Separating>
void make_separated(Range&& range, Printing&& print, Separating&& separate)
{
	if (std::empty(range)) { return; }
	print(*range.begin());

	for (auto it = std::next(range.begin()); it != range.end(); ++it)
	{
		separate();
		print(*it);
	}
}

//and now i can overload and use
template<typename T>
void new_print(const std::vector<T>& v)
{
	make_separated(v, [](const auto& x) {std::cout << x; }, []() {std::cout << ", "; });
}

void new_print(const std::string& s)
{
	make_separated(s, [](const auto& x) {std::cout << x; }, []() {std::cout << ", "; });
}

template<typename T>
void new_print(std::initializer_list<T> ilist)
{
	make_separated(ilist, [](const auto& x) {std::cout << x; }, []() {std::cout << ", "; });
}




/*simple benchamrk as HOF*/
template<typename T>
auto benchmark(T&& func)
{
	const auto t = std::chrono::high_resolution_clock::now();
	func();
	return std::chrono::high_resolution_clock::now() - t;
}



int main()
{
	//print(vi);
	//print_without_ened_coma(vi);

	//new_print({ 2134,2414,5345,63245,53 });
	//new_print({ "dsad", "sdsada", "sdsada", "sdada", "sdsa" });
	//new_print(vi);
	//new_print(vs);
	
	std::chrono::duration<double> x = benchmark([]() {std::cout << "hello\n"; });
	std::cout << x.count();


	return 0;
}