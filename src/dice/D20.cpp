/*
 * D20.cpp
 * Implements a class that represents a 20-sided die
 * Created by Andrew Davis
 * Created on 3/11/2017
 * Open source (GPL license)
 */

//include header
#include "D20.h"

//first constructor - creates a D20 with a randomized value
D20::D20()
	: Die(20) //call the first superclass constructor
{
	//no code needed
}

//second constructor - creates a D20 with a set value
D20::D20(int newValue)
	: Die(20, newValue) //call the second superclass constructor
{
	//no code needed
}

//destructor
D20::~D20() {
	//no code needed
}

//copy constructor
D20::D20(const D20& dtz)
	: Die(dtz) //call the superclass copy constructor
{
	//no code needed
}

//move constructor
D20::D20(D20&& dtz)
	: Die(dtz) //call the superclass move constructor
{
	//no code needed
}

//assignment operator
D20& D20::operator=(const D20& src) {
	Die::operator=(src); //call the superclass assignment operator
	return *this; //return the object
}

//move operator
D20& D20::operator=(D20&& src) {
	Die::operator=(src); //call the superclass move operator
	return *this; //return the object
}

//end of implementation
