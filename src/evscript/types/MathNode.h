/*
 * MathNode.h
 * Declares a class that represents an AST node that marks a math operation
 * Created by Andrew Davis
 * Created on 3/21/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef MATH_NODE_H
#define MATH_NODE_H

//includes
#include "ASTNode.h"
#include "EnumNodeType.h"
#include "EnumMathOps.h"

//class declaration
class MathNode final : public ASTNode
{
	//public fields and methods
	public:
		//constructor
		MathNode(EnumMathOps newOp, const ASTNode* newLeft, const ASTNode* newRight);

		//destructor
		~MathNode();

		//copy constructor
		MathNode(const MathNode& mn);

		//move constructor
		MathNode(MathNode&& mn);

		//assignment operator
		MathNode& operator=(const MathNode& src);

		//move operator
		MathNode& operator=(MathNode&& src);

		//getter method
		EnumMathOps getOperation() const; //returns the operation of the MathNode

	//private fields and methods
	private:
		EnumMathOps operation; //the operation for the MathNode
};

#endif
