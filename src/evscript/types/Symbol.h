/*
 * Symbol.h
 * Declares a class that represents a symbol in EvScript
 * Created by Andrew Davis
 * Created on 3/16/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef SYMBOL_H_INC
#define SYMBOL_H_INC

//includes
#include "ASTNode.h"
#include "Variant.h"
#include "Array.h"
#include "SymbolList.h"
#include <string>

//class declaration
class Symbol final {
	//public fields and methods
	public:
		//default constructor - initializes every field to empty
		Symbol();

		//constructor 1 - constructs from a name and a value
		Symbol(const char* newName, const Variant& newValue);

		//constructor 2 - constructs from a name and an array
		Symbol(const char* newName, const Array& newArray);

		//constructor 3 - constructs from a name and a function dataset
		Symbol(const char* newName, const ASTNode* newFunction, const SymbolList* newArgs);

		//destructor
		~Symbol();

		//copy constructor
		Symbol(const Symbol& s);

		//move constructor
		Symbol(Symbol&& s);

		//assignment operator
		Symbol& operator=(const Symbol& src);

		//move operator
		Symbol& operator=(Symbol&& src);

		//property methods
		std::string& name(); //returns a reference to the name of the Symbol
		Variant& value(); //returns a reference to the value of the Symbol
		Array& array(); //returns a reference to the array for the Symbol
		ASTNode*& function(); //returns a pointer to the function AST for the Symbol
		SymbolList*& functionArgs(); //returns a pointer to the Symbol's function arguments

	//private fields and methods
	private:
		//fields
		std::string name_; //the name of the Symbol
		Variant value_; //the value of the Symbol
		Array array_; //the array for the Symbol
		ASTNode* function_; //the function code embedded in the Symbol
		SymbolList* args_; //the arguments to the Symbol's function
		
};

#endif
