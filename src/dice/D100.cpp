/*
 * D100.cpp
 * Implements a class that represents a 100-sided die
 * Created by Andrew Davis
 * Created on 3/11/2017
 * All rights reserved
 */

//include header
#include "D100.h"

//first constructor - creates a D100 with a randomized value
D100::D100()
	: Die(100) //call the first superclass constructor
{
	//no code needed
}

//second constructor - creates a D100 with a set value
D100::D100(int newValue)
	: Die(100, newValue) //call the second superclass constructor
{
	//no code needed
}

//destructor
D100::~D100() {
	//no code needed
}

//copy constructor
D100::D100(const D100& doh)
	: Die(doh) //call the superclass copy constructor
{
	//no code needed
}

//move constructor
D100::D100(D100&& doh)
	: Die(doh) //call the superclass move constructor
{
	//no code needed
}

//assignment operator
D100& D100::operator=(const D100& src) {
	Die::operator=(src); //call the superclass assignment operator
	return *this; //return the object
}

//move operator
D100& D100::operator=(D100&& src) {
	Die::operator=(src); //call the superclass move operator
	return *this; //return the object
}

//end of implementation
