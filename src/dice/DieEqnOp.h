/*
 * DieEqnOp.h
 * Declares a class that represents a operation AST node for die equations
 * Created by Andrew Davis
 * Created on 6/27/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef DIE_EQN_OP_H
#define DIE_EQN_OP_H

//includes
#include <string>
#include "DieEqnAST.h"
#include "EnumEqnOps.h"
#include "EnumEqnAST.h"

//class declaration
class DieEqnOp final : public DieEqnAST
{
	//public fields and methods
	public:
		//constructor
		DieEqnOp(EnumEqnOps newOp, const std::string& newValue, DieEqnAST* newLeft, DieEqnAST* newRight);

		//destructor
		~DieEqnOp();

		//copy constructor
		DieEqnOp(const DieEqnOp& deo);

		//move constructor
		DieEqnOp(DieEqnOp&& deo);

		//assignment operator
		DieEqnOp& operator=(const DieEqnOp& src);

		//move operator
		DieEqnOp& operator=(DieEqnOp&& src);

		//getter methods

		EnumEqnOps getOp() const; //returns the operation type
		char getSymbol() const; //returns the operation symbol

	//private fields and methods
	private:
		//field
		EnumEqnOps op; //the operation type
};

#endif
