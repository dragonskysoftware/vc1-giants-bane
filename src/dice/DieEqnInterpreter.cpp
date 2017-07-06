/*
 * DieEqnInterpreter.cpp
 * Implements a class that interpretes die equations
 * Created by Andrew Davis
 * Created on 6/29/2017
 * Open source (GPL license)
 */

//include header
#include "DieEqnInterpreter.h"

//constructor
DieEqnInterpreter::DieEqnInterpreter(const DieEqnParser& newParser)
	: parser(newParser) //init the field
{
	//no code needed
}

//destructor
DieEqnInterpreter::~DieEqnInterpreter() {
	//no code needed
}

//copy constructor
DieEqnInterpreter::DieEqnInterpreter(const DieEqnInterpreter& dei)
	: parser(dei.parser) //copy the field
{
	//no code needed
}

//move constructor
DieEqnInterpreter::DieEqnInterpreter(DieEqnInterpreter&& dei)
	: parser(dei.parser) //move the field
{
	//no code needed
}

//assignment operator
DieEqnInterpreter& DieEqnInterpreter::operator=(const DieEqnInterpreter& src) {
	this->parser = src.parser; //assign the parser field
	return *this; //and return the object
}

//move operator
DieEqnInterpreter& DieEqnInterpreter::operator=(DieEqnInterpreter&& src) {
	this->parser = src.parser; //move the parser field
	return *this; //and return the object
}

//interpret method - interprets a die equation
int DieEqnInterpreter::interpret() {
	DieEqnAST* ast = this->parser.parse(); //get the AST for the roll
	int result = this->eval(ast); //evaluate it
	delete ast; //deallocate the AST
	ast = nullptr; //and zero it out
	return result; //finally, return the result of the roll
}

//private eval method - evaluates the AST for a die equation
int DieEqnInterpreter::eval(const DieEqnAST* tree) {
	if(!tree) { //if the AST is null
		throw NullASTException(); //then throw an exception
	}
	switch(tree->getType()) { //switch on the type
		case EnumEqnAST::NUM: //numeric value
			{
				return dynamic_cast<const DieEqnNum*>(tree)->intValue(); //return the integer value of the node
			}
		case EnumEqnAST::OP: //operator
			{
				switch(dynamic_cast<const DieEqnOp*>(tree)->getOp()) {
						case EnumEqnOps::DIE:
							{
								int mult = this->eval(tree->getLeft());
								int sides = this->eval(tree->getRight());
								Die d(sides);
								int result = 0;
								for(int i = 0; i < mult; i++) {
									d.roll();
									result += d.getValue();
								}
								return result;
							}
						case EnumEqnOps::ADD:
							{
								return this->eval(tree->getLeft()) + this->eval(tree->getRight());
							}
						case EnumEqnOps::SUB:
							{
								return this->eval(tree->getLeft()) - this->eval(tree->getRight());
							}
						default:
							{
								break;
							}
				}
			}
		default:
			{
				break;
			}
	}
}

//end of implementation							
