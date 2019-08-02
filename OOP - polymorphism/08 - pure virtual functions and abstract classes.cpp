#include <iostream>
#include <memory>
#include <vector>

//abstract class:
//cannot instantiate objects because it is too generic (eg.: class Shape)
//is used as a base class in inheritance hierarchy
//is often referred to as Abstract Base Class (ABC)
//must contain at least one PURE Virtual Function!!

//virtual function is used to make a class abstract
//typically do not provide implementations
//virtual void f() = 0;
//derived class MUST override pure virtual function in order to be concrete class
//if it does not override, then the derives IS ALSO abstract class

//concrete class:
//used to instantiate object from (eg.: CheckingAccount)
//all their member functions are defined  


// abstract base class (ABC) 
class Shape
{
private:
	//stuff common to all shapes
public:
	virtual void draw() = 0;
	virtual void rotate() = 0;
	virtual ~Shape() {}
};

//abstract class
class OpenedShape :public Shape
{
private:
	//stuff common to all openedshapes
public:
	// draw and rotate inherited but not overriden  --> abstract class
	virtual ~OpenedShape() {}
};

//abstract class
class ClosedShape :public Shape 
{
private:
	//stuff common to all closedshapes
public:
	// draw and rotate inherited but not overriden  --> abstract class
	virtual ~ClosedShape() {}
};


// concrete class
class Line : public OpenedShape
{
private:
	//
public:
	//overriding pure virtual functions --> concrete class
	virtual void draw() override { std::cout << "drawing line\n"; }
	virtual void rotate() override { std::cout << "rotating line\n"; }
	virtual ~Line(){}
};

//concrete class
class Circle : public ClosedShape
{
private:
	//
public:
	//overriding pure virtual functions --> concrete class
	virtual void draw() override { std::cout << "drawing circle\n"; }
	virtual void rotate() override { std::cout << "rotating circle\n"; }
	virtual ~Circle() {}
};

//concrete class
class Square : public ClosedShape
{
private:
	//
public:
	//overriding pure virtual functions --> concrete class
	virtual void draw() override { std::cout << "drawing square\n"; }
	virtual void rotate() override { std::cout << "rotating square\n"; }
	virtual ~Square() {}
};

void rotate(Shape& s)
{
	s.rotate();
}

void refresh_screen(std::vector<Shape*>& shapes)
{
	for (auto const& i : shapes) i->draw();
}

int main()
{
	//non of these lines are allowed --> cannot instantiate abstract class
	//Shape s;
	//Shape* ptr = new Shape();
	//std::unique_ptr<Shape> up{ std::make_unique<Shape>() };

	////the same..
	//OpenedShape os;
	//ClosedShape cs;


	//this works fine. but these methods are statically bound and the point of making abstract base class is u leverage the dynamic binding polymorphism
	Circle c;
	c.draw();
	c.rotate();

	Square s;
	s.draw();
	s.rotate();

	Line l;
	l.draw();

	

	std::cout << "\n--------- dynamic binding polymorphism using raw pointers -------------------------\n";
	Shape* ptr_c = new Circle;
	Shape* ptr_s = new Square;
	Shape* ptr_l = new Line;
	// ABC-pointers to derived concrete class objects --> it decides dynamically at runtime upon which object to call the methods 
	ptr_c->draw();
	ptr_c->rotate();
	ptr_s->draw();
	ptr_s->rotate();
	ptr_l->draw();
	ptr_l->rotate();

	std::cout << "\n--------- looping over vector of ABC raw pointers -------------------------\n";
	std::vector<Shape*> shapes{ ptr_c, ptr_l, ptr_s };
	for (auto const& i : shapes) i->draw();

	std::cout << "\n--------- looping over array of ABC raw pointers -------------------------\n";
	Shape* arr_shapes[]{ ptr_c, ptr_l, ptr_s };
	for (size_t i = 0; i < sizeof(arr_shapes) / sizeof(arr_shapes[0]); ++i) arr_shapes[i]->draw();

	std::cout << "\n--------- dynamic binding polymorphism using references -------------------------\n";

	rotate(c);
	rotate(s);
	rotate(l);
	refresh_screen(shapes);


	return 0;
}