#include <iostream>

//assortment of comonly used containers, iterators and algorithms

//KEYNOTES:
//-extenivelly tested --> fast, type safe, consistent
//-know time and space complexity --> no surprises when using them
//-extensible --> possible to add up/modify it

//three parts designed totally independently but working together
//-containter (collections: array, vector, deque, stack, map, set, etc..)
//-algorithms (functions for processing the collections: find, max, count, sort, etc..)
//-iterators (object used to traverse and access the data in algorithms: forwardIterator, reverseIterator, constantIterator, etc..)
//functors and allocators are also part of stl

//three types of containers
//-sequence (array, vector, list, forward_list, deque)
//-associative containers (set, multiset, map, multimap)
//-container adapters (stack, queue, priority queue) -- but these dont support algorithms

//types of iterators
//-input iterators - from the container to program
//-output iterators - from the program to the container
//-forward iterators - one item at time in forward direction
//-bi-directional iterators - one item at time both directions
//-random access iterators - directly access a container
