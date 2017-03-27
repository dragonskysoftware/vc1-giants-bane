/*
 * InvalidASTException.cpp
 * Implements an exception that is thrown when an invalid AST is found by the EvScript interpreter
 * Created by Andrew Davis
 * Created on 3/27/2017
 * Open source (GPL license)
 */

//include header
#include "InvalidASTException.h"

//constructor
InvalidASTException::InvalidASTException(const char* msg)
	: errorString(msg) //init the error message string
{
	this->errorString = "InvalidASTException thrown! Message: " + this->errorString; //append a prefix to the error string
}

//destructor
InvalidASTException::~InvalidASTException() {
	this->errorString.clear(); //clear the error string
}

//copy constructor
InvalidASTException::InvalidASTException(const InvalidASTException& iae)
	: errorString(iae.errorString) //copy the error string
{
	//no code needed
}

//move constructor
InvalidASTException::InvalidASTException(InvalidASTException&& iae)
	: errorString(iae.errorString) //move the error string
{
	iae.errorString.clear(); //empty the temporary's error string
}

//assignment operator
InvalidASTException& InvalidASTException::operator=(const InvalidASTException& src) {
	this->errorString = src.errorString; //assign the error string
	return *this; //return the object
}

//move operator
InvalidASTException& InvalidASTException::operator=(InvalidASTException&& src) {
	this->errorString = src.errorString; //move the error string
	src.errorString.clear(); //empty the temporary's error string
	return *this; //return the object
}

//overridden what() method - called when the exception is thrown
const char* InvalidASTException::what() const throw() {
	return this->errorString.c_str(); //return the error string as a C string
}

//end of implementation


