/*
 * ArrayRef.cpp
 * Implements a class that represents an array reference AST node
 * Created by Andrew Davis
 * Created on 3/23/2017
 * Open source (GPL license)
 */

//include header
#include "ArrayRef.h"

//constructor
ArrayRef::ArrayRef(Symbol* newSym, const ASTNode* newIndex)
	: ASTNode(EnumNodeType::ARRAY, nullptr, nullptr), sym(newSym), indexNode(nullptr) //call superclass constructor
{
	if(newSym == nullptr) { //if the supplied symbol pointer is null
		throw InvalidStateException("Symbol pointer is null in ArrayRef constructor"); //then throw an exception
	}
	if(newIndex == nullptr) { //if the supplied AST pointer is null
		throw InvalidStateException("AST pointer is null in ArrayRef constructor"); //then throw an exception
	}
	this->indexNode = new ASTNode(*newIndex); //init the AST pointer
}

//destructor
ArrayRef::~ArrayRef() {
	this->free(); //deallocate the object
}

//copy constructor
ArrayRef::ArrayRef(const ArrayRef& ar)
	: ASTNode(ar), sym(ar.sym), indexNode(nullptr) //call superclass copy constructor and zero the fields
{
	this->indexNode = new ASTNode(*ar.indexNode); //copy the AST pointer
}

//move constructor
ArrayRef::ArrayRef(ArrayRef&& ar)
	: ASTNode(ar), sym(ar.sym), indexNode(nullptr) //call superclass move constructor and zero the fields
{
	this->indexNode = new ASTNode(*ar.indexNode); //move the AST pointer
	ar.free(); //deallocate the temporary
}

//assignment operator
ArrayRef& ArrayRef::operator=(const ArrayRef& src) {
	ASTNode::operator=(src); //call superclass assignment operator
	this->sym = src.sym; //assign the symbol
	*this->indexNode = *src.indexNode; //assign the index node
	return *this; //return the object
}

//move operator
ArrayRef& ArrayRef::operator=(ArrayRef&& src) {
	ASTNode::operator=(src); //call superclass move operator
	this->sym = src.sym; //move the symbol
	*this->indexNode = *src.indexNode; //move the index node
	src.free(); //deallocate the temporary
	return *this; //return the object
}

//getter methods

//array method - gets and sets the array field of the symbol pointer
Array& ArrayRef::array() {
	return this->sym->array(); //return a call to the array method of the symbol pointer
}

//getIndexNode method - returns the AST node used to calculate the reference index of the ArrayRef
const ASTNode* ArrayRef::getIndexNode() const {
	return this->indexNode; //return the index AST node
}

//private method

//free method - deallocates the ArrayRef
void ArrayRef::free() {
	delete this->indexNode; //deallocate the index node
	this->indexNode = nullptr; //and zero it out
}

//end of implementation
