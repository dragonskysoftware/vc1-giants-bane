/*
 * ArrayRef.h
 * Declares a class that represents an array reference AST node
 * Created by Andrew Davis
 * Created on 3/23/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef ARR_REF_H
#define ARR_REF_H

//includes
#include "ASTNode.h"
#include "EnumNodeType.h"
#include "Symbol.h"
#include "Array.h"
#include "../../except/InvalidStateException.h"

//class declaration
class ArrayRef final : public ASTNode
{
	//public fields and methods
	public:
		//constructor
		ArrayRef(Symbol* newSym, const ASTNode* newIndex);

		//destructor
		~ArrayRef();

		//copy constructor
		ArrayRef(const ArrayRef& ar);

		//move constructor
		ArrayRef(ArrayRef&& ar);

		//assignment operator
		ArrayRef& operator=(const ArrayRef& src);

		//move operator
		ArrayRef& operator=(ArrayRef&& src);

		//getter methods
		Array& array(); //returns the stored Symbol's array
		ASTNode* getIndexNode(); //returns the index node for the ArrayRef object

	//private fields and methods
	private:
		//private method
		void free(); //deallocates an ArrayRef object

		//fields
		Symbol* sym; //the symbol that stores the Array
		ASTNode* indexNode; //the AST node that is used to calculate the array index to access
};

#endif
