/*
 * OutOfRangeException.cpp
 * Implements an exception that is thrown when an object enters an invalid operational state
 * Created by Andrew Davis
 * Created on 3/11/2017
 * Open source (GPL license)
 */

//include header
#include "OutOfRangeException.h"

//constructor
OutOfRangeException::OutOfRangeException(int badIndex)
	: errorString("") //init the error message string
{
	this->errorString = "OutOfRangeException thrown! Bad index: " + std::to_string(badIndex); //assemble the error string
}

//destructor
OutOfRangeException::~OutOfRangeException() {
	this->errorString.clear(); //clear the error string
}

//copy constructor
OutOfRangeException::OutOfRangeException(const OutOfRangeException& ore)
	: errorString(ore.errorString) //copy the error string
{
	//no code needed
}

//move constructor
OutOfRangeException::OutOfRangeException(OutOfRangeException&& ore)
	: errorString(ore.errorString) //move the error string
{
	ore.errorString.clear(); //empty the temporary's error string
}

//assignment operator
OutOfRangeException& OutOfRangeException::operator=(const OutOfRangeException& src) {
	this->errorString = src.errorString; //assign the error string
	return *this; //return the object
}

//move operator
OutOfRangeException& OutOfRangeException::operator=(OutOfRangeException&& src) {
	this->errorString = src.errorString; //move the error string
	src.errorString.clear(); //empty the temporary's error string
	return *this; //return the object
}

//overridden what() method - called when the exception is thrown
const char* OutOfRangeException::what() const throw() {
	return this->errorString.c_str(); //return the error string as a C string
}

//end of implementation


