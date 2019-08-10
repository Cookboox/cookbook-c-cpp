#include<iostream>


//Parrent class with two public members and one private
class Parrent
{
private:
	int x = 1;
protected:
	int y = 2;
public:
	int z = 3;

	void say_hello() { std::cout << "hello from Parrent" << "\n"; }
	void display_x() { std::cout << "displaying parrent member x: " << this->x << "\n"; }
	void display_y() { std::cout << "displaying parrent member y: " << this->y << "\n"; }

};


//empty child class publicly inheriting
class ChildPub :public Parrent {};

//empty child class protectedly inheriting
class ChildProt :protected Parrent {};

//empty child class privately inheriting
class ChildPriv :private Parrent {}; //same as ChildPriv :Parrent {};
 

int main()
{
	
	Parrent p;	
	p.say_hello();
	p.display_x();
	p.display_y();
	p.z;
	p.x; // this is private member - upon object no access to it
	p.y; // this is protected member - upon object no access to it
	

	// child inherited everything  PUBLICLY and did not add any methods or data so it will display the same as Parrent
	ChildPub cpub;
	cpub.say_hello();
	cpub.display_x();
	cpub.display_y();
	cpub.z;
	cpub.x; // this is private member - upon derived object no access to it
	cpub.y; // this is protected member - upon derived object no access to it



	// child inherited everything  PROTECTEDLY and did not add any methods or data so it will have no access to any members
	ChildProt cprot;
	cprot.say_hello();
	cprot.display_x();
	cprot.display_y();
	cprot.z;
	cprot.x; // this is private member - upon derived object no access to it
	cprot.y; // this is protected member - upon derived object no access to it

	// child inherited everything  PRIVATELY and did not add any methods or data so it will have no access to any members
	ChildPriv cpriv;
	cpriv.say_hello();
	cpriv.display_x();
	cpriv.display_y();
	cpriv.z;
	cpriv.x; // this is private member - upon derived object no access to it
	cpriv.y; // this is protected member - upon derived object no access to it



	return 0;
}