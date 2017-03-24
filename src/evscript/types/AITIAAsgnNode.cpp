/*
 * AITIAAsgnNode.cpp
 * Implements a class that represents an AST node that marks an array-dereference-to-array-dereference variable assignment
 * Created by Andrew Davis
 * Created on 3/24/2017
 * Open source (GPL license)
 */

//include header
#include "AITIAAsgnNode.h"

//constructor
AITIAAsgnNode::AITIAAsgnNode(const ArrayRef* newLval, const ArrayRef* newRval)
	: GenAsgnNode(EnumAsgnType::AITIA), lvalRef(nullptr), rvalRef(nullptr) //call superconstructor and init the fields
{
	if(newLval == nullptr) { //if the new lval pointer is invalid
		throw InvalidStateException("Lval pointer is null in AITIAAsgnNode constructor"); //then throw an exception
	}
	if(newRval == nullptr) { //if the new value pointer is invalid
		throw InvalidStateException("Rval pointer is null in AITIAAsgnNode constructor"); //then throw an exception
	}
	this->lvalRef = new ArrayRef(*newLval); //init the lval field
	this->rvalRef = new ArrayRef(*newRval); //init the rval field
}

//destructor
AITIAAsgnNode::~AITIAAsgnNode() {
	this->free(); //deallocate the object
}

//copy constructor
AITIAAsgnNode::AITIAAsgnNode(const AITIAAsgnNode& aan)
	: GenAsgnNode(aan), lvalRef(nullptr), rvalRef(nullptr) //call superclass copy constructor and null the fields
{
	this->lvalRef = new ArrayRef(*aan.lvalRef); //copy the lval reference
	this->rvalRef = new ArrayRef(*aan.rvalRef); //copy the rval reference
}

//move constructor
AITIAAsgnNode::AITIAAsgnNode(AITIAAsgnNode&& aan)
	: GenAsgnNode(aan), lvalRef(nullptr), rvalRef(nullptr) //call superclass move constructor and null the fields
{
	this->lvalRef = new ArrayRef(*aan.lvalRef); //move the lval reference
	this->rvalRef = new ArrayRef(*aan.rvalRef); //move the rval reference
	aan.free(); //deallocate the temporary
}

//assignment operator
AITIAAsgnNode& AITIAAsgnNode::operator=(const AITIAAsgnNode& src) {
	GenAsgnNode::operator=(src); //call superclass assignment operator
	*this->lvalRef = *src.lvalRef; //assign the lval reference
	*this->rvalRef = *src.rvalRef; //assign the rval reference
	return *this; //return the object
}

//move operator
AITIAAsgnNode& AITIAAsgnNode::operator=(AITIAAsgnNode&& src) {
	GenAsgnNode::operator=(src); //call superclass move operator
	*this->lvalRef = *src.lvalRef; //move the lval reference
	*this->rvalRef = *src.rvalRef; //move the rval reference
	src.free(); //deallocate the object
	return *this; //return the object
}

//getter methods

//lval method - gets and sets the lvalRef field
ArrayRef* AITIAAsgnNode::lval() {
	return this->lvalRef; //return the lval pointer
}

//get method - returns the ArrayRef node used to calculate the value assigned to the lval reference
const ArrayRef* AITIAAsgnNode::getRval() const {
	return this->rvalRef; //return the rval pointer
}

//private method

//free method - deallocates the object
void AITIAAsgnNode::free() {
	delete this->lvalRef; //deallocate the lval reference
	this->lvalRef = nullptr; //and zero it out
	delete this->rvalRef; //deallocate the rval reference
	this->rvalRef = nullptr; //and zero it out
}

//end of implementation
