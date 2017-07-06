/*
 * DieEqnAST.cpp
 * Implements a class that represents an AST node for die equations
 * Created by Andrew Davis
 * Created on 6/26/2017
 * Open source (GPL license)
 */

//include header
#include "DieEqnAST.h"

//constructor
DieEqnAST::DieEqnAST(EnumEqnAST newType, const std::string& newValue, DieEqnAST* newLeft, DieEqnAST* newRight)
	: type(newType), value(newValue), left(newLeft), right(newRight)
{
	//no code needed
}

//destructor
DieEqnAST::~DieEqnAST() {
	this->free(); //deallocate the object
}

//copy constructor
DieEqnAST::DieEqnAST(const DieEqnAST& dea)
	: type(dea.type), value(dea.value), left(dea.left), right(dea.right)
{
	//no code needed
}

//move constructor
DieEqnAST::DieEqnAST(DieEqnAST&& dea)
	: type(dea.type), value(dea.value), left(dea.left), right(dea.right)
{
	dea.free(); //deallocate the temporary
}

//assignment operator
DieEqnAST& DieEqnAST::operator=(const DieEqnAST& src) {
	this->type = src.type; //assign the type field
	this->value = src.value; //assign the value field
	this->free(); //prepare to assign the branch pointers
	this->left = src.left; //assign the left branch
	this->right = src.right; //assign the right branch
	return *this; //and return the object
}

//move operator
DieEqnAST& DieEqnAST::operator=(DieEqnAST&& src) {
	this->type = src.type; //move the type field
	this->value = src.value; //move the value field
	this->free(); //prepare to move the branch pointers
	this->left = src.left; //move the left branch
	this->right = src.right; //move the right branch
	src.free(); //deallocate the temporary
	return *this; //and return the object
}

//getter methods

//getType method - returns the type of the AST node
EnumEqnAST DieEqnAST::getType() const {
	return this->type; //return the type field
}

//stringValue method - returns the value of the AST node as a string
const std::string& DieEqnAST::stringValue() const {
	return this->value; //return the value field
}

//getLeft method - returns the left branch of the AST
const DieEqnAST* DieEqnAST::getLeft() const {
	return this->left; //return the left branch field
}

//getRight method - returns the right branch of the AST
const DieEqnAST* DieEqnAST::getRight() const {
	return this->right; //return the right branch field
}

//protected free method - deallocates the object
void DieEqnAST::free() {
	delete this->left; //deallocate the left branch
	this->left = nullptr; //and zero it out
	delete this->right; //deallocate the right branch
	this->right = nullptr; //and zero it out
}

//end of implementation
