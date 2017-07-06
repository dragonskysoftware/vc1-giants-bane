/*
 * DieEqnToken.cpp
 * Implements a class that represents a token for parsing die equations
 * Created by Andrew Davis
 * Created on 6/26/2017
 * Open source (GPL license)
 */

//include header
#include "DieEqnToken.h"

//constructor
DieEqnToken::DieEqnToken(EnumEqnToken newType, const std::string& newValue)
	: type(newType), value(newValue) //init the fields
{
	//no code needed
}

//destructor
DieEqnToken::~DieEqnToken() {
	//no code needed
}

//copy constructor
DieEqnToken::DieEqnToken(const DieEqnToken& det)
	: type(det.type), value(det.value) //copy the fields
{
	//no code needed
}

//move constructor
DieEqnToken::DieEqnToken(DieEqnToken&& det)
	: type(det.type), value(det.value) //move the fields
{
	//no code needed
}

//assignment operator
DieEqnToken& DieEqnToken::operator=(const DieEqnToken& src) {
	this->type = src.type; //assign the type field
	this->value = src.value; //assign the value field
	return *this; //and return the object
}

//move operator
DieEqnToken& DieEqnToken::operator=(DieEqnToken&& src) {
	this->type = src.type; //move the type field
	this->value = src.value; //move the value field
	return *this; //and return the object
}

//getter methods

//getType method - returns the token's type
EnumEqnToken DieEqnToken::getType() const {
	return this->type; //return the type field
}

//getValue method - returns the token's value
const std::string& DieEqnToken::getValue() const {
	return this->value; //return the value field
}

//end of implementation
