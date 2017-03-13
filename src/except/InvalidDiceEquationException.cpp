/*
 * InvalidDiceEquationException.cpp
 * Implements an exception that is thrown when an invalid dice equation string is supplied for parsing
 * Created by Andrew Davis
 * Created on 3/13/2017
 * Open source (GPL license)
 */

//include header
#include "InvalidDiceEquationException.h"

//constructor
InvalidDiceEquationException::InvalidDiceEquationException(const char* badEqn)
	: errorString(badEqn) //init the error message string
{
	this->errorString = "InvalidDiceEquationException thrown! Equation: " + this->errorString; //append a prefix to the error string
}

//destructor
InvalidDiceEquationException::~InvalidDiceEquationException() {
	this->errorString.clear(); //clear the error string
}

//copy constructor
InvalidDiceEquationException::InvalidDiceEquationException(const InvalidDiceEquationException& idee)
	: errorString(idee.errorString) //copy the error string
{
	//no code needed
}

//move constructor
InvalidDiceEquationException::InvalidDiceEquationException(InvalidDiceEquationException&& idee)
	: errorString(idee.errorString) //move the error string
{
	idee.errorString.clear(); //empty the temporary's error string
}

//assignment operator
InvalidDiceEquationException& InvalidDiceEquationException::operator=(const InvalidDiceEquationException& src) {
	this->errorString = src.errorString; //assign the error string
	return *this; //return the object
}

//move operator
InvalidDiceEquationException& InvalidDiceEquationException::operator=(InvalidDiceEquationException&& src) {
	this->errorString = src.errorString; //move the error string
	src.errorString.clear(); //empty the temporary's error string
	return *this; //return the object
}

//overridden what() method - called when the exception is thrown
const char* InvalidDiceEquationException::what() const throw() {
	return this->errorString.c_str(); //return the error string as a C string
}

//end of implementation


