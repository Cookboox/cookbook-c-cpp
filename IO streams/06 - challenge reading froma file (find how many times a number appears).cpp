#include <iostream>
#include <fstream>
#include <string>
#include <utility>

struct Word
{
	int total{0};
	int counter{0};
} return_value;

Word& count_word_occurences(std::string const &passed_word)
{
	std::string word_in_text;
	std::ifstream in_file{ "C:\\Users\\nirvikalpa\\Desktop\\infile.txt" };

	if (!in_file) 
		std::cerr << "error file\n";
	else
	{
		while (!in_file.eof())
		{
			in_file >> word_in_text;
				++return_value.total;
			if (passed_word == word_in_text)
				++return_value.counter;
		}
	}
	return return_value;
}

bool find_substring(std::string const& word_read, std::string const& word_passed)
{
	size_t index = word_read.find(word_passed);
	if (index == std::string::npos) //npos is no position (very big number)
		return false;
	else return true;
}


Word count_word_occurences_with_substrings(std::string const& word_passed)
{
	std::string word_read{};
	std::ifstream in_file{ "C:\\Users\\nirvikalpa\\Desktop\\infile.txt" };

	if (!in_file)
		std::cerr << "error file\n";
	else
	{
		while (in_file >> word_read) //read word by word
		{
				++return_value.total;
			if (find_substring(word_read, word_passed))
				++return_value.counter;
		}
	}
	return return_value;
}


int main()
{
	std::string word;
	std::cout << "Enter the word you want to lookup: \n";
	std::cin >> word;

	//std::cout << "\n--------------WITHOUT SUBSTRINGS----------------------------------------\n";

	//Word result = count_word_occurences(word);
	//
	//std::cout << "Searched in " << result.total << " words\n";
	//std::cout << word << " was found: " << result.counter << " times\n";

	std::cout << "\n--------------WITH SUBSTRINGS----------------------------------------\n";

	Word result2 = count_word_occurences_with_substrings(word);
	std::cout << "Searched in " << result2.total << " words\n";
	std::cout << word << " was found: " << result2.counter << " times\n";


	return 0;
}