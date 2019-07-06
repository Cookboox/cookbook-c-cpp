#include<iostream>

class Parent
{
public:
	Parent() { std::cout << "default constructor of Parent" << "\n"; }
	Parent(int a) { std::cout << "parametrized constructor of Parent" << "\n"; }
};

class Child:public Parent
{
public:
	Child() { std::cout << "default constructor of Child" << "\n"; }
	Child(int b) { std::cout << "parametrized constructor of Child" << "\n"; }

 	Child(int a, int b):Parent(a) { std::cout << "parametrized constructor of Parent and parametrized constructor of Child" << "\n"; }
};





int main()
{
	Parent p1; // calls default constructor of Parent
	Child c1; // it will first call default constructor of Parrent, then it will call default constr of Child

	Parent p2(10); // calls parametrized constructor of Parent
	Child c2(10); // it will first call default constructor of Parrent, then it will call paramterized constr of Child

	Child c3(10, 20); //call paramterized constructor of Child, and parametrized constructor of Parent


	return 0;
}