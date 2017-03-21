/*
 * MathNode.cpp
 * Implements a class that represents an AST node that marks a math operation
 * Created by Andrew Davis
 * Created on 3/21/2017
 * Open source (GPL license)
 */

//include header
#include "MathNode.h"

//constructor
MathNode::MathNode(EnumMathOps newOp, const ASTNode* newLeft, const ASTNode* newRight)
	: ASTNode(EnumNodeType::MATH, newLeft, newRight), operation(newOp) //call superconstructor and init the operation field
{
	//no code needed
}

//destructor
MathNode::~MathNode() {
	//no code needed - superclass takes care of it all
}

//copy constructor
MathNode::MathNode(const MathNode& mn)
	: ASTNode(mn), operation(mn.operation) //call superclass copy constructor and copy the operation field
{
	//no code needed
}

//move constructor
MathNode::MathNode(MathNode&& mn)
	: ASTNode(mn), operation(mn.operation) //call superclass move constructor and move the operation field
{
	//no code needed
}

//assignment operator
MathNode& MathNode::operator=(const MathNode& src) {
	ASTNode::operator=(src); //call superclass assignment operator
	this->operation = src.operation; //assign the operation field
	return *this; //return the object
}

//move operator
MathNode& MathNode::operator=(MathNode&& src) {
	ASTNode::operator=(src); //call superclass move operator
	this->operation = src.operation; //move the operation field
	return *this; //return the object
}

//getter method

//getOperation method - returns the MathNode's operation
EnumMathOps MathNode::getOperation() const {
	return this->operation; //return the operation field
}

//end of implementation

