/*
 * VTVAsgnNode.cpp
 * Implements a class that represents an AST node that marks a value-to-value variable assignment
 * Created by Andrew Davis
 * Created on 3/24/2017
 * Open source (GPL license)
 */

//include header
#include "VTVAsgnNode.h"

//constructor
VTVAsgnNode::VTVAsgnNode(Symbol* newSym, const ASTNode* newVal)
	: GenAsgnNode(EnumAsgnType::VTV), sym(newSym), valueNode(nullptr) //call superconstructor and init the fields
{
	if(newSym == nullptr) { //if the new symbol pointer is invalid
		throw InvalidStateException("Symbol pointer is null in VTVAsgnNode constructor"); //then throw an exception
	}
	if(newVal == nullptr) { //if the new value pointer is invalid
		throw InvalidStateException("AST value pointer is null in VTVAsgnNode constructor"); //then throw an exception
	}
	this->valueNode = new ASTNode(*newVal); //init the value node
}

//destructor
VTVAsgnNode::~VTVAsgnNode() {
	this->free(); //deallocate the object
}

//copy constructor
VTVAsgnNode::VTVAsgnNode(const VTVAsgnNode& van)
	: GenAsgnNode(van), sym(van.sym), valueNode(nullptr) //call superclass copy constructor and copy the symbol pointer
{
	this->valueNode = new ASTNode(*van.valueNode); //copy the value node
}

//move constructor
VTVAsgnNode::VTVAsgnNode(VTVAsgnNode&& van)
	: GenAsgnNode(van), sym(van.sym), valueNode(nullptr) //call superclass move constructor and move the symbol pointer
{
	this->valueNode = new ASTNode(*van.valueNode); //move the value node
	van.free(); //deallocate the temporary
}

//assignment operator
VTVAsgnNode& VTVAsgnNode::operator=(const VTVAsgnNode& src) {
	GenAsgnNode::operator=(src); //call superclass assignment operator
	this->sym = src.sym; //assign the symbol pointer
	*this->valueNode = *src.valueNode; //assign the value node
	return *this; //return the object
}

//move operator
VTVAsgnNode& VTVAsgnNode::operator=(VTVAsgnNode&& src) {
	GenAsgnNode::operator=(src); //call superclass move operator
	this->sym = src.sym; //move the symbol pointer
	*this->valueNode = *src.valueNode; //move the value node
	src.free(); //deallocate the temporary
	return *this; //return the object
}

//getter methods

//symbol method - gets and sets the symbol field
Symbol* VTVAsgnNode::symbol() {
	return this->sym; //return the symbol pointer
}

//getValueNode method - returns the AST node used to calculate the value assigned to the symbol
const ASTNode* VTVAsgnNode::getValueNode() const {
	return this->valueNode; //return the value node
}

//private method

//free method - deallocates the object
void VTVAsgnNode::free() {
	delete this->valueNode; //deallocate the value node
	this->valueNode = nullptr; //and zero it out
}

//end of implementation
