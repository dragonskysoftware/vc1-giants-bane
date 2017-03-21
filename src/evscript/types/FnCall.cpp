/*
 * FnCall.cpp
 * Implements a class that represents an AST node that holds built-in function call data
 * Created by Andrew Davis
 * Created on 3/21/2017
 * Open source (GPL license)
 */

//include header
#include "FnCall.h"

//constructor
FnCall::FnCall(EnumFunc newID, const ASTNode* newLeft)
	: ASTNode(EnumNodeType::FUNC, newLeft, nullptr), functionID(newID) //call superconstructor and init the ID field
{
	//no code needed
}

//destructor
FnCall::~FnCall() {
	//no code needed - superclass takes care of it all
}

//copy constructor
FnCall::FnCall(const FnCall& fc)
	: ASTNode(fc), functionID(fc.functionID) //call superclass copy constructor and copy the ID field
{
	//no code needed
}

//move constructor
FnCall::FnCall(FnCall&& fc)
	: ASTNode(fc), functionID(fc.functionID) //call superclass move constructor and move the ID field
{
	//no code needed
}

//assignment operator
FnCall& FnCall::operator=(const FnCall& src) {
	ASTNode::operator=(src); //call superclass assignment operator
	this->functionID = src.functionID; //assign the function ID
	return *this; //return the object
}

//move operator
FnCall& FnCall::operator=(FnCall&& src) {
	ASTNode::operator=(src); //call superclass move operator
	this->functionID = src.functionID; //move the function ID
	return *this; //return the object
}

//getter method

//getFunctionID method - returns the ID of the function call represented by this FnCall node
EnumFunc FnCall::getFunctionID() const {
	return this->functionID; //return the function ID field
}

//end of implementation
