/*
 * InvalidSoundException.h
 * Declares an exception that is thrown when an invalid sound is found
 * Created by Andrew Davis
 * Created on 4/9/2017
 * All rights reserved
 */

//disallow reinclusion
#ifndef INVAL_SND_EXCE
#define INVAL_SND_EXCE

//includes
#include <exception>
#include <string>

//class declaration
class InvalidSoundException final : public std::exception
{
	//public fields and methods
	public:
		//constructor
		InvalidSoundException(const char* soundName, const char* error);

		//destructor
		~InvalidSoundException();

		//copy constructor
		InvalidSoundException(const InvalidSoundException& ise);

		//move constructor
		InvalidSoundException(InvalidSoundException&& ise);

		//assignment operator
		InvalidSoundException& operator=(const InvalidSoundException& src);

		//move operator
		InvalidSoundException& operator=(InvalidSoundException&& src);

		//overridden what() method - called when the exception is thrown
		const char* what() const throw() override;
	
	//private fields and methods
	private:
		//fields
		std::string errorString; //the string containing the error message
};

#endif
