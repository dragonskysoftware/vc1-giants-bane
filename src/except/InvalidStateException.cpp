/*
 * InvalidStateException.cpp
 * Implements an exception that is thrown when an object enters an invalid operational state
 * Created by Andrew Davis
 * Created on 3/11/2017
 * All rights reserved
 */

//include header
#include "InvalidStateException.h"

//constructor
InvalidStateException::InvalidStateException(const char* msg)
	: errorString(msg) //init the error message string
{
	this->errorString = "InvalidStateException thrown! Message: " + this->errorString; //append a prefix to the error string
}

//destructor
InvalidStateException::~InvalidStateException() {
	this->errorString.clear(); //clear the error string
}

//copy constructor
InvalidStateException::InvalidStateException(const InvalidStateException& ise)
	: errorString(ise.errorString) //copy the error string
{
	//no code needed
}

//move constructor
InvalidStateException::InvalidStateException(InvalidStateException&& ise)
	: errorString(ise.errorString) //move the error string
{
	ise.errorString.clear(); //empty the temporary's error string
}

//assignment operator
InvalidStateException& InvalidStateException::operator=(const InvalidStateException& src) {
	this->errorString = src.errorString; //assign the error string
	return *this; //return the object
}

//move operator
InvalidStateException& InvalidStateException::operator=(InvalidStateException&& src) {
	this->errorString = src.errorString; //move the error string
	src.errorString.clear(); //empty the temporary's error string
	return *this; //return the object
}

//overridden what() method - called when the exception is thrown
const char* InvalidStateException::what() const throw() {
	return this->errorString.c_str(); //return the error string as a C string
}

//end of implementation


