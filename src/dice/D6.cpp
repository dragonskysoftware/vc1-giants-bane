/*
 * D6.cpp
 * Implements a class that represents a 6-sided die
 * Created by Andrew Davis
 * Created on 3/11/2017
 * Open source (GPL license)
 */

//include header
#include "D6.h"

//first constructor - creates a D6 with a randomized value
D6::D6()
	: Die(6) //call the first superclass constructor
{
	//no code needed
}

//second constructor - creates a D6 with a set value
D6::D6(int newValue)
	: Die(6, newValue) //call the second superclass constructor
{
	//no code needed
}

//destructor
D6::~D6() {
	//no code needed
}

//copy constructor
D6::D6(const D6& ds)
	: Die(ds) //call the superclass copy constructor
{
	//no code needed
}

//move constructor
D6::D6(D6&& ds)
	: Die(ds) //call the superclass move constructor
{
	//no code needed
}

//assignment operator
D6& D6::operator=(const D6& src) {
	Die::operator=(src); //call the superclass assignment operator
	return *this; //return the object
}

//move operator
D6& D6::operator=(D6&& src) {
	Die::operator=(src); //call the superclass move operator
	return *this; //return the object
}

//end of implementation
