/*
 * SymbolList.cpp
 * Implements a class that acts as a linked list that holds Symbol objects
 * Created by Andrew Davis
 * Created on 3/23/2017
 * Open source (GPL license)
 */

//include header
#include "SymbolList.h"

//constructor
SymbolList::SymbolList(Symbol* newSym, const SymbolList* newNext)
	: sym(newSym), next(nullptr) //init the fields
{
	if(newNext != nullptr) { //if the next pointer isn't null
		this->next = new SymbolList(*newNext); //then copy it in
	}
}

//destructor
SymbolList::~SymbolList() {
	this->free(); //deallocate the list
}

//copy constructor
SymbolList::SymbolList(const SymbolList& sl)
	: sym(sl.sym), next(nullptr) //copy the fields
{
	if(sl.next != nullptr) { //if the next pointer isn't null
		this->next = new SymbolList(*sl.next); //then copy it in
	}
}

//move constructor
SymbolList::SymbolList(SymbolList&& sl)
	: sym(sl.sym), next(nullptr) //move the fields
{
	if(sl.next != nullptr) { //if the next pointer isn't null
		this->next = new SymbolList(*sl.next); //then move it in
	}
	sl.free(); //deallocate the temporary
}

//assignment operator
SymbolList& SymbolList::operator=(const SymbolList& src) {
	this->sym = src.sym; //assign the symbol pointer
	if(this->next != nullptr && src.next != nullptr) { //if there is a valid next pointer
		*this->next = *src.next; //assign the next pointer
	}
	return *this; //return the object
}

//move operator
SymbolList& SymbolList::operator=(SymbolList&& src) {
	this->sym = src.sym; //move the symbol pointer
	if(this->next != nullptr && src.next != nullptr) { //if there is a valid next pointer
		*this->next = *src.next; //move the next pointer
	}
	src.free(); //deallocate the temporary
	return *this; //return the object
}

//getter method

//getSymbol method - returns the symbol pointer for the current node
Symbol* SymbolList::getSymbol() const {
	return this->sym; //return the symbol pointer
}

//list method

//nextNode method - returns the next node in the list
SymbolList*& SymbolList::nextNode() {
	return this->next; //return the next node pointer
}

//private method

//free method - deallocates the list
void SymbolList::free() {
	delete this->next; //deallocate the next pointer
	this->next = nullptr; //and zero it out
}

//end of implementation
