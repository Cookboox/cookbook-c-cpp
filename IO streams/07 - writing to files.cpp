#include <iostream>
#include <fstream>
#include <string>

//1) declare either of the two classes fstream, ofstream
//2) connect it to a file 
//3) write data
//4) close the stream --> it will flush the buffer

//DEFAULT BEHAVIOUR
//file created if not exists
//file overwiten -->can be specified to append

//std::ofstream out_file{ "path/to/file", std::ios::trunc } //default
//std::ofstream out_file{ "path/to/file", std::ios::app } //append each write
//std::ofstream out_file{ "path/to/file", std::ios::ate } //seek to end of stream when opening

//if u dont know the name
//std::ofstream out_file;
//out_file.open(filename);

//check if opened
//if(out_file) 

//close
//out_file.close(); //IMPORTANT SINCE IT FLUSHES ANY BUFFER THAT MAY NOT HAVE BEEN WRITTEN

void copying_file_line_by_line()
{
	std::ifstream source{ "C:\\Users\\nirvikalpa\\Desktop\\infile.txt" };
	std::ofstream target{ "C:\\Users\\nirvikalpa\\Desktop\\copy_by_line_infile.txt" };
	std::string line;

	if (!source) std::cerr << "error opening source file\n";
	if (!target) std::cerr << "error opening target file\n";

	else
	{
		while (std::getline(source, line))
			target << line << std::endl;
	}
	source.close();
	target.close();
}

void copying_file_char_by_char()
{
	std::ifstream source{ "C:\\Users\\nirvikalpa\\Desktop\\infile.txt" };
	std::ofstream target{ "C:\\Users\\nirvikalpa\\Desktop\\copy_by_chars_infile.txt" };
	char c{};

	if(!source) std::cerr << "error opening source file\n";
	if(!target) std::cerr << "error opening target file\n";
	else
	{
		while (source.get(c))
			target.put(c);
	}
	source.close();
	target.close();
}

void copying_file_word_by_word()
{
	std::ifstream source{ "C:\\Users\\nirvikalpa\\Desktop\\infile.txt" };
	std::ofstream target{ "C:\\Users\\nirvikalpa\\Desktop\\copy_by_words_infile.txt" };
	std::string word;
	if (!source) std::cerr << "error opening source file\n";
	if (!target) std::cerr << "error opening target file\n";
	else
	{
		while (source >> word)
			target << word;
	}
	source.close();
	target.close();
}

void writing_to_file_by_char()
{
	std::ofstream target{ "C:\\Users\\nirvikalpa\\Desktop\\file1.txt" };
	char c{};

	if (!target) std::cerr << "error target\n";
	else
	{
		while (std::cin.get(c))
		{
			target.put(c);
			if (c == '\t') 
				break;
		}
	}
	target.close();
}

void writing_to_file_by_line()
{
	std::ofstream target{ "C:\\Users\\nirvikalpa\\Desktop\\file2.txt", std::ios::app};
	std::string line;

	if (!target) std::cerr << "error opening target file\n";
	else
	{
		while (std::getline(std::cin, line))
		{
			target << line << std::endl;
			if (line == "\t") 
				break;
		}
	}
	target.close();
}

void writing_to_file_by_word()
{
	std::ofstream target{ "C:\\Users\\nirvikalpa\\Desktop\\file3.txt", std::ios::app };
	std::string word;

	if (!target) std::cerr << "error target file\n";
	else
	{
		while (std::cin >> word)
		{
			target << word << " ";
			if (word == "exit()")
				break;
		}
	}
}

int main()
{
	//copying_file_line_by_line();
	//copying_file_char_by_char();
	//copying_file_word_by_word();

	//writing_to_file_by_char();
	//writing_to_file_by_line();
	writing_to_file_by_word();

	return 0;
}