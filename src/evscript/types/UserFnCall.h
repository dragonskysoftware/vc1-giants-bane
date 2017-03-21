/*
 * UserFnCall.h
 * Declares a class that represents an AST node that marks a call to a user-defined function
 * Created by Andrew Davis
 * Created on 3/21/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef USER_FN_CALL_H
#define USER_FN_CALL_H

//includes
#include "ASTNode.h"
#include "Symbol.h"
#include "EnumNodeType.h"
#include "../../except/InvalidStateException.h"

//class declaration
class UserFnCall final : public ASTNode
{
	//public fields and methods
	public:
		//constructor
		UserFnCall(const Symbol* newSym, const ASTNode* newLeft);

		//destructor
		~UserFnCall();

		//copy constructor
		UserFnCall(const UserFnCall& ufc);

		//move constructor
		UserFnCall(UserFnCall&& ufc);

		//assignment operator
		UserFnCall& operator=(const UserFnCall& src);

		//move operator
		UserFnCall& operator=(UserFnCall&& src);

		//getter method
		const Symbol* getSymbol() const; //returns the function call's symbol, which contains the call's function data
	
	//private fields and methods
	private:
		//field
		Symbol* sym; //the call's symbol, which holds the function data for the call
};

#endif
