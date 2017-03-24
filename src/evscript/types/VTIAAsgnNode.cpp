/*
 * VTIAAsgnNode.cpp
 * Implements a class that represents an AST node that marks a value-to-array-dereference variable assignment
 * Created by Andrew Davis
 * Created on 3/24/2017
 * Open source (GPL license)
 */

//include header
#include "VTIAAsgnNode.h"

//constructor
VTIAAsgnNode::VTIAAsgnNode(Symbol* newSym, const ArrayRef* newRef)
	: GenAsgnNode(EnumAsgnType::VTIA), sym(newSym), ref(nullptr) //call superconstructor and init the fields
{
	if(newSym == nullptr) { //if the new symbol pointer is invalid
		throw InvalidStateException("Symbol pointer is null in VTIAAsgnNode constructor"); //then throw an exception
	}
	if(newRef == nullptr) { //if the new value pointer is invalid
		throw InvalidStateException("ArrayRef pointer is null in VTIAAsgnNode constructor"); //then throw an exception
	}
	this->ref = new ArrayRef(*newRef); //init the value node
}

//destructor
VTIAAsgnNode::~VTIAAsgnNode() {
	this->free(); //deallocate the object
}

//copy constructor
VTIAAsgnNode::VTIAAsgnNode(const VTIAAsgnNode& van)
	: GenAsgnNode(van), sym(van.sym), ref(nullptr) //call superclass copy constructor and copy the symbol pointer
{
	this->ref = new ArrayRef(*van.ref); //copy the reference
}

//move constructor
VTIAAsgnNode::VTIAAsgnNode(VTIAAsgnNode&& van)
	: GenAsgnNode(van), sym(van.sym), ref(nullptr) //call superclass move constructor and move the symbol pointer
{
	this->ref = new ArrayRef(*van.ref); //move the reference
	van.free(); //deallocate the temporary
}

//assignment operator
VTIAAsgnNode& VTIAAsgnNode::operator=(const VTIAAsgnNode& src) {
	GenAsgnNode::operator=(src); //call superclass assignment operator
	this->sym = src.sym; //assign the symbol pointer
	*this->ref = *src.ref; //assign the reference
	return *this; //return the object
}

//move operator
VTIAAsgnNode& VTIAAsgnNode::operator=(VTIAAsgnNode&& src) {
	GenAsgnNode::operator=(src); //call superclass move operator
	this->sym = src.sym; //move the symbol pointer
	*this->ref = *src.ref; //move the reference
	src.free(); //deallocate the temporary
	return *this; //return the object
}

//getter methods

//symbol method - gets and sets the symbol field
Symbol* VTIAAsgnNode::symbol() {
	return this->sym; //return the symbol pointer
}

//getArrayRef method - returns the ArrayRef node used to calculate the value assigned to the symbol
const ArrayRef* VTIAAsgnNode::getArrayRef() const {
	return this->ref; //return the array reference
}

//private method

//free method - deallocates the object
void VTIAAsgnNode::free() {
	delete this->ref; //deallocate the array reference
	this->ref = nullptr; //and zero it out
}

//end of implementation
