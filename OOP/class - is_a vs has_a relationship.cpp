#include<iostream>

class Rectangle
{
private:
	int width = 1;
	int lenght = 1;

public:
	Rectangle() {};
	Rectangle(int w, int l) { this->lenght = l, this->width = w; }

	int get_length() { return this->lenght; }
	void set_length(int l) { this->lenght = l; }
};

//i am extending Rectangle class that is why i can say Cuboid IS A Rectangle
class Cuboid :public Rectangle
{
private:
	int height = 0;

public:
	Cuboid() {};
	Cuboid(int h) { this->height = h; }

	int get_height() { return this->height; }

};

// i am using object as part of my class, so Table HAS A Rectangle
class Table
{
private:
	Rectangle top; //why i cant write top(10,20)?
	int nr_of_legs = 4;

public:
	Table() {};
};


int main()
{
	/*Rectangle r;
	std::cout << r.get_length() << "\n";

	Rectangle r2(3,4);
	std::cout << r2.get_length() << "\n";

	Cuboid c;
	std::cout << c.get_length() << "\n"; 

	Cuboid c2(20);
	std::cout << c2.get_height() << "\n";

	c2.set_length(4);
	std::cout << c2.get_length() << "\n";
*/





	return 0;
} 