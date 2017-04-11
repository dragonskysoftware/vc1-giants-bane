/*
 * D4.cpp
 * Implements a class that represents a 4-sided die
 * Created by Andrew Davis
 * Created on 3/11/2017
 * All rights reserved
 */

//include header
#include "D4.h"

//first constructor - creates a D4 with a randomized value
D4::D4()
	: Die(4) //call the first superclass constructor
{
	//no code needed
}

//second constructor - creates a D4 with a set value
D4::D4(int newValue)
	: Die(4, newValue) //call the second superclass constructor
{
	//no code needed
}

//destructor
D4::~D4() {
	//no code needed
}

//copy constructor
D4::D4(const D4& df)
	: Die(df) //call the superclass copy constructor
{
	//no code needed
}

//move constructor
D4::D4(D4&& df)
	: Die(df) //call the superclass move constructor
{
	//no code needed
}

//assignment operator
D4& D4::operator=(const D4& src) {
	Die::operator=(src); //call the superclass assignment operator
	return *this; //return the object
}

//move operator
D4& D4::operator=(D4&& src) {
	Die::operator=(src); //call the superclass move operator
	return *this; //return the object
}

//end of implementation
