/*
 * InvalidDictEntryException.cpp
 * Implements an exception that is thrown when an invalid dictionary entry is found
 * Created by Andrew Davis
 * Created on 3/12/2017
 * All rights reserved
 */

//include header
#include "InvalidDictEntryException.h"

//constructor
InvalidDictEntryException::InvalidDictEntryException(const char* badEntry)
	: errorString(badEntry) //init the error message string with the bad entry
{
	this->errorString = "InvalidDictEntryException thrown! Bad entry: " + this->errorString; //append a prefix to the error string
}

//destructor
InvalidDictEntryException::~InvalidDictEntryException() {
	this->errorString.clear(); //clear the error string
}

//copy constructor
InvalidDictEntryException::InvalidDictEntryException(const InvalidDictEntryException& idee)
	: errorString(idee.errorString) //copy the error string
{
	//no code needed
}

//move constructor
InvalidDictEntryException::InvalidDictEntryException(InvalidDictEntryException&& idee)
	: errorString(idee.errorString) //move the error string
{
	idee.errorString.clear(); //empty the temporary's error string
}

//assignment operator
InvalidDictEntryException& InvalidDictEntryException::operator=(const InvalidDictEntryException& src) {
	this->errorString = src.errorString; //assign the error string
	return *this; //return the object
}

//move operator
InvalidDictEntryException& InvalidDictEntryException::operator=(InvalidDictEntryException&& src) {
	this->errorString = src.errorString; //move the error string
	src.errorString.clear(); //empty the temporary's error string
	return *this; //return the object
}

//overridden what() method - called when the exception is thrown
const char* InvalidDictEntryException::what() const throw() {
	return this->errorString.c_str(); //return the error string as a C string
}

//end of implementation


