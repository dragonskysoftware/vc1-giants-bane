/*
 * CompNode.cpp
 * Implements a class that represents an AST node that marks a logical comparison
 * Created by Andrew Davis
 * Created on 3/21/2017
 * Open source (GPL license)
 */

//include header
#include "CompNode.h"

//constructor
CompNode::CompNode(EnumCompType newCompType, const ASTNode* newLeft, const ASTNode* newRight)
	: ASTNode(EnumNodeType::COMP, newLeft, newRight), comparisonType(newCompType) //call superconstructor and init the field
{
	//no code needed
}

//destructor
CompNode::~CompNode() {
	//no code needed - superclass takes care of it all
}

//copy constructor
CompNode::CompNode(const CompNode& cn)
	: ASTNode(cn), comparisonType(cn.comparisonType) //call superclass copy constructor and copy the field
{
	//no code needed
}

//move constructor
CompNode::CompNode(CompNode&& cn)
	: ASTNode(cn), comparisonType(cn.comparisonType) //call superclass move constructor and move the field
{
	//no code needed
}

//assignment operator
CompNode& CompNode::operator=(const CompNode& src) {
	ASTNode::operator=(src); //call superclass assignment operator
	this->comparisonType = src.comparisonType; //assign the comparison type
	return *this; //return the object
}

//move operator
CompNode& CompNode::operator=(CompNode&& src) {
	ASTNode::operator=(src); //call superclass move operator
	this->comparisonType = src.comparisonType; //move the comparison type
	return *this; //return the object
}

//getter method

//getComparisonType method - returns the comparison type of the CompNode
EnumCompType CompNode::getComparisonType() const {
	return this->comparisonType; //return the comparison type field
}

//end of implementation
