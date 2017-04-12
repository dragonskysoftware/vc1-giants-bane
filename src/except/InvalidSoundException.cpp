/*
 * InvalidSoundException.cpp
 * Implements an exception that is thrown when an invalid sound is found
 * Created by Andrew Davis
 * Created on 4/12/2017
 * All rights reserved
 */

//include header
#include "InvalidSoundException.h"

//constructor
InvalidSoundException::InvalidSoundException(const char* soundName, const char* error)
	: errorString() //init the error message string
{
	this->errorString = "InvalidSoundException thrown with a bad sound: " + std::string(soundName) + " and an error: " + std::string(error); //append a prefix to the error string
}

//destructor
InvalidSoundException::~InvalidSoundException() {
	this->errorString.clear(); //clear the error string
}

//copy constructor
InvalidSoundException::InvalidSoundException(const InvalidSoundException& ise)
	: errorString(ise.errorString) //copy the error string
{
	//no code needed
}

//move constructor
InvalidSoundException::InvalidSoundException(InvalidSoundException&& ise)
	: errorString(ise.errorString) //move the error string
{
	ise.errorString.clear(); //empty the temporary's error string
}

//assignment operator
InvalidSoundException& InvalidSoundException::operator=(const InvalidSoundException& src) {
	this->errorString = src.errorString; //assign the error string
	return *this; //return the object
}

//move operator
InvalidSoundException& InvalidSoundException::operator=(InvalidSoundException&& src) {
	this->errorString = src.errorString; //move the error string
	src.errorString.clear(); //empty the temporary's error string
	return *this; //return the object
}

//overridden what() method - called when the exception is thrown
const char* InvalidSoundException::what() const throw() {
	return this->errorString.c_str(); //return the error string as a C string
}

//end of implementation


