/*
 * AITVAsgnNode.h
 * Declares a class that represents an AST node that marks an array-dereference-to-array-dereference variable assignment
 * Created by Andrew Davis
 * Created on 3/24/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef AITVA_ASGN_H
#define AITVA_ASGN_H

//includes
#include "ArrayRef.h"
#include "ASTNode.h"
#include "GenAsgnNode.h"
#include "EnumNodeType.h"
#include "EnumAsgnType.h"
#include "../../except/InvalidStateException.h"

//class declaration
class AITVAsgnNode final : public GenAsgnNode
{
	//public fields and methods
	public:
		//constructor
		AITVAsgnNode(const ArrayRef* newLval, const ASTNode* newRval);

		//destructor
		~AITVAsgnNode();

		//copy constructor
		AITVAsgnNode(const AITVAsgnNode& aan);

		//move constructor
		AITVAsgnNode(AITVAsgnNode&& aan);

		//assignment operator
		AITVAsgnNode& operator=(const AITVAsgnNode& src);

		//move operator
		AITVAsgnNode& operator=(AITVAsgnNode&& src);

		//getter methods
		ArrayRef* lval(); //gets or sets the lval array reference for the node 
		ASTNode* getRval(); //returns the rval for the node
	
	//private fields and methods
	private:
		//private method
		void free(); //deallocates the node

		//fields
		ArrayRef* lvalRef; //the ArrayRef to be assigned to
		ASTNode* rval; //used to obtain the value to be assigned to the lval ArrayRef
};

#endif
