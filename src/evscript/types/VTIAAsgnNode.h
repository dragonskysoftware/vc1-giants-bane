/*
 * VTIAAsgnNode.h
 * Declares a class that represents an AST node that marks a value-to-array-dereference variable assignment
 * Created by Andrew Davis
 * Created on 3/24/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef VTIA_ASGN_H
#define VTIA_ASGN_H

//includes
#include "ArrayRef.h"
#include "GenAsgnNode.h"
#include "EnumNodeType.h"
#include "EnumAsgnType.h"
#include "Symbol.h"
#include "../../except/InvalidStateException.h"

//class declaration
class VTIAAsgnNode final : public GenAsgnNode
{
	//public fields and methods
	public:
		//constructor
		VTIAAsgnNode(Symbol* newSym, const ArrayRef* newRef);

		//destructor
		~VTIAAsgnNode();

		//copy constructor
		VTIAAsgnNode(const VTIAAsgnNode& van);

		//move constructor
		VTIAAsgnNode(VTIAAsgnNode&& van);

		//assignment operator
		VTIAAsgnNode& operator=(const VTIAAsgnNode& src);

		//move operator
		VTIAAsgnNode& operator=(VTIAAsgnNode&& src);

		//getter methods
		Symbol*& symbol(); //gets or sets the node's symbol
		ArrayRef* getArrayRef(); //returns the array reference for the node
	
	//private fields and methods
	private:
		//private method
		void free(); //deallocates the node

		//fields
		Symbol* sym; //the symbol to be assigned to
		ArrayRef* ref; //used to obtain the value to be assigned to the symbol
};

#endif
