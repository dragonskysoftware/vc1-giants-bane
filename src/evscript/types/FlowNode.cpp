/*
 * FlowNode.cpp
 * Implements a class that represents a control flow AST node
 * Created by Andrew Davis
 * Created on 3/21/2017
 * Open source (GPL license)
 */

//include header
#include "FlowNode.h"

//constructor
FlowNode::FlowNode(EnumNodeType newType, const ASTNode* newCond, const ASTNode* newThen, const ASTNode* newElse)
	: ASTNode(newType, nullptr, nullptr), condition(nullptr), thenBranch(nullptr), elseBranch(nullptr)
{
	//check for errors
	if(this->nodeType != EnumNodeType::IF && this->nodeType != EnumNodeType::WHL) { //if the node type is invalid
		throw InvalidStateException("Invalid node type in FlowNode constructor"); //then throw an exception
	}
	if(newCond == nullptr) { //if the condition is invalid
		throw InvalidStateException("Condition pointer is null in FlowNode constructor"); //then throw an exception
	}
	if(newThen == nullptr) { //if the "then branch" is invalid
		throw InvalidStateException("\"Then branch\" pointer is null in FlowNode constructor"); //then throw an exception
	}
	
	//initialize the condition and "then branch" fields
	this->condition = new ASTNode(*newCond); //copy in the condition pointer
	this->thenBranch = new ASTNode(*newThen); //copy in the "then branch"
	
	//initialize the "else branch" field
	if(newElse == nullptr) { //if the "else branch" is null
		this->elseBranch = nullptr; //then null the "else branch" field
	} else { //if it's not
		this->elseBranch = new ASTNode(*newElse); //copy in the "else branch"
	}
}

//destructor
FlowNode::~FlowNode() {
	this->free(); //deallocate the assets
}

//copy constructor
FlowNode::FlowNode(const FlowNode& fn)
	: ASTNode(fn), condition(nullptr), thenBranch(nullptr), elseBranch(nullptr) //call superclass copy constructor
{
	this->condition = new ASTNode(*fn.condition); //copy the condition field
	this->thenBranch = new ASTNode(*fn.thenBranch); //copy the "then branch" field
	if(fn.elseBranch != nullptr) { //if the other "else branch" isn't null
		this->elseBranch = new ASTNode(*fn.elseBranch); //then copy it in
	}
}

//move constructor
FlowNode::FlowNode(FlowNode&& fn)
	: ASTNode(fn), condition(nullptr), thenBranch(nullptr), elseBranch(nullptr) //call superclass move constructor
{
	this->condition = new ASTNode(*fn.condition); //move the condition field
	this->thenBranch = new ASTNode(*fn.thenBranch); //move the "then branch" field
	if(fn.elseBranch != nullptr) { //if the other "else branch" isn't null
		this->elseBranch = new ASTNode(*fn.elseBranch); //then move it in
	}
	fn.free(); //deallocate the temporary's assets
}

//assignment operator
FlowNode& FlowNode::operator=(const FlowNode& src) {
	ASTNode::operator=(src); //call superclass assignment operator
	*this->condition = *src.condition; //assign the condition field
	*this->thenBranch = *src.thenBranch; //assign the "then branch" field
	delete this->elseBranch; //deallocate this "else branch"
	this->elseBranch = nullptr; //and zero it out
	if(src.elseBranch != nullptr) { //if the other "else branch" isn't null
		this->elseBranch = new ASTNode(*src.elseBranch); //then assign it
	}
	return *this; //return the object
}

//move operator
FlowNode& FlowNode::operator=(FlowNode&& src) {
	ASTNode::operator=(src); //call superclass move operator
	*this->condition = *src.condition; //move the condition field
	*this->thenBranch = *src.thenBranch; //move the "then branch" field
	delete this->elseBranch; //deallocate this "else branch"
	this->elseBranch = nullptr; //and zero it out
	if(src.elseBranch != nullptr) { //if the other "else branch" isn't null
		this->elseBranch = new ASTNode(*src.elseBranch); //then move it
	}
	src.free(); //free the temporary's assets
	return *this; //return the object
}

//getter methods

//getCondition method - returns the condition AST node for the FlowNode
const ASTNode* FlowNode::getCondition() const {
	return this->condition; //return the condition pointer
}

//getThenBranch method - returns the "then branch" AST node for the FlowNode
const ASTNode* FlowNode::getThenBranch() const {
	return this->thenBranch; //return the "then branch" pointer
}

//getElseBranch method - returns the "else branch" AST node for the FlowNode
const ASTNode* FlowNode::getElseBranch() const {
	return this->elseBranch; //return the "else branch" pointer
}

//private method

//free method - deallocates the assets allocated by a FlowNode
void FlowNode::free() {
	//deallocate the pointers
	delete this->condition; //deallocate the condition
	delete this->thenBranch; //deallocate the "then branch"
	delete this->elseBranch; //deallocate the "else branch"

	//zero them out
	this->condition = nullptr; //zero the condition
	this->thenBranch = nullptr; //zero the "then branch"
	this->elseBranch = nullptr; //zero the "else branch"

	//done!
}

//end of implementation
