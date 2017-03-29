/*
 * FlowNode.h
 * Declares a class that represents a control flow AST node
 * Created by Andrew Davis
 * Created on 3/21/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef FLOW_NODE_H
#define FLOW_NODE_H

//includes
#include "ASTNode.h"
#include "EnumNodeType.h"
#include "../../except/InvalidStateException.h"

//class declaration
class FlowNode final : public ASTNode
{
	//public fields and methods
	public:
		//constructor
		FlowNode(EnumNodeType newType, const ASTNode* newCond, const ASTNode* newThen, const ASTNode* newElse);

		//destructor
		~FlowNode();

		//copy constructor
		FlowNode(const FlowNode& fn);

		//move constructor
		FlowNode(FlowNode&& fn);

		//assignment operator
		FlowNode& operator=(const FlowNode& src);

		//move operator
		FlowNode& operator=(FlowNode&& src);

		//getter methods
		ASTNode* getCondition(); //returns the condition AST node
		ASTNode* getThenBranch(); //returns the "then branch" AST node
		ASTNode* getElseBranch(); //returns the "else branch" AST node

	//private fields and methods
	private:
		//private methods
		void free(); //deallocates the assets for the FlowNode
		//fields
		ASTNode* condition; //the condition AST node
		ASTNode* thenBranch; //the "then branch" AST node
		ASTNode* elseBranch; //the "else branch" AST node
};

#endif
