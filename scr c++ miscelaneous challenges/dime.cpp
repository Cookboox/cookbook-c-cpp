#include<iostream>
#include<string>
#include<random>
#include<array>

int rn()
{
	std::random_device dev;
	std::mt19937 mt{ dev() };
	std::uniform_int_distribution<int> distr{ 1,6 };
	return distr(mt);
}


int main()
{
	std::vector<int> results {};

	for (int i = 0; i < 30; ++i) 
	{ 
		std::cout << rn() << ", ";
		results.push_back(rn());
	}

	std::cout << std::endl << std::endl;

	for (int i = 1; i <= 6; ++i) { std::cout << "number " << i << " appeared " << std::count(results.begin(), results.end(), i) << " times"  << "\n" ;}

	return 0;
}
