/*
 * InvalidAbilityScoreException.h
 * Declares an exception that is thrown when an invalid ability score is encountered
 * Created by Andrew Davis
 * Created on 3/14/2017
 * All rights reserved
 */

//disallow reinclusion
#ifndef INVAL_SCORE_EXCE
#define INVAL_SCORE_EXCE

//includes
#include <exception>
#include <string>

//class declaration
class InvalidAbilityScoreException final : public std::exception
{
	//public fields and methods
	public:
		//constructor
		InvalidAbilityScoreException(int badScore);

		//destructor
		~InvalidAbilityScoreException();

		//copy constructor
		InvalidAbilityScoreException(const InvalidAbilityScoreException& iase);

		//move constructor
		InvalidAbilityScoreException(InvalidAbilityScoreException&& iase);

		//assignment operator
		InvalidAbilityScoreException& operator=(const InvalidAbilityScoreException& src);

		//move operator
		InvalidAbilityScoreException& operator=(InvalidAbilityScoreException&& src);

		//overridden what() method - called when the exception is thrown
		const char* what() const throw() override;
	
	//private fields and methods
	private:
		//fields
		std::string errorString; //the string containing the error message
};

#endif
