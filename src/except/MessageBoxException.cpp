/*
 * MessageBoxException.cpp
 * Implements an exception that is thrown when an error is encountered with a message box
 * Created by Andrew Davis
 * Created on 4/19/2017
 * All rights reserved
 */

//include header
#include "MessageBoxException.h"

//constructor
MessageBoxException::MessageBoxException(const char* msg)
	: errorString(msg) //init the error message string
{
	this->errorString = "MessageBoxException thrown! Message: " + this->errorString; //append a prefix to the error string
}

//destructor
MessageBoxException::~MessageBoxException() {
	this->errorString.clear(); //clear the error string
}

//copy constructor
MessageBoxException::MessageBoxException(const MessageBoxException& mbe)
	: errorString(mbe.errorString) //copy the error string
{
	//no code needed
}

//move constructor
MessageBoxException::MessageBoxException(MessageBoxException&& mbe)
	: errorString(mbe.errorString) //move the error string
{
	mbe.errorString.clear(); //empty the temporary's error string
}

//assignment operator
MessageBoxException& MessageBoxException::operator=(const MessageBoxException& src) {
	this->errorString = src.errorString; //assign the error string
	return *this; //return the object
}

//move operator
MessageBoxException& MessageBoxException::operator=(MessageBoxException&& src) {
	this->errorString = src.errorString; //move the error string
	src.errorString.clear(); //empty the temporary's error string
	return *this; //return the object
}

//overridden what() method - called when the exception is thrown
const char* MessageBoxException::what() const throw() {
	return this->errorString.c_str(); //return the error string as a C string
}

//end of implementation


