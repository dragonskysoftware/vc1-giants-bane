/*
 * DieEqnParser.h
 * Declares a class that parses die equations
 * Created by Andrew Davis
 * Created on 6/29/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef DIE_EQN_PARSE_H
#define DIE_EQN_PARSE_H

//includes
#include "DieEqnAST.h"
#include "DieEqnNum.h"
#include "DieEqnOp.h"
#include "DieEqnToken.h"
#include "DieEqnLexer.h"
#include "EnumEqnToken.h"
#include "EnumEqnOps.h"
#include "../except/DieEqnParserException.h"

//class declaration
class DieEqnParser final {
	//public fields and methods
	public:
		//constructor
		explicit DieEqnParser(const DieEqnLexer& newLexer);

		//destructor
		~DieEqnParser();

		//copy constructor
		DieEqnParser(const DieEqnParser& dep);

		//move constructor
		DieEqnParser(DieEqnParser&& dep);

		//assignment operator
		DieEqnParser& operator=(const DieEqnParser& src);

		//move operator
		DieEqnParser& operator=(DieEqnParser&& src);

		//other method
		DieEqnAST* parse(); //parses a die equation

	//private fields and methods
	private:
		//methods
		void error(); //throws an exception
		void eat(EnumEqnToken tokenType); //gets the next token
		DieEqnAST* emitNumeral(); //emits the AST for a number
		DieEqnAST* emitRoll(); //emits the AST for a roll
		DieEqnAST* emitEqn(); //emits the AST for an equation

		//fields
		DieEqnLexer lexer; //the lexer for the die equation
		DieEqnToken currentToken; //the current token being parsed
		
};


#endif
