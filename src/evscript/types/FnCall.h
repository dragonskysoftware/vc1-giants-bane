/*
 * FnCall.h
 * Declares a class that represents an AST node that holds built-in function call data
 * Created by Andrew Davis
 * Created on 3/21/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef FN_CALL_H
#define FN_CALL_H

//includes
#include "EnumFunc.h"
#include "ASTNode.h"
#include "EnumNodeType.h"

//class declaration
class FnCall final : public ASTNode
{
	//public fields and methods
	public:
		//constructor
		FnCall(EnumFunc newID, const ASTNode* newLeft);

		//destructor
		~FnCall();

		//copy constructor
		FnCall(const FnCall& fc);

		//move constructor
		FnCall(FnCall&& fc);

		//assignment operator
		FnCall& operator=(const FnCall& src);

		//move operator
		FnCall& operator=(FnCall&& src);

		//getter method
		EnumFunc getFunctionID() const; //returns the ID of the function call represented by the FnCall node
	
	//private fields and methods
	private:
		//field
		EnumFunc functionID; //the ID of the represented function call

};

#endif
