/*
 * DieEqnLexerException.h
 * Declares an exception that is thrown when an 
 * invalid die equation is processed by the die equation lexer
 * Created by Andrew Davis
 * Created on 6/27/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef DIE_EQN_LEX_EXCE
#define DIE_EQN_LEX_EXCE

//includes
#include <exception>
#include <string>

//class declaration
class DieEqnLexerException final : public std::exception
{
	//public fields and methods
	public:

		//constructor
		explicit DieEqnLexerException(const std::string& badEqn);
	
		//destructor
		~DieEqnLexerException();

		//copy constructor
		DieEqnLexerException(const DieEqnLexerException& dele);

		//move constructor
		DieEqnLexerException(DieEqnLexerException&& dele);

		//assignment operator
		DieEqnLexerException& operator=(const DieEqnLexerException& src);

		//move operator
		DieEqnLexerException& operator=(DieEqnLexerException&& src);

		//overridden what method - called when the exception is thrown
		const char* what() const throw() override;

	//private fields and methods
	private:
		//field
		std::string msg; //the error message

	
};

#endif
