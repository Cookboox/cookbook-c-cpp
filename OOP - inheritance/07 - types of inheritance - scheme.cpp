/*
	there are these basics types of inheritance (<----- means "inhereited from")
	----------------------------------------------------------------------------------------------------------------------
	type			 - structure										- example
	----------------------------------------------------------------------------------------------------------------------
	simple 			 - parrent <----- child								- rectangle <----- cuboid
	hierarchical 	 - parrent <----- many childs						- shape <----- triangle, rectangle, circle
	multilevel 		 - parrent <----- child <----- grandchild			- point <----- circle <----- cylinder
	multiple 		 - many parrents <----- child						- phone, camera, mediaplyer <----- smartphone
	multipath		 - parrent <----- many childs <----- grandchild
	---------------------------------------------------------------------------------------------------------------------
	of course we can have mixture of the above.. hybrid, multipath is damgerous (ambiguity in data in grandchild - virtual fucntions solve that)

*/


//------------------ scheme of SIMPLE (parrent <----- child)  ------------------//
class A
{

};

class B : public A
{

};


//------------------ scheme of HIERARCHICAL (parrent <----- many childs) ------------------//
class A
{

};

class B : public A
{

};

class C : public A
{

};

class D : public A
{

};

//------------------ scheme of MULTILEVEL (parrent <----- child <----- grandchild) ------------------//
class A
{

};

class B : public A
{

};

class C : public B
{

};

//------------------ scheme of MULTIPLE (many parrents <----- child) ------------------//

class A
{

};

class B
{

};

class C : public A, public B
{

};


//------------------ scheme of MULTIPATH (parrent <----- many childs <----- grandchild) and how to solve it - using the word virtual ------------------//
class A
{

};

class B :virtual public A // keyword virtual make the class B virtual and will remove the problem of data ambiguity for class D that inherits from B
{

};

class C :virtual public A  // keyword virtual make the class C virtual and will remove the problem of data ambiguity for class D that inherits from C
{

};

class D :public B, public C
{

};
