/*
 * AITVAsgnNode.cpp
 * Implements a class that represents an AST node that marks an array-dereference-to-array-dereference variable assignment
 * Created by Andrew Davis
 * Created on 3/24/2017
 * Open source (GPL license)
 */

//include header
#include "AITVAsgnNode.h"

//constructor
AITVAsgnNode::AITVAsgnNode(const ArrayRef* newLval, const ASTNode* newRval)
	: GenAsgnNode(EnumAsgnType::AITIA), lvalRef(nullptr), rval(nullptr) //call superconstructor and init the fields
{
	if(newLval == nullptr) { //if the new lval pointer is invalid
		throw InvalidStateException("Lval pointer is null in AITVAsgnNode constructor"); //then throw an exception
	}
	if(newRval == nullptr) { //if the new value pointer is invalid
		throw InvalidStateException("Rval pointer is null in AITVAsgnNode constructor"); //then throw an exception
	}
	this->lvalRef = new ArrayRef(*newLval); //init the lval field
	this->rval = new ASTNode(*newRval); //init the rval field
}

//destructor
AITVAsgnNode::~AITVAsgnNode() {
	this->free(); //deallocate the object
}

//copy constructor
AITVAsgnNode::AITVAsgnNode(const AITVAsgnNode& aan)
	: GenAsgnNode(aan), lvalRef(nullptr), rval(nullptr) //call superclass copy constructor and null the fields
{
	this->lvalRef = new ArrayRef(*aan.lvalRef); //copy the lval reference
	this->rval = new ASTNode(*aan.rval); //copy the rval reference
}

//move constructor
AITVAsgnNode::AITVAsgnNode(AITVAsgnNode&& aan)
	: GenAsgnNode(aan), lvalRef(nullptr), rval(nullptr) //call superclass move constructor and null the fields
{
	this->lvalRef = new ArrayRef(*aan.lvalRef); //move the lval reference
	this->rval = new ASTNode(*aan.rval); //move the rval reference
	aan.free(); //deallocate the temporary
}

//assignment operator
AITVAsgnNode& AITVAsgnNode::operator=(const AITVAsgnNode& src) {
	GenAsgnNode::operator=(src); //call superclass assignment operator
	*this->lvalRef = *src.lvalRef; //assign the lval reference
	*this->rval = *src.rval; //assign the rval reference
	return *this; //return the object
}

//move operator
AITVAsgnNode& AITVAsgnNode::operator=(AITVAsgnNode&& src) {
	GenAsgnNode::operator=(src); //call superclass move operator
	*this->lvalRef = *src.lvalRef; //move the lval reference
	*this->rval = *src.rval; //move the rval reference
	src.free(); //deallocate the object
	return *this; //return the object
}

//getter methods

//lval method - gets and sets the lvalRef field
ArrayRef* AITVAsgnNode::lval() {
	return this->lvalRef; //return the lval pointer
}

//getRval method - returns the ASTNode used to calculate the value assigned to the lval reference
ASTNode* AITVAsgnNode::getRval() {
	return this->rval; //return the rval pointer
}

//private method

//free method - deallocates the object
void AITVAsgnNode::free() {
	delete this->lvalRef; //deallocate the lval reference
	this->lvalRef = nullptr; //and zero it out
	delete this->rval; //deallocate the rval
	this->rval = nullptr; //and zero it out
}

//end of implementation
