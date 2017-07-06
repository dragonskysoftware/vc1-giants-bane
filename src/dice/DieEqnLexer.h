/*
 * DieEqnLexer.h
 * Declares a class that lexes die equations
 * Created by Andrew Davis
 * Created on 6/27/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef DIE_EQN_LEX_H
#define DIE_EQN_LEX_H

//includes
#include <string>
#include "DieEqnToken.h"
#include "EnumEqnToken.h"
#include "../except/DieEqnLexerException.h"
#include "../util/func.h"

//class declaration
class DieEqnLexer final {
	//public fields and methods
	public:
		//constructor
		explicit DieEqnLexer(const std::string& newText);

		//destructor
		~DieEqnLexer();

		//copy constructor
		DieEqnLexer(const DieEqnLexer& del);

		//move constructor
		DieEqnLexer(DieEqnLexer&& del);

		//assignment operator
		DieEqnLexer& operator=(const DieEqnLexer& src);

		//move operator
		DieEqnLexer& operator=(DieEqnLexer&& src);

		//other methods

		//returns the next token from the input
		DieEqnToken getNextToken();

	//private fields and methods
	private:
		//methods
		void error(); //throws an error
		void advance(); //advances the lexer's position
		void skipWhiteSpace(); //skips whitespace in the equation
		std::string number(); //returns a multidigit string number

		//fields
		std::string text; //the text to lex
		int pos; //the processing position in the text
		char currentChar; //the current character being processed

};

#endif
