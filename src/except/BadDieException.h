/*
 * BadDieException.h
 * Declares an exception that is thrown when a bad die is encountered
 * Created by Andrew Davis
 * Created on 6/26/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef BAD_DIE_EXCEPT_H
#define BAD_DIE_EXCEPT_H

//includes
#include <exception>
#include <string>

//class declaration
class BadDieException final : public std::exception
{
	//public fields and methods
	public:
		//constructor
		explicit BadDieException(const char* newMsg);

		//destructor
		~BadDieException();

		//copy constructor
		BadDieException(const BadDieException& bde);

		//move constructor
		BadDieException(BadDieException&& bde);

		//assignment operator
		BadDieException& operator=(const BadDieException& src);

		//move operator
		BadDieException& operator=(BadDieException&& src);

		//overridden what method - called on the exception
		const char* what() const throw() override;

	//private fields and methods
	private:
		//field
		std::string msg; //the error message
};

#endif
