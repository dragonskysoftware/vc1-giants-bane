/*
 * DieEqnParserException.cpp
 * Implements an exception that is thrown when an 
 * invalid die equation is processed by the die equation parser
 * Created by Andrew Davis
 * Created on 6/27/2017
 * Open source (GPL license)
 */

//include header
#include "DieEqnParserException.h"

//constructor
DieEqnParserException::DieEqnParserException(const std::string& badToken)
	: msg(badToken) //init the field
{
	//append a prefix to the message
	this->msg = "Syntax error found on token with value " + this->msg;
}

//destructor
DieEqnParserException::~DieEqnParserException() {
	//no code needed
}

//copy constructor
DieEqnParserException::DieEqnParserException(const DieEqnParserException& depe)
	: msg(depe.msg) //copy the message
{
	//no code needed
}

//move constructor
DieEqnParserException::DieEqnParserException(DieEqnParserException&& depe)
	: msg(depe.msg) //move the message
{
	//no code needed
}

//assignment operator
DieEqnParserException& DieEqnParserException::operator=(const DieEqnParserException& src) {
	this->msg = src.msg; //assign the message field
	return *this; //and return the object
}

//move operator
DieEqnParserException& DieEqnParserException::operator=(DieEqnParserException&& src) {
	this->msg = src.msg; //move the message field
	return *this; //and return the object
}

//overridden what method - called when the exception is thrown
const char* DieEqnParserException::what() const throw() {
	return this->msg.c_str(); //return the message field as a C string
}

//end of implementation
