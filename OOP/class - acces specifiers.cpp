#include<iostream>


// class has access to all its memebers
// child class has access to protected and public memebers
// object of a class has access to only pulblic members



/*-------------------------------------------------------------------------------------------------------
					|	private   |	protected   |		public			 	|
--------------------------------------------------------------------------------------------------------
inside class		|	 yes	  |	yes	    |		yes				|
inside derived class|	  no      |	yes	    |		yes				|
upon class object	|	  no      |	no	    |		yes				|
upon derived object	|	  no      |	no	    |	 	no (yes if publicly inherits)   |
---------------------------------------------------------------------------------------------------------*/

//here i make a simple class with member using different access
class Parrent
{
private:
	int a = 0;
protected:
	int b = 0;
public:
	int c = 0;
	void foo()
	{
		a = 1;
		b = 2;
		c = 3;
	}
};
 
//here i inherit privately
class ChildPrivate : Parrent
{
public:
	// derived class cannot acces private memeber of base class, regardless the way it inherits
	void foo()
	{
		//a = 100; 
		b = 200;
		c = 300;
	}
};

//here i inherit protectedly
class ChildProtected :protected Parrent
{
public:
	// derived class cannot acces private memeber of base class, regardless the way it inherits
	void foo()
	{
		//a = 100; 
		b = 200;
		c = 300;
	}
};

//here i inherit publicly
class ChildPublic :public Parrent
{
public:
	// derived class cannot acces private memeber of base class, regardless the way it inherits
	void foo()
	{
		//a = 100; 
		b = 200;
		c = 300;
	}
};


int main()
{
	//upon object i can acces only public members of the class!"
	Parrent	p;
	//p.a = 10; //i cannot access - not write, nor read
	//p.b = 10; //i cannot access - not write, nor read
	p.c = 10;
	std::cout << p.c << "\n";

	//beacause i iherited privately (default) i cannot access neither of Parrent class members
	ChildPrivate c{};
	//c.a;
	//c.b;
	//c.c;

	//beacause i iherited protectedly i cannot access neither of Parrent class members - basically the same as private inheritance
	ChildProtected c2{};
	//c2.a;
	//c2.b;
	//c2.c;


	//i inherited publicly, so i can access the value of c
	ChildPublic c1{};
	//c1.a;
	//c1.b;
	c1.c;
	std::cout << c1.c;


	return 0;
}