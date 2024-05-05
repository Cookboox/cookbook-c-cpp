#include<iostream>


class Shallow
{
private:
	int *data{ nullptr};

public:
	void set_data(int dval) { *data = dval; }
	int get_data() { return *data; }

	//contructor
	Shallow(int dval);

	//copy constructor
	Shallow(const Shallow &source);

	//destructor
	~Shallow();
};

Shallow::Shallow(int dval)  
{
	data = new int;
	*data = dval;
}

Shallow::Shallow(const Shallow &source) : data(source.data)
{
	std::cout << "Copy constructor - shallow copy " << "\n";
}

Shallow::~Shallow()
{
	delete data;
	std::cout << "destructor called " << "\n";
}

void display_shallow(Shallow s)
{
	std::cout << s.get_data() << "\n";
}


int main()
{
	Shallow obj1{ 100 };
	display_shallow(obj1);

	Shallow obj2{ obj1 };
	obj2.set_data(9999);




	return 0;
}

