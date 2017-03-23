/*
 * UserFnCall.cpp
 * Implements a class that represents an AST node that marks a call to a user-defined function
 * Created by Andrew Davis
 * Created on 3/21/2017
 * Open source (GPL license)
 */

//include header
#include "UserFnCall.h"

//constructor
UserFnCall::UserFnCall(Symbol* newSym, const ASTNode* newLeft)
	: ASTNode(EnumNodeType::CALL, newLeft, nullptr), sym(newSym) //call superconstructor and init the symbol field
{
	//no code needed
}

//destructor
UserFnCall::~UserFnCall() {
	//no code needed
}

//copy constructor
UserFnCall::UserFnCall(const UserFnCall& ufc)
	: ASTNode(ufc), sym(ufc.sym) //call superclass copy constructor and copy the symbol field
{
	//no code needed
}

//move constructor
UserFnCall::UserFnCall(UserFnCall&& ufc)
	: ASTNode(ufc), sym(ufc.sym) //call superclass move constructor and move the symbol field
{
	//no code needed
}

//assignment operator
UserFnCall& UserFnCall::operator=(const UserFnCall& src) {
	ASTNode::operator=(src); //call superclass assignment operator
	this->sym = src.sym; //assign the symbol field
	return *this; //return the object
}

//move operator
UserFnCall& UserFnCall::operator=(UserFnCall&& src) {
	ASTNode::operator=(src); //call superclass move operator
	this->sym = src.sym; //move the symbol field
	return *this; //return the object
}

//getter method

//getSymbol method - returns the symbol pointer for the user-defined function call
const Symbol* UserFnCall::getSymbol() const {
	return this->sym; //return the symbol pointer
}

//end of implementation
