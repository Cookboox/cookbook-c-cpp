#include <iostream>
#include<string>
#include<cctype>
#include<algorithm>



class FileName
{
private:
	std::string slovo;
public:
	FileName() = default;
	FileName(std::string s) : slovo(s) { get_extension(); }

	enum class has_extension { mp3 = 0, avi, doc, pdf, rtf };

	has_extension get_extension()
	{
		if (this->slovo.size() < 5)
		{
			std::cout << "konstrujui slovo kratsi nez 5\n";
			return has_extension::mp3;
		}
		else if (this->slovo.size() >= 5 && this->slovo.size() < 10)
		{
			std::cout << "konstrujui slovo kratsi nez 10\n";
			return has_extension::avi;
		}
		else if (this->slovo.size() >= 10 && this->slovo.size() < 15)
		{
			std::cout << "konstrujui slovo kratsi nez 15\n";
			return has_extension::doc;
		}
		else if (this->slovo.size() >= 15 && this->slovo.size() < 20)
		{
			std::cout << "konstrujui slovo kratsi nez 20\n";
			return has_extension::pdf;
		}
		else 
		{
			std::cout << "konstrujui slovo delsi nez 20\n";
			return has_extension::rtf;
		}
	}
	friend std::ostream& operator<<(std::ostream& os, FileName& const rhs);
};

std::ostream& operator<<(std::ostream& os, FileName& const rhs)
{
	os << rhs.slovo;
	return os;
}

int main()
{

	FileName s("1");
	FileName s1("12345678");
	FileName s2("1234567890123");
	FileName s3("1234567890123456");
	FileName s4("123456789012345678901234563495328524871245897496598234");

	std::cout << std::endl;
	std::cout << s  << "\n";
	std::cout << s1 << "\n";
	std::cout << s2 << "\n";
	std::cout << s3 << "\n";	
	std::cout << s4 << "\n" << std::endl;

	
	//here i have perfectly readible code
	if (s.get_extension() == FileName::has_extension::mp3)
		std::cout << s << " is less then five\n";
		//..
	if (s1.get_extension() == FileName::has_extension::avi)
		std::cout << s1 << " is less then ten\n";
		//..
	if (s2.get_extension() == FileName::has_extension::pdf)
		std::cout << s2 << " is less then 15\n";
		//..
	if (s3.get_extension() == FileName::has_extension::rtf)
		std::cout << s3 << " is less then 20\n";
		//..
	if (s4.get_extension() == FileName::has_extension::doc)
		std::cout << s4 << " is more then 20\n";
}





