/*
 * ATAAsgnNode.cpp
 * Implements a class that represents an AST node that marks a value-to-array-dereference variable assignment
 * Created by Andrew Davis
 * Created on 3/24/2017
 * Open source (GPL license)
 */

//include header
#include "ATAAsgnNode.h"

//constructor
ATAAsgnNode::ATAAsgnNode(Symbol* newLval, Symbol* newRval)
	: GenAsgnNode(EnumAsgnType::ATA), lvalSym(newLval), rvalSym(newRval) //call superconstructor and init the fields
{
	if(newLval == nullptr) { //if the new lval symbol pointer is invalid
		throw InvalidStateException("Lval symbol pointer is null in ATAAsgnNode constructor"); //then throw an exception
	}
	if(newRval == nullptr) { //if the new rval symbol pointer is invalid
		throw InvalidStateException("Rval pointer is null in ATAAsgnNode constructor"); //then throw an exception
	}
}

//destructor
ATAAsgnNode::~ATAAsgnNode() {
	//no code needed
}

//copy constructor
ATAAsgnNode::ATAAsgnNode(const ATAAsgnNode& van)
	: GenAsgnNode(van), lvalSym(van.lvalSym), rvalSym(van.rvalSym) //call superclass copy constructor and copy the symbols
{
	//no code needed
}

//move constructor
ATAAsgnNode::ATAAsgnNode(ATAAsgnNode&& van)
	: GenAsgnNode(van), lvalSym(van.lvalSym), rvalSym(van.rvalSym) //call superclass move constructor and move the symbols
{
	//no code needed
}

//assignment operator
ATAAsgnNode& ATAAsgnNode::operator=(const ATAAsgnNode& src) {
	GenAsgnNode::operator=(src); //call superclass assignment operator
	this->lvalSym = src.lvalSym; //assign the lval symbol pointer
	this->rvalSym = src.rvalSym; //assign the rval symbol pointer
	return *this; //return the object
}

//move operator
ATAAsgnNode& ATAAsgnNode::operator=(ATAAsgnNode&& src) {
	GenAsgnNode::operator=(src); //call superclass move operator
	this->lvalSym = src.lvalSym; //move the lval symbol pointer
	this->rvalSym = src.rvalSym; //move the rval symbol pointer
	return *this; //return the object
}

//getter methods

//lval method - gets and sets the lval symbol field
Symbol* ATAAsgnNode::lval() { 
	return this->lvalSym; //return the lval symbol pointer
}

//getRval method - gets the rval symbol field
const Symbol* ATAAsgnNode::getRval() const {
	return this->rvalSym; //return the rval symbol pointer
}

//end of implementation
