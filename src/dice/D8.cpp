/*
 * D8.cpp
 * Implements a class that represents a 8-sided die
 * Created by Andrew Davis
 * Created on 3/11/2017
 * All rights reserved
 */

//include header
#include "D8.h"

//first constructor - creates a D8 with a randomized value
D8::D8()
	: Die(8) //call the first superclass constructor
{
	//no code needed
}

//second constructor - creates a D8 with a set value
D8::D8(int newValue)
	: Die(8, newValue) //call the second superclass constructor
{
	//no code needed
}

//destructor
D8::~D8() {
	//no code needed
}

//copy constructor
D8::D8(const D8& de)
	: Die(de) //call the superclass copy constructor
{
	//no code needed
}

//move constructor
D8::D8(D8&& de)
	: Die(de) //call the superclass move constructor
{
	//no code needed
}

//assignment operator
D8& D8::operator=(const D8& src) {
	Die::operator=(src); //call the superclass assignment operator
	return *this; //return the object
}

//move operator
D8& D8::operator=(D8&& src) {
	Die::operator=(src); //call the superclass move operator
	return *this; //return the object
}

//end of implementation
