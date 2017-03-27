/*
 * InvalidASTException.h
 * Declares an exception that is thrown when an invalid AST is found by the EvScript interpreter
 * Created by Andrew Davis
 * Created on 3/27/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef INVAL_AST_EXCE
#define INVAL_AST_EXCE

//includes
#include <exception>
#include <string>

//class declaration
class InvalidASTException final : public std::exception
{
	//public fields and methods
	public:
		//constructor
		InvalidASTException(const char* msg);

		//destructor
		~InvalidASTException();

		//copy constructor
		InvalidASTException(const InvalidASTException& iae);

		//move constructor
		InvalidASTException(InvalidASTException&& iae);

		//assignment operator
		InvalidASTException& operator=(const InvalidASTException& src);

		//move operator
		InvalidASTException& operator=(InvalidASTException&& src);

		//overridden what() method - called when the exception is thrown
		const char* what() const throw() override;
	
	//private fields and methods
	private:
		//fields
		std::string errorString; //the string containing the error message
};

#endif
