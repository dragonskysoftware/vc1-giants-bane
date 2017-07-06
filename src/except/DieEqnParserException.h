/*
 * DieEqnParserException.h
 * Declares an exception that is thrown when an 
 * invalid die equation is processed by the die equation parser
 * Created by Andrew Davis
 * Created on 6/27/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef DIE_EQN_PARSE_EXCE
#define DIE_EQN_PARSE_EXCE

//includes
#include <exception>
#include <string>

//class declaration
class DieEqnParserException final : public std::exception
{
	//public fields and methods
	public:

		//constructor
		explicit DieEqnParserException(const std::string& badToken);
	
		//destructor
		~DieEqnParserException();

		//copy constructor
		DieEqnParserException(const DieEqnParserException& depe);

		//move constructor
		DieEqnParserException(DieEqnParserException&& depe);

		//assignment operator
		DieEqnParserException& operator=(const DieEqnParserException& src);

		//move operator
		DieEqnParserException& operator=(DieEqnParserException&& src);

		//overridden what method - called when the exception is thrown
		const char* what() const throw() override;

	//private fields and methods
	private:
		//field
		std::string msg; //the error message

	
};

#endif
