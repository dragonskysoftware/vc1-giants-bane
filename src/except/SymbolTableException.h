/*
 * SymbolTableException.h
 * Declares an exception that is thrown when a problem is found with the EvScript symbol table
 * Created by Andrew Davis
 * Created on 3/27/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef SYM_TAB_EXCE
#define SYM_TAB_EXCE

//includes
#include <exception>
#include <string>

//class declaration
class SymbolTableException final : public std::exception
{
	//public fields and methods
	public:
		//constructor
		SymbolTableException(const char* msg);

		//destructor
		~SymbolTableException();

		//copy constructor
		SymbolTableException(const SymbolTableException& ste);

		//move constructor
		SymbolTableException(SymbolTableException&& ste);

		//assignment operator
		SymbolTableException& operator=(const SymbolTableException& src);

		//move operator
		SymbolTableException& operator=(SymbolTableException&& src);

		//overridden what() method - called when the exception is thrown
		const char* what() const throw() override;
	
	//private fields and methods
	private:
		//fields
		std::string errorString; //the string containing the error message
};

#endif
