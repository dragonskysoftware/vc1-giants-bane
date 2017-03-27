/*
 * SymbolTableException.cpp
 * Implements an exception that is thrown when a problem is found with the EvScript symbol table
 * Created by Andrew Davis
 * Created on 3/27/2017
 * Open source (GPL license)
 */

//include header
#include "SymbolTableException.h"

//constructor
SymbolTableException::SymbolTableException(const char* msg)
	: errorString(msg) //init the error message string
{
	this->errorString = "SymbolTableException thrown! Message: " + this->errorString; //append a prefix to the error string
}

//destructor
SymbolTableException::~SymbolTableException() {
	this->errorString.clear(); //clear the error string
}

//copy constructor
SymbolTableException::SymbolTableException(const SymbolTableException& ste)
	: errorString(ste.errorString) //copy the error string
{
	//no code needed
}

//move constructor
SymbolTableException::SymbolTableException(SymbolTableException&& ste)
	: errorString(ste.errorString) //move the error string
{
	ste.errorString.clear(); //empty the temporary's error string
}

//assignment operator
SymbolTableException& SymbolTableException::operator=(const SymbolTableException& src) {
	this->errorString = src.errorString; //assign the error string
	return *this; //return the object
}

//move operator
SymbolTableException& SymbolTableException::operator=(SymbolTableException&& src) {
	this->errorString = src.errorString; //move the error string
	src.errorString.clear(); //empty the temporary's error string
	return *this; //return the object
}

//overridden what() method - called when the exception is thrown
const char* SymbolTableException::what() const throw() {
	return this->errorString.c_str(); //return the error string as a C string
}

//end of implementation


