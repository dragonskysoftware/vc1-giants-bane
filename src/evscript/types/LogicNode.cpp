/*
 * LogicNode.cpp
 * Implements a class that represents an AST node that marks a logical operation
 * Created by Andrew Davis
 * Created on 3/21/2017
 * Open source (GPL license)
 */

//include header
#include "LogicNode.h"

//constructor
LogicNode::LogicNode(EnumLogicOps newOp, const ASTNode* newLeft, const ASTNode* newRight)
	: ASTNode(EnumNodeType::LOGIC, newLeft, newRight), operation(newOp) //call superconstructor and init the operation field
{
	//no code needed
}

//destructor
LogicNode::~LogicNode() {
	//no code needed - superclass takes care of it all
}

//copy constructor
LogicNode::LogicNode(const LogicNode& ln)
	: ASTNode(ln), operation(ln.operation) //call superclass copy constructor and copy the operation field
{
	//no code needed
}

//move constructor
LogicNode::LogicNode(LogicNode&& ln)
	: ASTNode(ln), operation(ln.operation) //call superclass move constructor and move the operation field
{
	//no code needed
}

//assignment operator
LogicNode& LogicNode::operator=(const LogicNode& src) {
	ASTNode::operator=(src); //call superclass assignment operator
	this->operation = src.operation; //assign the operation field
	return *this; //return the object
}

//move operator
LogicNode& LogicNode::operator=(LogicNode&& src) {
	ASTNode::operator=(src); //call superclass move operator
	this->operation = src.operation; //move the operation field
	return *this; //return the object
}

//getter method

//getOperation method - returns the LogicNode's operation
EnumLogicOps LogicNode::getOperation() const {
	return this->operation; //return the operation field
}

//end of implementation

