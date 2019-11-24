#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

void process_data()
{
	std::ifstream in_file{ "C:\\Users\\nirvikalpa\\Desktop\\responses.txt" };
	std::string correct;
	std::string name;
	std::string answer;
	double sum{ 0 };
	int number_of_students{ 0};
	double average_mark{ 0 };

	if (!in_file)
	{
		std::cerr << "error reading the file\n";
	}
	else
	{
		std::getline(in_file, correct);
		std::cout << std::right << std::setw(20) << "NAME"
			<< std::right << std::setw(20) << "ANSWER"
			<< std::right << std::setw(20) << "MARK\n";
		std::cout << std::setw(80) << std::setfill('-') << "";
		std::cout << std::setfill(' ') << "\n";

		while (!in_file.eof())
		{
			in_file >> name >> answer;
			++number_of_students;

			int mark{ 0 };
			for (size_t i = 0; i < answer.size(); ++i)
			{
				if (answer[i] == correct[i])
				{
					++mark;
					++sum;
				}
			}
			std::cout << std::right << std::setw(20) << name
				<< std::right << std::setw(20) << answer
				<< std::right << std::setw(20) << mark << "\n";
		}
		std::cout << std::setw(80) << std::setfill('-') << "";
		std::cout << std::setfill(' ') << "\n";
		std::cout << std::right << std::setw(20) << "average mark is:"
				  << std::right << std::setw(40) << sum / number_of_students << "\n";
	}
	in_file.close();
}


int main()
{
	process_data();

	return 0;
}