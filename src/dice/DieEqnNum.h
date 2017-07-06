/*
 * DieEqnNum.h
 * Declares a class that represents a numeric AST node for die equations
 * Created by Andrew Davis
 * Created on 6/26/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef DIE_EQN_AST_NUM
#define DIE_EQN_AST_NUM

//includes
#include "DieEqnAST.h"
#include "EnumEqnAST.h"
#include <string>

//class declaration
class DieEqnNum final : public DieEqnAST
{
	//public fields and methods
	public:
		//constructor
		explicit DieEqnNum(const std::string& newValue);

		//destructor
		~DieEqnNum();

		//copy constructor
		DieEqnNum(const DieEqnNum& den);

		//move constructor
		DieEqnNum(DieEqnNum&& den);

		//assignment operator
		DieEqnNum& operator=(const DieEqnNum& src);

		//move operator
		DieEqnNum& operator=(DieEqnNum&& src);

		//getter method

		int intValue() const; //returns the AST node's value

	//no private members
};

#endif
