/*
 * DieEqnAST.h
 * Declares a class that represents an AST node for die equations
 * Created by Andrew Davis
 * Created on 6/26/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef DIE_EQN_AST_H
#define DIE_EQN_AST_H

//includes
#include "EnumEqnAST.h"
#include <string>

//class declaration
class DieEqnAST {
	//public fields and methods
	public:
		//constructor
		DieEqnAST(EnumEqnAST newType, const std::string& newValue, DieEqnAST* newLeft, DieEqnAST* newRight);

		//destructor
		virtual ~DieEqnAST();

		//copy constructor
		DieEqnAST(const DieEqnAST& dea);

		//move constructor
		DieEqnAST(DieEqnAST&& dea);

		//assignment operator
		DieEqnAST& operator=(const DieEqnAST& src);

		//move operator
		DieEqnAST& operator=(DieEqnAST&& src);

		//getter methods

		EnumEqnAST getType() const; //returns the type of the AST
		const std::string& stringValue() const; //returns the value
		const DieEqnAST* getLeft() const; //returns the left leg
		const DieEqnAST* getRight() const; //returns the right leg

	//protected fields and methods
	protected:
		//method
		void free(); //deallocates the object

		//fields
		EnumEqnAST type; //the type of the AST node
		std::string value; //the value of the AST node
		DieEqnAST* left; //the left leg of the AST
		DieEqnAST* right; //the right leg of the AST
};

#endif
