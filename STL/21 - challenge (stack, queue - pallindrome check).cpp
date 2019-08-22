#include <iostream>
#include <stack>
#include <queue>
#include <cctype>
#include <string>
#include <vector>
#include <iomanip>

bool is_pallindrome(std::string const& s)
{
	std::stack<char> stack_string;
	std::queue<char> queue_string;

 	for (auto& i : s)
	{
		if (std::isalpha(i))
		{
			stack_string.push(std::tolower(i));
			queue_string.push(std::tolower(i));
		}
	}
	
	while (!stack_string.empty())
	{
		if (stack_string.top() != queue_string.front())
			return false;
		else
		{
			stack_string.pop();
			queue_string.pop();
		}
	}	
	return true;
}

template<typename T>
void display(std::vector<T> const& v)
{
	std::cout << std::setw(30) << std::right << "PHRASE:" << " : " << std::setw(30) << std::left << "IS PALINDROME?" << std::endl;
	std::cout << std::setw(60) << std::right << std::setfill('-') << "" << std::setfill(' ') << std::endl;

	for (auto const& word : v)
	{
		std::cout << std::boolalpha << std::setw(30) << std::right << word << " : "
									<< std::setw(30) << std::left << is_pallindrome(word) << "\n";
	}
}

int main()
{
	std::vector<char const*> words{ "ahoj", "jelenovi pivo nelej","madam", "orrarrarro", "pallindrome", "C++", "bob", "radar" };
	display(words);

	return 0;
}