/*
 * D12.cpp
 * Implements a class that represents a 12-sided die
 * Created by Andrew Davis
 * Created on 3/11/2017
 * Open source (GPL license)
 */

//include header
#include "D12.h"

//first constructor - creates a D12 with a randomized value
D12::D12()
	: Die(12) //call the first superclass constructor
{
	//no code needed
}

//second constructor - creates a D12 with a set value
D12::D12(int newValue)
	: Die(12, newValue) //call the second superclass constructor
{
	//no code needed
}

//destructor
D12::~D12() {
	//no code needed
}

//copy constructor
D12::D12(const D12& dtt)
	: Die(dtt) //call the superclass copy constructor
{
	//no code needed
}

//move constructor
D12::D12(D12&& dtt)
	: Die(dtt) //call the superclass move constructor
{
	//no code needed
}

//assignment operator
D12& D12::operator=(const D12& src) {
	Die::operator=(src); //call the superclass assignment operator
	return *this; //return the object
}

//move operator
D12& D12::operator=(D12&& src) {
	Die::operator=(src); //call the superclass move operator
	return *this; //return the object
}

//end of implementation
