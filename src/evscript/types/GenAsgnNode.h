/*
 * GenAsgnNode.h
 * Declares a class that represents an AST node that marks a generalized variable assignment
 * Created by Andrew Davis
 * Created on 3/24/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef GEN_ASGN_H
#define GEN_ASGN_H

//includes
#include "ASTNode.h"
#include "EnumNodeType.h"
#include "EnumAsgnType.h"

//class declaration
class GenAsgnNode : public ASTNode
{
	//public fields and methods
	public:
		//constructor
		explicit GenAsgnNode(EnumAsgnType newAssignType);

		//destructor
		virtual ~GenAsgnNode();

		//copy constructor
		GenAsgnNode(const GenAsgnNode& gan);

		//move constructor
		GenAsgnNode(GenAsgnNode&& gan);

		//assignment operator
		GenAsgnNode& operator=(const GenAsgnNode& src);

		//move operator
		GenAsgnNode& operator=(GenAsgnNode&& src);

		//getter method
		EnumAsgnType getAssignType() const; //returns the type of assignment node this is

	//protected fields and methods
	protected:
		//field
		EnumAsgnType assignmentType; //the type of assignment node this represents
};

#endif
