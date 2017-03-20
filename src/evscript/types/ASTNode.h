/*
 * ASTNode.h
 * Declares a class that represents an Abstract Syntax Tree node
 * Created by Andrew Davis
 * Created on 3/16/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef AST_NODE_H
#define AST_NODE_H

//include
#include "EnumNodeType.h"

//class declaration
class ASTNode {
	//public fields and methods
	public:
		//constructor
		ASTNode(EnumNodeType newType, const ASTNode* newLeft, const ASTNode* newRight);

		//destructor
		virtual ~ASTNode();

		//copy constructor
		ASTNode(const ASTNode& ast);

		//move constructor
		ASTNode(ASTNode&& ast);

		//assignment operator
		ASTNode& operator=(const ASTNode& src);

		//move operator
		ASTNode& operator=(ASTNode&& src);

		//getter methods
		EnumNodeType getNodeType() const; //returns the node type of the ASTNode
		const ASTNode* getLeftBranch() const; //returns the left branch of the ASTNode
		const ASTNode* getRightBranch() const; //returns the right branch of the ASTNode
	
	//protected fields and methods
	protected:
		EnumNodeType nodeType; //the type of the ASTNode
		ASTNode* left; //the left branch of the continuing AST
		ASTNode* right; //the right branch of the continuing AST
};

#endif
