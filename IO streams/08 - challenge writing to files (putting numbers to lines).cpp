#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

void add_number_to_each_line()
{
	std::ifstream source{ "C:\\Users\\nirvikalpa\\Desktop\\infile.txt" };
	std::ofstream target{ "C:\\Users\\nirvikalpa\\Desktop\\infile_numbered.txt" };
	std::string line;
	int counter{ 0 };

	if (!source) std::cerr << "error source file\n";
	if (!target) std::cerr << "error target file\n";
	else
	{
		while (std::getline(source, line))
		{
			++counter;
			target << counter << "\t" << line << std::endl;
		}
	}
	source.close();
	target.close();
	std::cout << "completed\n";	
}

void add_number_to_each_line_exclude_blanklines()
{
	std::ifstream source{ "C:\\Users\\nirvikalpa\\Desktop\\infile.txt" };
	std::ofstream target{ "C:\\Users\\nirvikalpa\\Desktop\\infile_numbered2.txt" };
	std::string line;
	int counter{ 0 };
	
	if (!source) std::cerr << "error source file\n";
	if (!target) std::cerr << "error target file\n";
	else
	{
		while (std::getline(source, line))
		{
			if (line.empty())
			{
				target << std::endl;
			}
			else
			{
				++counter;
				target << counter << "\t" << line << std::endl;
			}
		}
	}
	source.close();
	target.close();
	std::cout << "completed\n";
}

void add_number_to_each_line_exclude_blanklines_and_charnr()
{
	std::ifstream source{ "C:\\Users\\nirvikalpa\\Desktop\\infile.txt" };
	std::ofstream target{ "C:\\Users\\nirvikalpa\\Desktop\\infile_numbered3.txt" };
	std::string line;
	int counter{ 0 };
	int char_numbers{ 0 };

	if (!source) std::cerr << "error source file\n";
	if (!target) std::cerr << "error target file\n";
	else
	{
		while (std::getline(source, line))
		{
			if (line.empty())
			{
				target << std::endl;
			}
			else
			{
				++counter;
				target << counter << "\t" << line << "\t" << line.size() << std::endl;
			}
		}
	}
	source.close();
	target.close();
	std::cout << "completed\n";
}

int main()
{
	add_number_to_each_line();
	add_number_to_each_line_exclude_blanklines();
	add_number_to_each_line_exclude_blanklines_and_charnr();

	return 0;
}