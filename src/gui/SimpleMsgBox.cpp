/*
 * SimpleMsgBox.cpp
 * Implements a class that represents a simple message box (one with no callbacks)
 * Created by Andrew Davis
 * Created on 4/19/2017
 * All rights reserved
 */

//include header
#include "SimpleMsgBox.h"

//constructor
SimpleMsgBox::SimpleMsgBox(int newFlags, const std::string& newTitle, const std::string& newMessage)
	: flags(newFlags), title(newTitle), message(newMessage), window(Game::getWindow()) //init the fields
{
	//no code needed
}

//destructor
SimpleMsgBox::~SimpleMsgBox() {
	//no code needed
}

//copy constructor
SimpleMsgBox::SimpleMsgBox(const SimpleMsgBox& smb)
	: flags(smb.flags), title(smb.title), message(smb.message), window(smb.window) //copy the fields
{
	//no code needed
}

//move constructor
SimpleMsgBox::SimpleMsgBox(SimpleMsgBox&& smb)
	: flags(smb.flags), title(smb.title), message(smb.message), window(smb.window) //move the fields
{
	//no code needed
}

//assignment operator
SimpleMsgBox& SimpleMsgBox::operator=(const SimpleMsgBox& src) {
	this->flags = src.flags; //assign the flags
	this->title = src.title; //assign the title
	this->message = src.message; //assign the message
	this->window = src.window; //assign the window
	return *this; //return the object
}

//move operator
SimpleMsgBox& SimpleMsgBox::operator=(SimpleMsgBox&& src) {
	this->flags = src.flags; //move the flags
	this->title = src.title; //move the title
	this->message = src.message; //move the message
	this->window = src.window; //move the window
	return *this; //return the object
}

//other method

//show method - displays the SimpleMsgBox and allows input
void SimpleMsgBox::show() const {
	//display the message box and test for errors
	SoundEffect* warningTone = nullptr; //declare the warning tone sound effect
	if(this->flags == SDL_MESSAGEBOX_WARNING) { // if the message box is a warning box
		warningTone = new SoundEffect("../assets/sounds/warning.ogg"); //allocate the warning tone
		warningTone->play(); //then play the warning tone
	}
	if(SDL_ShowSimpleMessageBox(this->flags, this->title.c_str(), this->message.c_str(), this->window) < 0) {
		//if this point is reached, an error occured while displaying the message box.
		//So, we throw a MessageBoxException, passing it the result of SDL_GetError().
		//We also clean up the warning tone
		delete warningTone; //deallocate the warning tone
		warningTone = nullptr; //and zero it out
		throw MessageBoxException(SDL_GetError());
	}
	delete warningTone; //deallocate the warning tone
	warningTone = nullptr; //and zero it out
}

//end of implementation
