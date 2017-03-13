/*
 * D10.cpp
 * Implements a class that represents a 10-sided die
 * Created by Andrew Davis
 * Created on 3/11/2017
 * Open source (GPL license)
 */

//include header
#include "D10.h"

//first constructor - creates a D10 with a randomized value
D10::D10()
	: Die(10) //call the first superclass constructor
{
	//no code needed
}

//second constructor - creates a D10 with a set value
D10::D10(int newValue)
	: Die(10, newValue) //call the second superclass constructor
{
	//no code needed
}

//destructor
D10::~D10() {
	//no code needed
}

//copy constructor
D10::D10(const D10& dtz)
	: Die(dtz) //call the superclass copy constructor
{
	//no code needed
}

//move constructor
D10::D10(D10&& dtz)
	: Die(dtz) //call the superclass move constructor
{
	//no code needed
}

//assignment operator
D10& D10::operator=(const D10& src) {
	Die::operator=(src); //call the superclass assignment operator
	return *this; //return the object
}

//move operator
D10& D10::operator=(D10&& src) {
	Die::operator=(src); //call the superclass move operator
	return *this; //return the object
}

//end of implementation
