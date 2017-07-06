/*
 * MsgBoxData.cpp
 * Implements a class that represents GUI message box data
 * Created by Andrew Davis
 * Created on 4/14/2017
 * All rights reserved
 */

//include header
#include "MsgBoxData.h"

//first constructor
MsgBoxData::MsgBoxData(int newFlags, const char* newTitle, const char* newMsg, int numbuttons, const MsgBoxButtonData* newButtons, const MsgBoxColorScheme& newScheme)
	: flags(newFlags), window(nullptr), title(newTitle), message(newMsg), buttonCount(numbuttons), buttons(nullptr), scheme(newScheme) //init the fields
{
	this->window = Game::getWindow(); //assign the window pointer
	this->buttons = new MsgBoxButtonData[this->buttonCount]; //allocate memory for the button data
	for(int i = 0; i < this->buttonCount; i++) { //loop through the button array
		this->buttons[i] = newButtons[i]; //and assign over the button data
	}
}

//second constructor
MsgBoxData::MsgBoxData(int newFlags, const std::string& newTitle, const std::string& newMsg, int numbuttons, const MsgBoxButtonData* newButtons, const MsgBoxColorScheme& newScheme)
	: MsgBoxData(newFlags, newTitle.c_str(), newMsg.c_str(), numbuttons, newButtons, newScheme) //call first constructor
{
	//no code needed
}

//third constructor
MsgBoxData::MsgBoxData(int newFlags, const char* newTitle, const std::string& newMsg, int numbuttons, const MsgBoxButtonData* newButtons, const MsgBoxColorScheme& newScheme)
	: MsgBoxData(newFlags, newTitle, newMsg.c_str(), numbuttons, newButtons, newScheme) //call first constructor
{
	//no code needed
}

//fourth constructor
MsgBoxData::MsgBoxData(int newFlags, const std::string& newTitle, const char* newMsg, int numbuttons, const MsgBoxButtonData* newButtons, const MsgBoxColorScheme& newScheme)
	: MsgBoxData(newFlags, newTitle.c_str(), newMsg, numbuttons, newButtons, newScheme) //call first constructor
{
	//no code needed
}

//destructor
MsgBoxData::~MsgBoxData() {
	this->free(); //deallocate the object
}

//copy constructor
MsgBoxData::MsgBoxData(const MsgBoxData& mbd)
	: flags(mbd.flags), window(mbd.window), title(mbd.title), message(mbd.message), buttonCount(mbd.buttonCount), buttons(nullptr), scheme(mbd.scheme) //copy the fields
{
	this->buttons = new MsgBoxButtonData[this->buttonCount]; //allocate memory for the button data
	for(int i = 0; i < this->buttonCount; i++) { //loop through the button array
		this->buttons[i] = mbd.buttons[i]; //and copy over the button data
	}
}

//move constructor
MsgBoxData::MsgBoxData(MsgBoxData&& mbd)
	: flags(mbd.flags), window(mbd.window), title(mbd.title), message(mbd.message), buttonCount(mbd.buttonCount), buttons(nullptr), scheme(mbd.scheme) //move the fields
{
	this->buttons = new MsgBoxButtonData[this->buttonCount]; //allocate memory for the button data
	for(int i = 0; i < this->buttonCount; i++) { //loop through the button array
		this->buttons[i] = mbd.buttons[i]; //and move over the button data
	}
	mbd.free(); //deallocate the temporary
}

//assignment operator
MsgBoxData& MsgBoxData::operator=(const MsgBoxData& src) {
	this->flags = src.flags; //assign the flags
	this->window = src.window; //assign the window pointer
	this->title = src.title; //assign the title
	this->message = src.message; //assign the message
	this->buttonCount = src.buttonCount; //assign the button count
	for(int i = 0; i < this->buttonCount; i++) { //loop through the button array
		this->buttons[i] = src.buttons[i]; //and assign the buttons
	}
	this->scheme = src.scheme; //assign the color scheme
	return *this; //return the object
}

//move operator
MsgBoxData& MsgBoxData::operator=(MsgBoxData&& src) {
	this->flags = src.flags; //move the flags
	this->window = src.window; //move the window pointer
	this->title = src.title; //move the title
	this->message = src.message; //move the message
	this->buttonCount = src.buttonCount; //move the button count
	for(int i = 0; i < this->buttonCount; i++) { //loop through the button array
		this->buttons[i] = src.buttons[i]; //and move the buttons
	}
	this->scheme = src.scheme; //move the color scheme
	src.free(); //deallocate the temporary
	return *this; //return the object
}

//getter methods

//getFlags method - returns the flags for the data
int MsgBoxData::getFlags() const {
	return this->flags; //return the flags field
}

//getTitle method - returns the title string for the message box
const std::string& MsgBoxData::getTitle() const {
	return this->title; //return the title field
}

//getMessage method - returns the message string for the message box
const std::string& MsgBoxData::getMessage() const {
	return this->message; //return the message field
}

//getButtonCount method - returns the number of buttons in the message box
int MsgBoxData::getButtonCount() const {
	return this->buttonCount; //return the button count field
}

//getButtonData method - returns the button data for the message box
const MsgBoxButtonData* MsgBoxData::getButtonData() const {
	return this->buttons; //return the button data field
}

//getColorScheme method - returns the color scheme for the message box
const MsgBoxColorScheme& MsgBoxData::getColorScheme() const {
	return this->scheme; //return the color scheme field
}

//other methods

//toSDLData method - converts the object to native SDL data
SDL_MessageBoxData MsgBoxData::toSDLData() const {
	std::vector<SDL_MessageBoxButtonData> buttonArr; //the vector of buttons
	for(int i = 0; i < this->buttonCount; i++) { //loop through the buttons
		buttonArr.push_back(this->buttons[i].toSDLData()); //and add them to the vector
	}
	SDL_MessageBoxColorScheme sdlScheme = this->scheme.toSDLData(); //get the color scheme object
	SDL_MessageBoxData ret = {
		static_cast<Uint32>(this->flags),
		this->window,
		this->title.c_str(),
		this->message.c_str(),
		this->buttonCount,
		&buttonArr[0],
		&sdlScheme
	};
	return ret; //return the data
}

//private free method - deallocates the object
void MsgBoxData::free() {
	delete[] this->buttons; //deallocate the button array
	this->buttons = nullptr; //and zero it out
}

//end of implementation
