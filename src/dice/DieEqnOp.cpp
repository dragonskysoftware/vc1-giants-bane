/*
 * DieEqnOp.cpp
 * Implements a class that represents a operation AST node for die equations
 * Created by Andrew Davis
 * Created on 6/27/2017
 * Open source (GPL license)
 */

//include header
#include "DieEqnOp.h"

//constructor
DieEqnOp::DieEqnOp(EnumEqnOps newOp, const std::string& newValue, DieEqnAST* newLeft, DieEqnAST* newRight)
	: DieEqnAST(EnumEqnAST::OP, newValue, newLeft, newRight), op(newOp)
{
	//no code needed
}

//destructor
DieEqnOp::~DieEqnOp() {
	//no code needed
}

//copy constructor
DieEqnOp::DieEqnOp(const DieEqnOp& deo)
	: DieEqnAST(deo), op(deo.op) //copy the fields
{
	//no code needed
}

//move constructor
DieEqnOp::DieEqnOp(DieEqnOp&& deo)
	: DieEqnAST(deo), op(deo.op) //move the fields
{
	//no code needed
}

//assignment operator
DieEqnOp& DieEqnOp::operator=(const DieEqnOp& src) {
	DieEqnAST::operator=(src); //call superclass assignment operator
	this->op = src.op; //assign the operation type
	return *this; //and return the object
}

//move operator
DieEqnOp& DieEqnOp::operator=(DieEqnOp&& src) {
	DieEqnAST::operator=(src); //call superclass move operator
	this->op = src.op; //move the operation type
	return *this; //and return the object
}

//getter methods

//getOp method - returns the operation type
EnumEqnOps DieEqnOp::getOp() const {
	return this->op; //return the operation type field
}

//getSymbol method - returns the operation symbol
char DieEqnOp::getSymbol() const {
	return this->value[0]; //return the first character in the value
}

//end of implementation
