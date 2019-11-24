#include <iostream>
#include <iomanip>

//can be used for both inut and output formatting, output is more common
//what matters is the time of the effect, some are immediate, some last only for the next object, some for all program

//two versions:
//1) method of the object --> std::cout.width(10]
//2) manipulator --> std::cout << std::setw(10)

//COMMON STREAM MANIPULATORS:
//1) boolean - boolapha, noboolalpha (applies to all) 
//2) integer - dec, hex, oct, showbase, showpos, uppercase...  (applies to all)
//3) float - fixed, scientific, setprecision, showpoint, showpos... (persist once they are set)
//4) field width, justification, fill - setw, lef, right, internal, setfill...
//5) others - endl, flush, ws, skipws...

void helper()
{
	std::cout << "\n1234567890123456789012345678901234567890123456789012345678901234567890\n"; 
}

void boolean()
{
	//all flags have defualt value
	std::cout << "default noboolalpha: " << (1 == 1) << "\n";
	std::cout << "default noboolalpha: " << (1 == 2) << "\n";
	   
	std::cout << std::boolalpha;
	std::cout << "boolalpha: " << (1 == 1) << "\n";
	std::cout << "boolalpha: " << (1 == 2) << "\n";

	std::cout << std::noboolalpha;
	std::cout << "boolalpha: " << (1 == 1) << "\n";
	std::cout << "boolalpha: " << (1 == 2) << "\n";


	//this is how i set a flag using method --> no need to include iomanip
	std::cout.setf(std::ios::boolalpha);
	std::cout << "boolalpha: " << (1 == 1) << "\n";
	std::cout << "boolalpha: " << (1 == 2) << "\n";

	//if i want to go back to 0/1 i need to reset it
	//this will reset whichever flag i pass there to default..
	std::cout << std::resetiosflags(std::ios::boolalpha);
	std::cout << "boolalpha: " << (1 == 1) << "\n";
	std::cout << "boolalpha: " << (1 == 2) << "\n";
	   
}

void integers()
{
	//4 different ways to display numbers - dec, hex, octo, bin
	//hex - starts 0X - represents memory location, each hex number is 8 bits (1 byte)
	//octo - starts 0 -
	//bin

	int x = 255;
	int y = -255;

	std::cout << "--------displaying using different basis without showing base------------------------\n";
	std::cout << std::dec << x << "\n";
	std::cout << std::oct << x <<  "\n";	
	std::cout << std::hex << x << "\n";

	std::cout << "--------displaying using different basis with showing base------------------------\n";
	std::cout << std::showbase;
	std::cout << std::dec << x << "\n";
	std::cout << std::oct << x << "\n";
	std::cout << std::hex << x << "\n";

	std::cout << "--------displaying using different basis with showing base and sign------------------------\n";
	std::cout << std::showpos;
	std::cout << std::dec << x << "\n";
	std::cout << std::oct << x << "\n";
	std::cout << std::hex << x << "\n";

	std::cout << "--------alternative way using setf method------------------------\n";
	std::cout.setf(std::ios::showbase);	
	std::cout.setf(std::ios::showpos);
	std::cout.setf(std::ios::uppercase);

	std::cout << "--------reseting to defualts------------------------\n";
	std::cout << std::resetiosflags(std::ios::showbase);
	std::cout << std::resetiosflags(std::ios::showpos);
	std::cout << std::resetiosflags(std::ios::basefield); //resets numbers to dec
}

void floats()
{
	//mostly about the presicions
	//default precision is 6

	double a{ 123456789.987654321 };
	double b{ 1234.56789 };
	double c{ 1234.00 };

	std::cout << "----------default---------------------\n";
	std::cout << a << "\n"; //will display scientific notation since 6 digits are default
	std::cout << b << "\n";
	std::cout << c << "\n";

	std::cout << "----------setprecision(2)---------------------\n";
	std::cout << std::setprecision(2);
	std::cout << a << "\n";
	std::cout << b << "\n";
	std::cout << c << "\n";

	std::cout << "----------setprecision(5)---------------------\n";
	std::cout << std::setprecision(5);
	std::cout << a << "\n";
	std::cout << b << "\n";
	std::cout << c << "\n";

	std::cout << "----------setprecision(10)---------------------\n";
	std::cout << std::setprecision(10);
	std::cout << a << "\n";
	std::cout << b << "\n";
	std::cout << c << "\n";


	std::cout << "----------setprecision(š)---------------------\n";
	std::cout << std::setprecision(3) << std::fixed; //fixes the deciml point --> precision hapens after
	std::cout << a << "\n";
	std::cout << b << "\n";
	std::cout << c << "\n";

	std::cout.unsetf(std::ios::fixed | std::ios::scientific); //reseting to default
	std::resetiosflags(std::ios::fixed); //same as above

	std::cout << "----------setprecision(10) and setpoin---------------------\n";
	std::cout << std::setprecision(12) << std::showpoint; //adds 0000 to the precision
	std::cout << a << "\n";
	std::cout << b << "\n";
	std::cout << c << "\n";
}

void witdth_just_fill()
{
	//field width and justification only appies to the next object
	//fiil char persist until changed

	double x = 12345.6789;
	std::string s{ "hello" };

	std::cout << "\n-----setw(10) default std::right----------------------------------\n";
	helper();
	std::cout << std::setw(10) << x  //default is right justified
		<< s; //applies only to the next object so this one will not be justified;

	std::cout << "\n-----setw(10) two times ----------------------------------\n";
	helper();
	std::cout << std::setw(10) << x
		<< std::setw(10) << s;

	std::cout << "\n-----setw(10) std::left ----------------------------------\n";
	helper();
	std::cout << std::setw(10) << std::left << x
		<< std::setw(10) << std::left << s
		<< std::setw(10) << std::left << s
		<< std::setw(10) << std::left << s
		<< std::setw(10) << std::left << s;
	
	std::cout << "\n-----setw(10) std::left, std::setfill ----------------------------------\n";	helper();
	std::cout << std::setfill('~') << std::setw(10) << std::left << x //setfill is persistent and applies only when setw() is set
		<< std::setw(10) << std::left << s
		<< std::setw(10) << std::left << s
		<< std::setw(10) << std::left << s
		<< std::setw(10) << std::left << s;

}







int main()
{
	//boolean();
	//integers();
	//floats();
	witdth_just_fill();

	return 0;
}
