/*
 * BadDieException.cpp
 * Implements an exception that is thrown when a bad die is encountered
 * Created by Andrew Davis
 * Created on 6/26/2017
 * Open source (GPL license)
 */

//include header
#include "BadDieException.h"

//constructor
BadDieException::BadDieException(const char* newMsg)
	: msg(newMsg) //init the message field
{
	//append a prefix onto the message field
	this->msg = "BadDieException thrown! Message: " + this->msg;
}

//destructor
BadDieException::~BadDieException() {
	//no code needed
}

//copy constructor
BadDieException::BadDieException(const BadDieException& bde)
	: msg(bde.msg) //copy the message field
{
	//no code needed
}

//move constructor
BadDieException::BadDieException(BadDieException&& bde)
	: msg(bde.msg) //move the message field
{
	//no code needed
}

//assignment operator
BadDieException& BadDieException::operator=(const BadDieException& src) {
	this->msg = src.msg; //assign the message field
	return *this; //return the object
}

//move operator
BadDieException& BadDieException::operator=(BadDieException&& src) {
	this->msg = src.msg; //move the message field
	return *this; //return the object
}

//overridden what() method - called when the exception is thrown
const char* BadDieException::what() const throw() {
	return this->msg.c_str(); //return the message as a C string
}

//end of implementation
