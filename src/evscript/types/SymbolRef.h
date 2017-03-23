/*
 * SymbolRef.h
 * Declares a class that holds an AST node that references a symbol
 * Created by Andrew Davis
 * Created on 3/23/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef SYM_REF_H
#define SYM_REF_H

//includes
#include "ASTNode.h"
#include "EnumNodeType.h"
#include "Symbol.h"
#include "../../except/InvalidStateException.h"

//class declaration
class SymbolRef final : public ASTNode
{
	//public fields and methods
	public:
		//constructor
		SymbolRef(const Symbol* newSym); 

		//destructor
		~SymbolRef();

		//copy constructor
		SymbolRef(const SymbolRef& sr);

		//move constructor
		SymbolRef(SymbolRef&& sr);

		//assignment operator
		SymbolRef& operator=(const SymbolRef& src);

		//move operator
		SymbolRef& operator=(SymbolRef&& src);

		//getter method
		const Symbol* getSymbol() const; //returns the symbol pointer

	//private fields and methods
	private:
		//private method
		void free(); //deallocates the SymbolRef

		//field
		Symbol* sym; //the internal symbol pointer
};

#endif
