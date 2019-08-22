#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include <set>
#include <iomanip>

//accepts and returns reference becaue it will be callend inside of a function where the word will be declared
std::string& clean_words(std::string& s)
{
	if (s.at(s.size() - 1) == '.' || s.at(s.size() - 1) == ',') 
		s.erase(s.end() - 1);
	return s;
}

std::map<std::string, int> word_counter()
{
	std::ifstream source{ "file.txt" };
	std::string word_read;
	std::map<std::string, int> dictionary;

	if (!source) std::cerr << "error source file\n";
	while (source >> word_read)
	{
		word_read = clean_words(word_read);
		++dictionary[word_read];
	}	
	source.close();
	return dictionary;
}

void display_map(std::map<std::string,int> const &m)
{
	std::cout << std::setw(15) << std::right << "WORD" << " : " << "COUNTER" << "\n" << std::endl;
	std::cout << std::setw(100) << std::setfill('-') << "\n";
	std::cout << std::setfill(' ');

	for (auto const& pair : m)
		std::cout << std::setw(15) << std::right << pair.first << " : " << pair.second << "\n";
}

std::set<int> find_on_which_lines_the_word_occurs(std::string word_passed)
{
	int line_counter{};
	std::set<int> set_of_line_numbers{};
	std::string line;
	std::string word_from_line;
	std::ifstream source{ "file.txt" };
	
	if (!source) std::cout << "fail source file\n";
	else
	{
		while (std::getline(source, line))
		{
			++line_counter;
			std::stringstream ss{ line };

			while(ss >> word_from_line)
			{
				if (word_from_line == word_passed)
					set_of_line_numbers.insert(line_counter);
			}
		}
	}
	source.close();
	return set_of_line_numbers;
}

void display_set(std::set<int> const& s)
{		
	std::cout << "[ ";
	for (auto const& i : s) std::cout << i << " ";	
	std::cout << "]\n";
}

std::map<std::string, std::set<int>> word_counter_with_line_numbers()
{
	std::ifstream source{ "file.txt" };
	std::map<std::string, std::set<int>> dictionary;
	std::string line;
	std::string word;
	int line_counter{ 0 };
	   
	if (!source) std::cout << "error opening file\n";
	while (std::getline(source, line))
	{
		++line_counter;
		std::stringstream ss{ line };
		while (ss >> word)
		{
			word = clean_words(word);
			dictionary[word].insert(line_counter);
		}
	}
	source.close();
	return dictionary;
}

void display_map(std::map<std::string, std::set<int>> const& dict)
{
	std::cout << std::setw(15) << std::right << "WORD" << " : " << "OCCURENCES" << "\n";
	std::cout << std::setw(100) << std::setfill('-') << "\n";
	std::cout << std::setfill(' ');

	for (auto const &dict_pair : dict)
	{
		std::cout << std::setw(15) << std::right << dict_pair.first << " [ ";
		for (auto set_elem : dict_pair.second)
		{
			std::cout << set_elem << " ";
		}
		std::cout << "]\n";
	}
}

int main()
{
	std::map<std::string, int> m = word_counter();
	display_map(m);
	
	std::cout << std::endl;

	std::map<std::string, std::set<int>> dict = word_counter_with_line_numbers();
	display_map(dict);

	´´
	return 0;
}