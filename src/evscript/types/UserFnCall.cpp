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
UserFnCall::UserFnCall(const Symbol* newSym, const ASTNode* newLeft)
	: ASTNode(EnumNodeType::CALL, newLeft, nullptr), sym(nullptr) //call superconstructor and null the symbol field
{
	if(newSym == nullptr) { //if the symbol supplied in the constructor is invalid
		throw InvalidStateException("Symbol pointer is null in UserFnCall constructor"); //then throw an exception
	} else { //if it's not
		this->sym = new Symbol(*newSym); //then construct this symbol field
	}
}

//destructor
UserFnCall::~UserFnCall() {
	delete this->sym; //deallocate the symbol field
	this->sym = nullptr; //and zero it out
}

//copy constructor
UserFnCall::UserFnCall(const UserFnCall& ufc)
	: ASTNode(ufc), sym(nullptr) //call superclass copy constructor and null the symbol field
{
	this->sym = new Symbol(*ufc.sym); //copy the symbol field
}

//move constructor
UserFnCall::UserFnCall(UserFnCall&& ufc)
	: ASTNode(ufc), sym(nullptr) //call superclass move constructor and null the symbol field
{
	this->sym = new Symbol(*ufc.sym); //move the symbol field
	delete ufc.sym; //deallocate the temporary's symbol field
	ufc.sym = nullptr; //and zero it out
}

//assignment operator
UserFnCall& UserFnCall::operator=(const UserFnCall& src) {
	ASTNode::operator=(src); //call superclass assignment operator
	*this->sym = *src.sym; //assign the symbol field
	return *this; //return the object
}

//move operator
UserFnCall& UserFnCall::operator=(UserFnCall&& src) {
	ASTNode::operator=(src); //call superclass move operator
	*this->sym = *src.sym; //move the symbol field
	delete src.sym; //deallocate the temporary's symbol field
	src.sym = nullptr; //and zero it out
	return *this; //return the object
}

//getter method

//getSymbol method - returns the symbol pointer for the user-defined function call
const Symbol* UserFnCall::getSymbol() const {
	return this->sym; //return the symbol pointer
}

//end of implementation
