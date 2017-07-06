/*
 * DieEqnNum.cpp
 * Implements a class that represents a numeric AST node for die equations
 * Created by Andrew Davis
 * Created on 6/26/2017
 * Open source (GPL license)
 */

//include header
#include "DieEqnNum.h"

//constructor
DieEqnNum::DieEqnNum(const std::string& newValue)
	: DieEqnAST(EnumEqnAST::NUM, newValue, nullptr, nullptr)
{
	//no code needed
}

//destructor
DieEqnNum::~DieEqnNum() {
	//no code needed
}

//copy constructor
DieEqnNum::DieEqnNum(const DieEqnNum& den)
	: DieEqnAST(den) //call superclass copy constructor
{
	//no code needed
}

//move constructor
DieEqnNum::DieEqnNum(DieEqnNum&& den)
	: DieEqnAST(den) //call superclass move constructor
{
	//no code needed
}

//assignment operator
DieEqnNum& DieEqnNum::operator=(const DieEqnNum& src) {
	DieEqnAST::operator=(src); //call superclass assignment operator
	return *this; //and return the object
}

//move operator
DieEqnNum& DieEqnNum::operator=(DieEqnNum&& src) {
	DieEqnAST::operator=(src); //call superclass move operator
	return *this; //and return the object
}

//getter method

//intValue method - returns the value of the AST as an int
int DieEqnNum::intValue() const {
	return std::stoi(this->value); //return the value field as an int
}

//end of implementation
