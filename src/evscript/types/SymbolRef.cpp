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
SymbolRef::SymbolRef(const Symbol* newSym)
	: ASTNode(EnumNodeType::REF, nullptr, nullptr), sym(nullptr) //call superclass constructor and zero the symbol pointer
{
	if(newSym == nullptr) { //if the supplied symbol is null
		throw InvalidStateException("Symbol pointer is null in SymbolRef constructor"); //then throw an exception
	}
	this->sym = new Symbol(*newSym); //init the symbol pointer
}

//destructor
SymbolRef::~SymbolRef() {
	this->free(); //deallocate the symbol pointer
}

//copy constructor
SymbolRef::SymbolRef(const SymbolRef& sr)
	: ASTNode(sr), sym(nullptr) //call superclass copy constructor and zero the symbol pointer
{
	this->sym = new Symbol(*sr.sym); //copy the symbol pointer
}

//move constructor
SymbolRef::SymbolRef(SymbolRef&& sr)
	: ASTNode(sr), sym(nullptr) //call superclass move constructor and zero the symbol pointer
{
	this->sym = new Symbol(*sr.sym); //move the symbol pointer
	sr.free(); //deallocate the temporary object
}

//assignment operator
SymbolRef& SymbolRef::operator=(const SymbolRef& src) {
	ASTNode::operator=(src); //call superclass assignment operator
	*this->sym = *src.sym; //assign the symbol pointer
	return *this; //return the object
}

//move operator
SymbolRef& SymbolRef::operator=(SymbolRef&& src) {
	ASTNode::operator=(src); //call superclass move operator
	*this->sym = *src.sym; //move the symbol pointer
	src.free(); //deallocate the temporary object
	return *this; //return the object
}

//getter method

//getSymbol method - returns the symbol pointer of the SymbolRef
const Symbol* SymbolRef::getSymbol() const {
	return this->sym; //return the symbol pointer
}

//private method

//free method - deallocates the SymbolRef
void SymbolRef::free() {
	delete this->sym; //deallocate the symbol pointer
	this->sym = nullptr; //and zero it out
}

//end of implementation
