/*
 * NullASTException.h
 * Declares an exception that is thrown when a null AST node is found
 * Created by Andrew Davis
 * Created on 6/29/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef NULL_AST_EXCE
#define NULL_AST_EXCE

//include
#include <exception>

//class declaration
class NullASTException final : public std::exception
{
	//public fields and methods
	public:
		//constructors are defaulted

		//overridden what method - called on the exception
		const char* what() const throw() override;

	//no private fields
};

#endif
