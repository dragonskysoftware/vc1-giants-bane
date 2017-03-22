/*
 * ConstNode.cpp
 * Implements a class that represents an AST node that holds a constant value
 * Created by Andrew Davis
 * Created on 3/22/2017
 * Open source (GPL license)
 */

//include header
#include "ConstNode.h"

//constructor 1 - constructs from a const reference
ConstNode::ConstNode(const Variant& newValue)
	: ASTNode(EnumNodeType::CONST, nullptr, nullptr), value(newValue)
{
	//no code needed
}

//constructor 2 - constructs from a pointer
ConstNode::ConstNode(const Variant* newValue)
	: ConstNode(*newValue) //call other constructor
{
	//no code needed
}

//destructor
ConstNode::~ConstNode() {
	//no code needed - superclass takes care of it all
}

//copy constructor
ConstNode::ConstNode(const ConstNode& cn)
	: ASTNode(cn), value(cn.value) //call superclass copy constructor and copy the value
{
	//no code needed
}

//move constructor
ConstNode::ConstNode(ConstNode&& cn)
	: ASTNode(cn), value(cn.value) //call superclass move constructor and move the value
{
	//no code needed
}

//assignment operator
ConstNode& ConstNode::operator=(const ConstNode& src) {
	ASTNode::operator=(src); //call superclass assignment operator
	this->value = src.value; //assign the value
	return *this; //and return the object
}

//move operator
ConstNode& ConstNode::operator=(ConstNode&& src) {
	ASTNode::operator=(src); //call superclass move operator
	this->value = src.value; //move the value
	return *this; //and return the object
}

//getter method

//getValue method - returns the constant value stored in the node
const Variant& ConstNode::getValue() const {
	return this->value; //return the value field
}

//end of implementation
