/*
 * InvalidAbilityScoreException.cpp
 * Implements an exception that is thrown when an invalid ability score is encountered
 * Created by Andrew Davis
 * Created on 3/14/2017
 * Open source (GPL license)
 */

//include header
#include "InvalidAbilityScoreException.h"

//constructor
InvalidAbilityScoreException::InvalidAbilityScoreException(int badScore)
	: errorString("") //init the error message string
{
	this->errorString = "InvalidAbilityScoreException thrown! Bad score: " + std::to_string(badScore); //assemble the error str
}

//destructor
InvalidAbilityScoreException::~InvalidAbilityScoreException() {
	this->errorString.clear(); //clear the error string
}

//copy constructor
InvalidAbilityScoreException::InvalidAbilityScoreException(const InvalidAbilityScoreException& iase)
	: errorString(iase.errorString) //copy the error string
{
	//no code needed
}

//move constructor
InvalidAbilityScoreException::InvalidAbilityScoreException(InvalidAbilityScoreException&& iase)
	: errorString(iase.errorString) //move the error string
{
	iase.errorString.clear(); //empty the temporary's error string
}

//assignment operator
InvalidAbilityScoreException& InvalidAbilityScoreException::operator=(const InvalidAbilityScoreException& src) {
	this->errorString = src.errorString; //assign the error string
	return *this; //return the object
}

//move operator
InvalidAbilityScoreException& InvalidAbilityScoreException::operator=(InvalidAbilityScoreException&& src) {
	this->errorString = src.errorString; //move the error string
	src.errorString.clear(); //empty the temporary's error string
	return *this; //return the object
}

//overridden what() method - called when the exception is thrown
const char* InvalidAbilityScoreException::what() const throw() {
	return this->errorString.c_str(); //return the error string as a C string
}

//end of implementation


