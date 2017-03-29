/*
 * SymbolList.h
 * Declares a class that acts as a linked list that holds Symbol objects
 * Created by Andrew Davis
 * Created on 3/20/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef SYM_LIST_H
#define SYM_LIST_H

//forward declaration of class Symbol
class Symbol;

//class declaration
class SymbolList final
{
	//public fields and methods
	public:
		//constructor
		SymbolList(Symbol* newSym, const SymbolList* newNext);

		//destructor
		~SymbolList();

		//copy constructor
		SymbolList(const SymbolList& sl);

		//move constructor
		SymbolList(SymbolList&& sl);

		//assignment operator
		SymbolList& operator=(const SymbolList& src);

		//move operator
		SymbolList& operator=(SymbolList&& src);

		//getter method
		Symbol* getSymbol() const; //returns the symbol for the current SymbolList node

		//other method
		SymbolList*& nextNode(); //returns the next node in the list
	
	//private fields and methods
	private:
		//private method
		void free(); //deallocates the SymbolList

		//fields
		Symbol* sym; //the symbol for this SymbolList node
		SymbolList* next; //the next node in the list
};

#endif
