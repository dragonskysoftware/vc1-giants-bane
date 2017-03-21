/*
 * GameCall.cpp
 * Implements a class that represents an AST node that holds game call data
 * Created by Andrew Davis
 * Created on 3/21/2017
 * Open source (GPL license)
 */

//include header
#include "GameCall.h"

//constructor
GameCall::GameCall(EnumCall newID, const ASTNode* newLeft)
	: ASTNode(EnumNodeType::GAME, newLeft, nullptr), callID(newID) //call superconstructor and init the ID field
{
	//no code needed
}

//destructor
GameCall::~GameCall() {
	//no code needed - superclass takes care of it all
}

//copy constructor
GameCall::GameCall(const GameCall& gc)
	: ASTNode(gc), callID(gc.callID) //call superclass copy constructor and copy the ID field
{
	//no code needed
}

//move constructor
GameCall::GameCall(GameCall&& gc)
	: ASTNode(gc), callID(gc.callID) //call superclass move constructor and move the ID field
{
	//no code needed
}

//assignment operator
GameCall& GameCall::operator=(const GameCall& src) {
	ASTNode::operator=(src); //call superclass assignment operator
	this->callID = src.callID; //assign the call ID
	return *this; //return the object
}

//move operator
GameCall& GameCall::operator=(GameCall&& src) {
	ASTNode::operator=(src); //call superclass move operator
	this->callID = src.callID; //move the call ID
	return *this; //return the object
}

//getter method

//getCallID method - returns the ID of the game call represented by this GameCall node
EnumCall GameCall::getCallID() const {
	return this->callID; //return the call ID field
}

//end of implementation
