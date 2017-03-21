/*
 * CompNode.h
 * Declares a class that represents an AST node that marks a logical comparison
 * Created by Andrew Davis
 * Created on 3/21/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef COMP_NODE_H
#define COMP_NODE_H

//includes
#include "ASTNode.h"
#include "EnumNodeType.h"
#include "EnumCompType.h"

//class declaration
class CompNode final : public ASTNode
{
	//public fields and methods
	public:
		//constructor
		CompNode(EnumCompType newCompType, const ASTNode* newLeft, const ASTNode* newRight);

		//destructor
		~CompNode();

		//copy constructor
		CompNode(const CompNode& cn);

		//move constructor
		CompNode(CompNode&& cn);

		//assignment operator
		CompNode& operator=(const CompNode& src);

		//move operator
		CompNode& operator=(CompNode&& src);

		//getter method
		EnumCompType getComparisonType() const; //returns the type of comparison this CompNode represents

	//private fields and methods
	private:
		EnumCompType comparisonType; //the comparison type for this CompNode
};

#endif
