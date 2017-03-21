/*
 * LogicNode.h
 * Declares a class that represents an AST node that marks a logical operation
 * Created by Andrew Davis
 * Created on 3/21/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef LOGIC_NODE_H
#define LOGIC_NODE_H

//includes
#include "ASTNode.h"
#include "EnumNodeType.h"
#include "EnumLogicOps.h"

//class declaration
class LogicNode final : public ASTNode
{
	//public fields and methods
	public:
		//constructor
		LogicNode(EnumLogicOps newOp, const ASTNode* newLeft, const ASTNode* newRight);

		//destructor
		~LogicNode();

		//copy constructor
		LogicNode(const LogicNode& ln);

		//move constructor
		LogicNode(LogicNode&& ln);

		//assignment operator
		LogicNode& operator=(const LogicNode& src);

		//move operator
		LogicNode& operator=(LogicNode&& src);

		//getter method
		EnumLogicOps getOperation() const; //returns the operation of the LogicNode

	//private fields and methods
	private:
		EnumLogicOps operation; //the operation for the LogicNode
};

#endif
