#include <iostream>

//issues with raw pointers:
//-unitialized memory
//-dangling pointers
//-memory leaks
//-not exception safe

//it all boils down to the problem of ownership
//-who owns the pointer?
//-who is responsible for deleting it?
//-when the pointer should be deleted?

//this is where smart pointers come in. but first? what are they?
//smart pointers keynotes:
//-they are objects implemented as template classes. it is basically a wrapper around a raw pointer, complile dependent
//-they can point only to heap allocated memory
//-they automatically delete the object holding
//-they adhere to RAII principles
//-they support overloaded operators of dereference and member access (*, ->);
//-they DO NOT support pointer arithmetic
//-they can have custom deleters

//prototype:
/*
{
	smart_pointer<class_name> ptr_name = ..;	//declare
	ptr_name->some_method();					//get method
	ptr_name->some_attribute;					//get data
	std::cout << *ptr_name << "\n";				//dereference
}
// automatic destruction
*/

//smart pointers are RAII respectful
//what is RAII: Resource Aquisition (open a file, allocate heap memory..) Is Initialization (the resource is aquired in constructor), resource freeing hapens in destructor
//RAII object are allocated on the stack!! smart pointers RAII objects

