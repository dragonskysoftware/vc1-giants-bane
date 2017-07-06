/*
 * DieEqnParser.cpp
 * Implements a class that parses die equations
 * Created by Andrew Davis
 * Created on 6/29/2017
 * Open source (GPL license)
 */

//include header
#include "DieEqnParser.h"

//constructor
DieEqnParser::DieEqnParser(const DieEqnLexer& newLexer)
	: lexer(newLexer), currentToken(EnumEqnToken::EOL, "") 
{
	this->currentToken = this->lexer.getNextToken(); //init the token
}

//destructor
DieEqnParser::~DieEqnParser() {
	//no code needed
}

//copy constructor
DieEqnParser::DieEqnParser(const DieEqnParser& dep)
	: lexer(dep.lexer), currentToken(dep.currentToken) //copy fields
{
	//no code needed
}

//move constructor
DieEqnParser::DieEqnParser(DieEqnParser&& dep)
	: lexer(dep.lexer), currentToken(dep.currentToken) //move fields
{
	//no code needed
}

//assignment operator
DieEqnParser& DieEqnParser::operator=(const DieEqnParser& src) {
	this->lexer = src.lexer; //assign the lexer
	this->currentToken = src.currentToken; //assign the current token
	return *this; //return the object
}

//move operator
DieEqnParser& DieEqnParser::operator=(DieEqnParser&& src) {
	this->lexer = src.lexer; //move the lexer
	this->currentToken = src.currentToken; //move the current token
	return *this; //return the object
}

//parse method - parses a die equation
DieEqnAST* DieEqnParser::parse() {
	return this->emitEqn(); //return the AST for a top-level equation
}

//private error method - throws an exception
void DieEqnParser::error() {
	throw DieEqnParserException(this->currentToken.getValue());
}

//private eat method - verifies the current token and gets the next one
void DieEqnParser::eat(EnumEqnToken tokenType) {
	if(this->currentToken.getType() == tokenType) { //check the types
		//if they match, then get the next token
		this->currentToken = this->lexer.getNextToken();
	} else { //if they don't match
		this->error(); //then throw an exception
	}
}

//private emitNumeral method - emits the AST for a number
DieEqnAST* DieEqnParser::emitNumeral() {
	DieEqnToken token = this->currentToken; //copy the current token
	this->eat(EnumEqnToken::NUM); //process the number
	return new DieEqnNum(token.getValue()); //and return the AST node
}

//private emitRoll method - emits the AST for a roll
DieEqnAST* DieEqnParser::emitRoll() {
	DieEqnAST* node = this->emitNumeral(); //get the roll multiplier
	//if a die operator is detected
	if(this->currentToken.getType() == EnumEqnToken::D) {
		DieEqnToken token = this->currentToken;
		this->eat(EnumEqnToken::D); //process the operator
		node = new DieEqnOp(EnumEqnOps::DIE, token.getValue(), node, this->emitNumeral()); //create the AST
	}
	return node; //return the created AST node
}

//private emitEqn method - emits the AST for an equation
DieEqnAST* DieEqnParser::emitEqn() {
	DieEqnAST* node = this->emitRoll(); //get the roll
	while((this->currentToken.getType() == EnumEqnToken::PLUS) || (this->currentToken.getType() == EnumEqnToken::MINUS)) { //loop over the operator
		DieEqnToken token = this->currentToken;
		if(token.getType() == EnumEqnToken::PLUS) { //plus op
			this->eat(EnumEqnToken::PLUS); //process the plus
			node = new DieEqnOp(EnumEqnOps::ADD, token.getValue(), node, this->emitRoll()); //create the AST
		} else if(token.getType() == EnumEqnToken::MINUS) { //minus
			this->eat(EnumEqnToken::MINUS); //process the minus
			node = new DieEqnOp(EnumEqnOps::SUB, token.getValue(), node, this->emitRoll()); //create the AST
		}
	}
	return node; //return the created AST node
}

//end of implementation
