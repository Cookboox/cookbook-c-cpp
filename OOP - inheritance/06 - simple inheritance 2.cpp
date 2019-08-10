#include<iostream>

class Parrent
{
private:
	int x = 1;
public:
	int a;
	void say_hello_parrent() { std::cout << "hello from Parrent" << "\n"; }
	void display_member_parrent() { std::cout << "displaying parrent member x: " << this->x << "\n"; }
};

class Child :public Parrent 
{
private:
	int x = 10; 
	int y = 11;
public:
	void say_hello_child() { std::cout << "hello from Child" << "\n"; }
	void display_member_child() { std::cout << "displaying child member x: " << this->x << "\n"; }
	void set_x_child(int new_x) 
	{
		this->x = new_x;
		std::cout << "setting x to: " << new_x << "\n"; 
	}
};


int main()
{
	Parrent p;
	Child c;

	// p has his own members accesible of course
	p.say_hello_parrent();
	p.display_member_parrent();
	p.a = 99;
	std::cout << p.a << "\n";

	// all public members are accesible
	c.say_hello_parrent();
	c.display_member_parrent();
	c.a = 99; 
	std::cout << c.a << "\n";


	// child has access to his own members
	c.say_hello_child();
	c.display_member_child();
	// this is private member of parrent and is not accesible to child
	//c.x = 99; //what if i mean x in child?? how to overwrite it?  i need to have a setter
	c.set_x_child(-55);
	c.display_member_child();
	   	 
	return 0;
}