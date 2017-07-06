/*
 * MessageBoxException.h
 * Declares an exception that is thrown when an error is encountered with a message box
 * Created by Andrew Davis
 * Created on 4/19/2017
 * All rights reserved
 */

//disallow reinclusion
#ifndef MSG_BOX_EXCE
#define MSG_BOX_EXCE

//includes
#include <exception>
#include <string>

//class declaration
class MessageBoxException final : public std::exception
{
	//public fields and methods
	public:
		//constructor
		MessageBoxException(const char* msg);

		//destructor
		~MessageBoxException();

		//copy constructor
		MessageBoxException(const MessageBoxException& mbe);

		//move constructor
		MessageBoxException(MessageBoxException&& mbe);

		//assignment operator
		MessageBoxException& operator=(const MessageBoxException& src);

		//move operator
		MessageBoxException& operator=(MessageBoxException&& src);

		//overridden what() method - called when the exception is thrown
		const char* what() const throw() override;
	
	//private fields and methods
	private:
		//fields
		std::string errorString; //the string containing the error message
};

#endif
