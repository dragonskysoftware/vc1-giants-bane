/*
 * InvalidStateException.h
 * Declares an exception that is thrown when an object enters an invalid operational state
 * Created by Andrew Davis
 * Created on 3/11/2017
 * All rights reserved
 */

//disallow reinclusion
#ifndef INVAL_ST_EXCE
#define INVAL_ST_EXCE

//includes
#include <exception>
#include <string>

//class declaration
class InvalidStateException final : public std::exception
{
	//public fields and methods
	public:
		//constructor
		InvalidStateException(const char* msg);

		//destructor
		~InvalidStateException();

		//copy constructor
		InvalidStateException(const InvalidStateException& ise);

		//move constructor
		InvalidStateException(InvalidStateException&& ise);

		//assignment operator
		InvalidStateException& operator=(const InvalidStateException& src);

		//move operator
		InvalidStateException& operator=(InvalidStateException&& src);

		//overridden what() method - called when the exception is thrown
		const char* what() const throw() override;
	
	//private fields and methods
	private:
		//fields
		std::string errorString; //the string containing the error message
};

#endif
