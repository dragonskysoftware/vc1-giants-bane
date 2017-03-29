/*
 * ATAAsgnNode.h
 * Declares a class that represents an AST node that marks a value-to-array-dereference variable assignment
 * Created by Andrew Davis
 * Created on 3/24/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef ATA_ASGN_H
#define ATA_ASGN_H

//includes
#include "ArrayRef.h"
#include "GenAsgnNode.h"
#include "EnumNodeType.h"
#include "EnumAsgnType.h"
#include "Symbol.h"
#include "../../except/InvalidStateException.h"

//class declaration
class ATAAsgnNode final : public GenAsgnNode
{
	//public fields and methods
	public:
		//constructor
		ATAAsgnNode(Symbol* newLval, Symbol* newRval);

		//destructor
		~ATAAsgnNode();

		//copy constructor
		ATAAsgnNode(const ATAAsgnNode& van);

		//move constructor
		ATAAsgnNode(ATAAsgnNode&& van);

		//assignment operator
		ATAAsgnNode& operator=(const ATAAsgnNode& src);

		//move operator
		ATAAsgnNode& operator=(ATAAsgnNode&& src);

		//getter methods
		Symbol*& lval(); //gets or sets the node's lval symbol
		Symbol* getRval(); //gets the node's rval symbol
	
	//private fields and methods
	private:
		//fields
		Symbol* lvalSym; //the symbol to be assigned to
		Symbol* rvalSym; //the symbol being assigned
};

#endif
