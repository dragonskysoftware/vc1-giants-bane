/*
 * DieRoll.cpp
 * Implements a class that represents a roll of some dice
 * Created by Andrew Davis
 * Created on 6/29/2017
 * Open source (GPL license)
 */

//include header
#include "DieRoll.h"

//constructor 1 - constructs from a std::string
DieRoll::DieRoll(const std::string& newEquation)
	: DieRoll(newEquation.c_str()) //call the second constructor
{
	//no code needed
}

//constructor 2 - constructs from a C string
DieRoll::DieRoll(const char* newEquation)
	: equation(newEquation) //init the field
{
	//no code needed
}

//constructor 3 - constructs from a die equation object
DieRoll::DieRoll(const DieEquation& newEquation)
	: equation(newEquation) //init the field
{
	//no code needed
}

//destructor
DieRoll::~DieRoll() {
	//no code needed
}

//copy constructor
DieRoll::DieRoll(const DieRoll& dr)
	: equation(dr.equation) //copy the field
{
	//no code needed
}

//move constructor
DieRoll::DieRoll(DieRoll&& dr)
	: equation(dr.equation) //move the field
{
	//no code needed
}

//assignment operator
DieRoll& DieRoll::operator=(const DieRoll& src) {
	this->equation = src.equation; //assign the equation
	return *this; //and return the object
}

//move operator
DieRoll& DieRoll::operator=(DieRoll&& src) {
	this->equation = src.equation; //move the equation
	return *this; //and return the object
}

//roll method - executes the die roll and returns the result
int DieRoll::roll() const {
	DieEqnLexer lex(this->equation.getData()); //get a lexer
	DieEqnParser parse(lex); //get a parser
	DieEqnInterpreter interp(parse); //get an interpreter
	return interp.interpret(); //return the interpreted die equation
}

//end of implementation
