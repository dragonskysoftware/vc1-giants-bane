/*
 * GameCall.h
 * Declares a class that represents an AST node that holds game call data
 * Created by Andrew Davis
 * Created on 3/21/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef GAME_CALL_H
#define GAME_CALL_H

//includes
#include "EnumCall.h"
#include "ASTNode.h"
#include "EnumNodeType.h"

//class declaration
class GameCall final : public ASTNode
{
	//public fields and methods
	public:
		//constructor
		GameCall(EnumCall newID, const ASTNode* newLeft);

		//destructor
		~GameCall();

		//copy constructor
		GameCall(const GameCall& gc);

		//move constructor
		GameCall(GameCall&& gc);

		//assignment operator
		GameCall& operator=(const GameCall& src);

		//move operator
		GameCall& operator=(GameCall&& src);

		//getter method
		EnumCall getCallID() const; //returns the ID of the game call represented by the GameCall node
	
	//private fields and methods
	private:
		//field
		EnumCall callID; //the ID of the represented game call

};

#endif
