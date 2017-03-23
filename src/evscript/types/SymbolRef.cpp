/*
 * SymbolRef.cpp
 * Implements a class that holds an AST node that references a symbol
 * Created by Andrew Davis
 * Created on 3/23/2017
 * Open source (GPL license)
 */

//include header
#include "SymbolRef.h"

//constructor
SymbolRef::SymbolRef(Symbol* newSym)
	: ASTNode(EnumNodeType::REF, nullptr, nullptr), sym(newSym) //call superclass constructor and init the symbol pointer
{
	//no code needed
}

//destructor
SymbolRef::~SymbolRef() {
	//no code needed
}

//copy constructor
SymbolRef::SymbolRef(const SymbolRef& sr)
	: ASTNode(sr), sym(sr.sym) //call superclass copy constructor and copy the symbol pointer
{
	//no code needed
}

//move constructor
SymbolRef::SymbolRef(SymbolRef&& sr)
	: ASTNode(sr), sym(sr.sym) //call superclass move constructor and move the symbol pointer
{
	//no code needed
}

//assignment operator
SymbolRef& SymbolRef::operator=(const SymbolRef& src) {
	ASTNode::operator=(src); //call superclass assignment operator
	this->sym = src.sym; //assign the symbol pointer
	return *this; //return the object
}

//move operator
SymbolRef& SymbolRef::operator=(SymbolRef&& src) {
	ASTNode::operator=(src); //call superclass move operator
	this->sym = src.sym; //move the symbol pointer
	return *this; //return the object
}

//getter method

//getSymbol method - returns the symbol pointer of the SymbolRef
const Symbol* SymbolRef::getSymbol() const {
	return this->sym; //return the symbol pointer
}

//end of implementation
