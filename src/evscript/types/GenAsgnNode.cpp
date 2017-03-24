/*
 * GenAsgnNode.cpp
 * Implements a class that represents an AST node that marks a generalized variable assignment
 * Created by Andrew Davis
 * Created on 3/24/2017
 * Open source (GPL license)
 */

//include header
#include "GenAsgnNode.h"

//constructor
GenAsgnNode::GenAsgnNode(EnumAsgnType newAssignType)
	: ASTNode(EnumNodeType::EQU, nullptr, nullptr), assignmentType(newAssignType) //call superconstructor and init the field
{
	//no code needed
}

//destructor
GenAsgnNode::~GenAsgnNode() {
	//no code needed - superclass takes care of it all
}

//copy constructor
GenAsgnNode::GenAsgnNode(const GenAsgnNode& gan)
	: ASTNode(gan), assignmentType(gan.assignmentType) //call superclass copy constructor and copy the field
{
	//no code needed
}

//move constructor
GenAsgnNode::GenAsgnNode(GenAsgnNode&& gan)
	: ASTNode(gan), assignmentType(gan.assignmentType) //call superclass move constructor and move the field
{
	//no code needed
}

//assignment operator
GenAsgnNode& GenAsgnNode::operator=(const GenAsgnNode& src) {
	ASTNode::operator=(src); //call superclass assignment operator
	this->assignmentType = src.assignmentType; //assign the assignment type field
	return *this; //return the object
}

//move operator
GenAsgnNode& GenAsgnNode::operator=(GenAsgnNode&& src) {
	ASTNode::operator=(src); //call superclass move operator
	this->assignmentType = src.assignmentType; //move the assignment type field
	return *this; //return the object
}

//getter method

//getAssignType method - returns the assignment type of the GenAsgnNode
EnumAsgnType GenAsgnNode::getAssignType() const {
	return this->assignmentType; //return the assignment type field
}

//emd of implementation
