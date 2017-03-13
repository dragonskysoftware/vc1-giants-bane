/*
 * InvalidDiceEquationException.h
 * Declares an exception that is thrown when an invalid dice equation string is supplied for parsing
 * Created by Andrew Davis
 * Created on 3/13/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef INVAL_DE_EXCE
#define INVAL_DE_EXCE

//includes
#include <exception>
#include <string>

//class declaration
class InvalidDiceEquationException final : public std::exception
{
	//public fields and methods
	public:
		//constructor
		InvalidDiceEquationException(const char* badEqn);

		//destructor
		~InvalidDiceEquationException();

		//copy constructor
		InvalidDiceEquationException(const InvalidDiceEquationException& idee);

		//move constructor
		InvalidDiceEquationException(InvalidDiceEquationException&& idee);

		//assignment operator
		InvalidDiceEquationException& operator=(const InvalidDiceEquationException& src);

		//move operator
		InvalidDiceEquationException& operator=(InvalidDiceEquationException&& src);

		//overridden what() method - called when the exception is thrown
		const char* what() const throw() override;
	
	//private fields and methods
	private:
		//fields
		std::string errorString; //the string containing the error message
};

#endif
