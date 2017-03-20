/*
 * OutOfRangeException.h
 * Declares an exception that is thrown when an object enters an invalid operational state
 * Created by Andrew Davis
 * Created on 3/11/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef OUT_OF_RNG_EXCE
#define OUT_OF_RNG_EXCE

//includes
#include <exception>
#include <string>

//class declaration
class OutOfRangeException final : public std::exception
{
	//public fields and methods
	public:
		//constructor
		OutOfRangeException(int badIndex);

		//destructor
		~OutOfRangeException();

		//copy constructor
		OutOfRangeException(const OutOfRangeException& ore);

		//move constructor
		OutOfRangeException(OutOfRangeException&& ore);

		//assignment operator
		OutOfRangeException& operator=(const OutOfRangeException& src);

		//move operator
		OutOfRangeException& operator=(OutOfRangeException&& src);

		//overridden what() method - called when the exception is thrown
		const char* what() const throw() override;
	
	//private fields and methods
	private:
		//fields
		std::string errorString; //the string containing the error message
};

#endif
