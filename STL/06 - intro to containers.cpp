
//some things are common to all containers, others are not

//COMMON THINGS:
//default constructor --> makes empty container
//overloaded constructors --> many options how to create a container
//copy constructor --> create a container as a copy of another one
//move constructor --> moves existing container to new one
//destructor
//copy asignement (=operator) --> copies one existing to another existing
//move asignement (=operator) --> moves one existing to another existing
//size, empty, swap, erase, clear..
//comparision operators
//iterators

//WHAT CAN BE STORED IN A CONTAINER?
//-all primitive types
//-our own custom types as long as they are copyable/assigneble (copy constructor/copy assignement must be implemented) because elements are copyied into containers
//-if the are not copyable, they can be moveable (move constructor/move assignement must be implemented)
//-ordered associative containers mus be able to compare elements (< and == operators mus be overloaded)
