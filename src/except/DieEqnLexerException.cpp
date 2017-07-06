/*
 * DieEqnLexerException.cpp
 * Implements an exception that is thrown when an 
 * invalid die equation is processed by the die equation lexer
 * Created by Andrew Davis
 * Created on 6/27/2017
 * Open source (GPL license)
 */

//include header
#include "DieEqnLexerException.h"

//constructor
DieEqnLexerException::DieEqnLexerException(const std::string& badEqn)
	: msg(badEqn) //init the field
{
	//append a prefix to the message
	this->msg = "Error lexing die equation " + this->msg;
}

//destructor
DieEqnLexerException::~DieEqnLexerException() {
	//no code needed
}

//copy constructor
DieEqnLexerException::DieEqnLexerException(const DieEqnLexerException& dele)
	: msg(dele.msg) //copy the message
{
	//no code needed
}

//move constructor
DieEqnLexerException::DieEqnLexerException(DieEqnLexerException&& dele)
	: msg(dele.msg) //move the message
{
	//no code needed
}

//assignment operator
DieEqnLexerException& DieEqnLexerException::operator=(const DieEqnLexerException& src) {
	this->msg = src.msg; //assign the message field
	return *this; //and return the object
}

//move operator
DieEqnLexerException& DieEqnLexerException::operator=(DieEqnLexerException&& src) {
	this->msg = src.msg; //move the message field
	return *this; //and return the object
}

//overridden what method - called when the exception is thrown
const char* DieEqnLexerException::what() const throw() {
	return this->msg.c_str(); //return the message field as a C string
}

//end of implementation
