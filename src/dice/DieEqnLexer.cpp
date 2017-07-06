/*
 * DieEqnLexer.cpp
 * Implements a class that lexes die equations
 * Created by Andrew Davis
 * Created on 6/27/2017
 * Open source (GPL license)
 */

//include header
#include "DieEqnLexer.h"

//constructor
DieEqnLexer::DieEqnLexer(const std::string& newText)
	: text(newText), pos(0), currentChar('x') //init the fields
{
	this->currentChar = this->text[this->pos]; //init the current char
}

//destructor
DieEqnLexer::~DieEqnLexer() {
	//no code needed
}

//copy constructor
DieEqnLexer::DieEqnLexer(const DieEqnLexer& del)
	: text(del.text), pos(del.pos), currentChar(del.currentChar)
{
	//no code needed
}

//move constructor
DieEqnLexer::DieEqnLexer(DieEqnLexer&& del)
	: text(del.text), pos(del.pos), currentChar(del.currentChar)
{
	//no code needed
}

//assignment operator
DieEqnLexer& DieEqnLexer::operator=(const DieEqnLexer& src) {
	this->text = src.text; //assign the text field
	this->pos = src.pos; //assign the position field
	this->currentChar = src.currentChar; //assign the current char
	return *this; //and return the object
}

//move operator
DieEqnLexer& DieEqnLexer::operator=(DieEqnLexer&& src) {
	this->text = src.text; //move the text field
	this->pos = src.pos; //move the position field
	this->currentChar = src.currentChar; //move the current char
	return *this; //and return the object
}

//other methods

//getNextToken method - returns the next token from the input
DieEqnToken DieEqnLexer::getNextToken() {
	//loop while the current character isn't null
	while(this->currentChar != '\0') {
		//check for a space
		if(isSpace(this->currentChar)) { //if a space was found
			this->skipWhiteSpace(); //then skip the spaces
			continue;
		}

		//check for a number
		if(isDigit(this->currentChar)) { //if a number was found
			//return the proper token
			return DieEqnToken(EnumEqnToken::NUM, this->number());
		}

		//check for a die operator
		if(this->currentChar == 'd' || this->currentChar == 'D') {
			//advance the lexer
			this->advance();
			//return the proper token
			return DieEqnToken(EnumEqnToken::D, "d");
		}

		//check for an addition operator
		if(this->currentChar == '+') { //if a plus sign was found
			//advance the lexer
			this->advance();
			//return the proper token
			return DieEqnToken(EnumEqnToken::PLUS, "+");
		}

		//check for a subtraction operator
		if(this->currentChar == '-') { //if a minus sign was found
			//advance the lexer
			this->advance();
			//return the proper token
			return DieEqnToken(EnumEqnToken::MINUS, "+");
		}

		this->error(); //no match, so throw an error
	}

	return DieEqnToken(EnumEqnToken::EOL, ""); //return an EOL token
}

//private error method - throws an exception
void DieEqnLexer::error() {
	throw DieEqnLexerException(this->text); //throw an error
}

//private advance method - advances the lexer's position
void DieEqnLexer::advance() {
	this->pos++; //increment the position
	if(this->pos > this->text.length() - 1) { //end of text reached
		this->currentChar = '\0'; //null the current character
	} else {
		this->currentChar = this->text[this->pos]; //set the char
	}
}

//private skipWhiteSpace method - skips over whitespace
void DieEqnLexer::skipWhiteSpace() {
	//loop over spaces
	while((this->currentChar != '\0') && (isSpace(this->currentChar))) {
		this->advance(); //and advance the lexer
	}
}

//private number method - returns a multidigit string number
std::string DieEqnLexer::number() {
	std::string result; //the return value
	//loop over digits
	while((this->currentChar != '\0') && (isDigit(this->currentChar))) {
		result += this->currentChar; //append the current char
		this->advance(); //advance the lexer
	}
	return result; //return the number string
}

//end of implementation
