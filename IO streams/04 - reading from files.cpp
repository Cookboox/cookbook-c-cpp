#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//fstream or ifstream are commonly used for input files

//steps always needed when reading from files:
//1) include <fstream>
//2) declare fstream or ifstream oject
//3) connect it to a file in local filesystem
//4) read data from the file via the stream
//5) close te file

//different methods how to read -binary, text, line by line, character by character.. etc..

//reading text data using fstream:
//std::fstream in_file{ "/path/to/file/name.txt", std::ios::in };
//reading non text file:
//std::fstream in_file{"/path/to/file/name.mp3", std::ios::in | std::ios::binary}

//reading text data using ifstream:
//std::iftream in_file{ "/path/to/file/name.txt"}; //no need to specify the flag since it is defaultstd::iftream in_file{ "/path/to/file/name.txt" };
//reading non text file:
//std::iftream in_file{ "/path/to/file/name.txt", std::ios::binary };

//if we dont know the name of the file
//std::ifstream in_file;
//in_file.open(filename); //filename we get from somewhere on runtime

//check if opened
//if(in_file) //if(in_file.is_ope())

//close
//in_file.close()

//reading from it just like from cin
//int variable;
//in_file >> variable;;

//reading entire line
//std::string line;
//std::getline(in_file, line);  
//while(!in_file.eof()) std::getline(in_file, line); .... //read entire file
//while(std::getline(in_file,line)) ....// getline returns ref to stream object, so it will return false if no other text to read
//while(in_file.get(c)) ....//reading unformatted single character, usefull because other >> operator or getline depend on whitespace

void read_file_word_by_word_using_insertion_opertator()
{
	std::string line;
	int x;
	float y;

	std::fstream in_file{ "C:\\Users\\nirvikalpa\\Desktop\\test1.txt" };
	if (!in_file) 
		std::cerr << "error reading file\n";
	else
	{
		in_file >> line >> x >> y;
		std::cout << line << " " << x << " " << y;
	}
	in_file.close();
}


int read_file_line_by_line_using_getline()
{			
	std::string line;
	std::fstream in_file{ "C:\\Users\\nirvikalpa\\Desktop\\infile.txt" };
	char const* c_line;

	if (!in_file)
	{
		std::cerr << "file not found\n";
		return 1;
	}
	else
	{
		while (std::getline(in_file, line)) 
			std::cout << line <<"\n";	
	}
	in_file.close();
	return 0;
}

void read_file_char_by_char_using_get()
{
	char c{};
	std::ifstream in_file{ "C:\\Users\\nirvikalpa\\Desktop\\infile.txt" };

	if (!in_file)
	{
		std::cerr << "error opening..\n";
	}
	else
	{
		while (in_file.get(c))
			std::cout << c;
	}
	in_file.close();
}


int main()
{	
	//read_file_word_by_word_using_insertion_opertator();
	//read_file_line_by_line_using_getline();
	read_file_char_by_char_using_get();
	return 0;
}