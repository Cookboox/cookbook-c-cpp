#include <iostream>
#include <sstream>
#include <string>
#include <limits>

//allow us to use in memory string objects as streams
//thus we can read write data to strings just as well as we can read it to any stream
//very usefull for data validation -->´parsing string and checking types..

//three classes: stringstream, istringstream, ostringstream

//1) declare a stringstream object
//2) connect it to a std::string
//3) read from/to it

void reading_from_stringstream()
{	
	std::string some_string{"Hello 100 3.14"};
	
	std::string word;
	int a{};
	double b{};
	
	//connection stringstream to string
	std::istringstream iss{some_string}; 

	//now i can read the string like a stream
	iss >> word >> a >> b;

	//and just display whatever is in the objects
	std::cout << word << a << b;

}

void reading_ss_using_getline()
{
	std::string greeting{ "hello i am a string" };
	
	//connect std::string to stringstream
	std::istringstream ss{ greeting };
	
	std::string new_string;
	std::getline(ss, new_string); //read whole line into new string

	std::cout << new_string;
}

void writing_to_stringstream()
{
	int a = 10;
	std::string name{ "paul" };

	std::ostringstream ss{}; //creating output stringstream object
	ss << a << name;// reading intor there
	std::cout << ss.str(); //reading from it

}

void data_validation()
{
	int value{};
	std::string input{};

	bool done = false;
	do
	{
		std::cout << "enter int number\n";
		std::cin >> input; // first reading it as a string
		std::stringstream ss{input}; //then connect the stringstream to the string

		if (ss >> value) //if it was successfull to extract int from the stringstream
			done = true; //we are done.. 
		else
			std::cerr << "you did not enter integer, try again..\n";

		//clear and ignore all in cin buffer
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max());

	} while (!done);

	std::cout << "you entered " << value << "\n";
}

void data_type_selector()
{
	int int_value{};
	double double_value{};
	std::string str_value{};

	std::string input{};

	std::cout << "enter something\n";
	std::cin >> input;
	std::stringstream ss{ input };


	if (ss >> int_value)
	{
		std::cout << "you entered int: " << int_value << "\n";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max());
	}

	if (ss >> double_value)
	{
		std::cout << "you entered double: " << double_value << "\n";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max());
	}
	if (ss >> int_value)
	{
		std::cout << "you entered string: " << str_value << "\n";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max());
	}
	
}

int main()
{
	//reading_from_stringstream();
	//reading_ss_using_getline();
	//writing_to_stringstream();

	//data_validation();
	data_type_selector();


	return 0;
}