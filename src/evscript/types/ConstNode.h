/*
 * ConstNode.h
 * Declares a class that represents an AST node that holds a constant value
 * Created by Andrew Davis
 * Created on 3/22/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef CONST_NODE_H
#define CONST_NODE_H

//includes
#include "Variant.h"
#include "ASTNode.h"
#include "EnumNodeType.h"

//class declaration
class ConstNode final : public ASTNode 
{
	//public fields and methods
	public:
		//constructor 1 - constructs from a const reference
		explicit ConstNode(const Variant& newValue);

		//constructor 2 - constructs from a pointer
		explicit ConstNode(const Variant* newValue);

		//destructor
		~ConstNode();

		//copy constructor
		ConstNode(const ConstNode& cn);

		//move constructor
		ConstNode(ConstNode&& cn);

		//assignment operator
		ConstNode& operator=(const ConstNode& src);

		//move operator
		ConstNode& operator=(ConstNode&& src);

		//getter method
		const Variant& getValue() const; //returns the value of the node

	//private fields and methods
	private:
		Variant value; //the value of the ConstNode
};

#endif
