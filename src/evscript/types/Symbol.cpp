/*
 * Symbol.cpp
 * Implements a class that represents a symbol in EvScript
 * Created by Andrew Davis
 * Created on 3/16/2017
 * Open source (GPL license)
 */

//include header
#include "Symbol.h"

//default constructor - initializes every field to empty
Symbol::Symbol()
	: name_(), value_(), array_(), function_(nullptr), args_(nullptr) //empty the fields
{
	//no code needed
}

//constructor 1 - constructs from a name and a value
Symbol::Symbol(const char* newName, const Variant& newValue)
	: name_(newName), value_(newValue), array_(), function_(nullptr), args_(nullptr) //init the fields
{
	//no code needed
}

//constructor 2 - constructs from a name and an array
Symbol::Symbol(const char* newName, const Array& newArray)
	: name_(newName), value_(), array_(newArray), function_(nullptr), args_(nullptr) //init the fields
{
	//no code needed
}

//constructor 3 - constructs from a name and a function dataset
Symbol::Symbol(const char* newName, const ASTNode* newFunction, const SymbolList* newArgs)
	: name_(newName), value_(), array_(), function_(nullptr), args_(nullptr) //init the fields
{
	if(newFunction != nullptr) { //if the new function is valid
		this->function_ = new ASTNode(*newFunction); //then init this function field
	}
	if(newArgs != nullptr) { //if the arguments are valid
		this->args_ = new SymbolList(*newArgs); //then init this args field
	}
}

//destructor
Symbol::~Symbol() {
	//clean up the object
	delete this->function_; //deallocate the function
	this->function_ = nullptr; //and zero it out
	delete this->args_; //deallocate the arguments
	this->args_ = nullptr; //and zero them out
}

//copy constructor
Symbol::Symbol(const Symbol& s)
	: name_(s.name_), value_(s.value_), array_(s.array_), function_(nullptr), args_(nullptr) //copy the fields
{
	if(s.function_ != nullptr) { //if the other function is valid
		this->function_ = new ASTNode(*s.function_); //then copy it into this function
	}
	if(s.args_ != nullptr) { //if the other args are valid
		this->args_ = new SymbolList(*s.args_); //then copy them into this args
	}

}

//move constructor
Symbol::Symbol(Symbol&& s)
	: name_(s.name_), value_(s.value_), array_(s.array_), function_(nullptr), args_(s.args_) //copy the fields
{
	if(s.function_ != nullptr) { //if the other function is valid
		this->function_ = new ASTNode(*s.function_); //then copy it into this function
	}
	if(s.args_ != nullptr) { //if the other args are valid
		this->args_ = new SymbolList(*s.args_); //then move them into this args
	}

	delete s.function_; //deallocate the temporary's function
	s.function_ = nullptr; //and zero it out
	delete s.args_; //deallocate the temporary's args
	s.args_ = nullptr; //and zero them out
}

//assignment operator
Symbol& Symbol::operator=(const Symbol& src) {
	this->name_ = src.name_; //assign the name
	this->value_ = src.value_; //assign the value
	this->array_ = src.array_; //assign the array
	if(src.function_ != nullptr) { //if the other function isn't null
		*this->function_ = *src.function_; //then assign the function
	} else { //if it is null
		delete this->function_; //deallocate this function
		this->function_ = nullptr; //and zero it out
	}
	if(src.args_ != nullptr) { //if the other args aren't null
		*this->args_ = *src.args_; //then assign the args
	} else { //if it is null
		delete this->args_; //deallocate this args
		this->args_ = nullptr; //and zero them out
	}
	return *this; //return the object
}

//move operator
Symbol& Symbol::operator=(Symbol&& src) {
	this->name_ = src.name_; //move the name
	this->value_ = src.value_; //move the value
	this->array_ = src.array_; //move the array
	this->args_ = src.args_; //move the function args
	if(src.function_ != nullptr) { //if the other function isn't null
		*this->function_ = *src.function_; //then move the function
	} else { //if it is null
		delete this->function_; //deallocate this function
		this->function_ = nullptr; //and zero it out
	}
	if(src.args_ != nullptr) { //if the other args aren't null
		*this->args_ = *src.args_; //then move the args
	} else { //if it is null
		delete this->args_; //deallocate this args
		this->args_ = nullptr; //and zero them out
	}
	delete src.function_; //deallocate the temporary's function
	src.function_ = nullptr; //and zero it out
	delete src.args_; //deallocate the temporary's args
	src.args_ = nullptr; //and zero them out
	return *this; //return the object
}

//property methods

//name method - returns a reference to the name_ field
std::string& Symbol::name() {
	return this->name_; //return the name_ field
}

//value method - returns a reference to the value_ field
Variant& Symbol::value() {
	return this->value_; //return the value_ field
}

//array method - returns a reference to the array_ field
Array& Symbol::array() {
	return this->array_; //return the array_ field
}

//function method - returns a pointer to the function_ field
ASTNode*& Symbol::function() {
	return this->function_; //return the function_ field
}

//functionArgs method - returns a pointer to the args_ field
SymbolList*& Symbol::functionArgs() {
	return this->args_; //return the args_ field
}

//end of implementation
