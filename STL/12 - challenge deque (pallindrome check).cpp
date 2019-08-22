#include <iostream>
#include <deque>
#include <algorithm>
#include <cctype> 
#include <vector>
#include <iomanip>
#include <string>


//write a function using deque to figure out if a string is a palindrome. put couple of string into vector and process them all

bool is_palindrome(std::string const& s)
{
	std::deque<char> d;

	for (auto const& i : s)
		if(std::isalpha(i)) d.push_back(std::toupper(i));

	while (d.size() > 1)
		if (d.front() == d.back())
		{
			d.pop_back();
			d.pop_front();
		}
		else return false;
	return true;
}

//works only for alnum characters
bool is_palindr(std::string const& s)
{
	for (size_t i = 0; i < s.size(); ++i)
		if (s[i] != s.size() - 1) 
			return false;
	return true;	
}



int main()
{
	std::vector<std::string> v{ "hello", "pallindrom", "jelenovi pivo nelej", "radar", "santa at nasa", "something else" };

	std::cout << std::boolalpha;
	std::cout << std::setw(50) << std::left << "WORD" << "IS PALINDROME?" << "\n";

	for(auto i : v) 
		std::cout << std::setw(50) << std::left << i << is_palindrome(i) << "\n";

	return 0;
}