/*
 * AITIAAsgnNode.h
 * Declares a class that represents an AST node that marks an array-dereference-to-array-dereference variable assignment
 * Created by Andrew Davis
 * Created on 3/24/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef AITIA_ASGN_H
#define AITIA_ASGN_H

//includes
#include "ArrayRef.h"
#include "GenAsgnNode.h"
#include "EnumNodeType.h"
#include "EnumAsgnType.h"
#include "../../except/InvalidStateException.h"

//class declaration
class AITIAAsgnNode final : public GenAsgnNode
{
	//public fields and methods
	public:
		//constructor
		AITIAAsgnNode(const ArrayRef* newLval, const ArrayRef* newRval);

		//destructor
		~AITIAAsgnNode();

		//copy constructor
		AITIAAsgnNode(const AITIAAsgnNode& aan);

		//move constructor
		AITIAAsgnNode(AITIAAsgnNode&& aan);

		//assignment operator
		AITIAAsgnNode& operator=(const AITIAAsgnNode& src);

		//move operator
		AITIAAsgnNode& operator=(AITIAAsgnNode&& src);

		//getter methods
		ArrayRef* lval(); //gets or sets the lval array reference for the node 
		const ArrayRef* getRval() const; //returns the rval array reference for the node
	
	//private fields and methods
	private:
		//private method
		void free(); //deallocates the node

		//fields
		ArrayRef* lvalRef; //the ArrayRef to be assigned to
		ArrayRef* rvalRef; //used to obtain the value to be assigned to the lval ArrayRef
};

#endif
