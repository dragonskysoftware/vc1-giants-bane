/*
 * VTVAsgnNode.h
 * Declares a class that represents an AST node that marks a value-to-value variable assignment
 * Created by Andrew Davis
 * Created on 3/24/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef VTV_ASGN_H
#define VTV_ASGN_H

//includes
#include "ASTNode.h"
#include "GenAsgnNode.h"
#include "EnumNodeType.h"
#include "EnumAsgnType.h"
#include "Symbol.h"
#include "../../except/InvalidStateException.h"

//class declaration
class VTVAsgnNode final : public GenAsgnNode
{
	//public fields and methods
	public:
		//constructor
		VTVAsgnNode(Symbol* newSym, const ASTNode* newVal);

		//destructor
		~VTVAsgnNode();

		//copy constructor
		VTVAsgnNode(const VTVAsgnNode& van);

		//move constructor
		VTVAsgnNode(VTVAsgnNode&& van);

		//assignment operator
		VTVAsgnNode& operator=(const VTVAsgnNode& src);

		//move operator
		VTVAsgnNode& operator=(VTVAsgnNode&& src);

		//getter methods
		Symbol* symbol(); //gets or sets the node's symbol
		const ASTNode* getValueNode() const; //returns the node's value
	
	//private fields and methods
	private:
		//private method
		void free(); //deallocates the node

		//fields
		Symbol* sym; //the symbol to be assigned to
		ASTNode* valueNode; //evaluates to the value to be assigned to the symbol
};

#endif
