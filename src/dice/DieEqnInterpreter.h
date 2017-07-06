/*
 * DieEqnInterpreter.h
 * Declares a class that interpretes die equations
 * Created by Andrew Davis
 * Created on 6/29/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef DIE_EQN_INTERPRET_H
#define DIE_EQN_INTERPRET_H

//includes
#include "Die.h"
#include "EnumEqnAST.h"
#include "EnumEqnOps.h"
#include "DieEqnAST.h"
#include "DieEqnOp.h"
#include "DieEqnNum.h"
#include "DieEqnParser.h"
#include "../except/NullASTException.h"

//class declaration
class DieEqnInterpreter final {
	//public fields and methods
	public:
		//constructor
		explicit DieEqnInterpreter(const DieEqnParser& newParser);

		//destructor
		~DieEqnInterpreter();

		//copy constructor
		DieEqnInterpreter(const DieEqnInterpreter& dei);

		//move constructor
		DieEqnInterpreter(DieEqnInterpreter&& dei);

		//assignment operator
		DieEqnInterpreter& operator=(const DieEqnInterpreter& src);

		//move operator
		DieEqnInterpreter& operator=(DieEqnInterpreter&& src);

		//other methods

		int interpret(); //interprets the die equation

	//private fields and methods
	private:
		//method
		int eval(const DieEqnAST* tree); //evaluates an AST

		//field
		DieEqnParser parser; //the parser for the die equation
};

#endif
