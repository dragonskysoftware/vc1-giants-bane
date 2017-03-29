/*
 * EVSContext.h
 * Declares a class that acts as a context for the EvScript interpreter
 * Created by Andrew Davis
 * Created on 3/25/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef EVS_CTX_H
#define EVS_CTX_H

//includes
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include "calls.h"
#include "types/evs_types.h"
#include "../util/constants.h"
#include "../except/InvalidASTException.h"
#include "../except/SymbolTableException.h"

//class declaration
class EVSContext final {
	//public fields and methods
	public:
		//constructor
		EVSContext();

		//destructor
		~EVSContext();

		//copy constructor
		EVSContext(const EVSContext& evsc);

		//move constructor
		EVSContext(EVSContext&& evsc);

		//assignment operator
		EVSContext& operator=(const EVSContext& src);

		//move operator
		EVSContext& operator=(EVSContext&& src);

		//setter methods
		void setAST(const ASTNode* newAST); //assigns the AST to be evaluated by the class

		//other methods
		Symbol* lookup(char* symName); //accesses the symbol table and either writes to it or reads from it
		void eval(); //evaluates the stored AST
		void defineFunc(Symbol*& name, SymbolList* syms, ASTNode* func); //defines a function
		void defineArray(Symbol*& name, ASTNode* size); //defines an array
		void defineArray(Symbol*& name, int size); //also defines an array

	//private fields and methods
	private:
		//private methods
		void free(); //deallocates the object
		unsigned symhash(char* symName); //hashes a symbol
		Variant eval(ASTNode* node); //actually does the evaluating of the stored AST
		Variant callBuiltIn(FnCall* func); //calls a built-in function
		Variant callGame(GameCall* call); //calls a game call
		Variant callUser(UserFnCall* ufunc); //calls a user-defined function

		//fields
		ASTNode* ast; //the AST that holds the parsed EvScript code
		Symbol* symtab; //the symbol table that holds all the symbols for a script

};

#endif
