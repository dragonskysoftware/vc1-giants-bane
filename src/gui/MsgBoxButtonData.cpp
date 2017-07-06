/*
 * MsgBoxButtonData.cpp
 * Implements a class that represents message box button data
 * Created by Andrew Davis
 * Created on 4/13/2017
 * All rights reserved
 */

//include header
#include "MsgBoxButtonData.h"

//default constructor
MsgBoxButtonData::MsgBoxButtonData()
	: flag(0), id(0), text(), callback() //zero the fields
{
	//no code needed
}

//first constructor - constructs from two ints, a C string, and a callback
MsgBoxButtonData::MsgBoxButtonData(int newFlag, int newID, const char* newText, std::function<void()> newCallback)
	: flag(newFlag), id(newID), text(newText), callback(newCallback) //init the fields
{
	//no code needed
}

//second constructor - constructs from two ints, a std::string, and a callback
MsgBoxButtonData::MsgBoxButtonData(int newFlag, int newID, const std::string& newText, std::function<void()> newCallback)
	: MsgBoxButtonData(newFlag, newID, newText.c_str(), newCallback) //call other constructor
{
	//no code needed
}

//destructor
MsgBoxButtonData::~MsgBoxButtonData() {
	//no code needed
}

//copy constructor
MsgBoxButtonData::MsgBoxButtonData(const MsgBoxButtonData& mbbd)
	: flag(mbbd.flag), id(mbbd.id), text(mbbd.text), callback(mbbd.callback) //copy the fields
{
	//no code needed
}

//move constructor
MsgBoxButtonData::MsgBoxButtonData(MsgBoxButtonData&& mbbd)
	: flag(mbbd.flag), id(mbbd.id), text(mbbd.text), callback(mbbd.callback) //move the fields
{
	//no code needed
}

//assignment operator
MsgBoxButtonData& MsgBoxButtonData::operator=(const MsgBoxButtonData& src) {
	this->flag = src.flag; //assign the flag
	this->id = src.id; //assign the button ID
	this->text = src.text; //assign the text
	this->callback = src.callback; //assign the callback
	return *this; //return the object
}

//move operator
MsgBoxButtonData& MsgBoxButtonData::operator=(MsgBoxButtonData&& src) {
	this->flag = src.flag; //move the flag
	this->id = src.id; //move the button ID
	this->text = src.text; //move the text
	this->callback = src.callback; //move the callback
	return *this; //return the object
}

//getter methods

//getFlag method - returns the flag of the button
int MsgBoxButtonData::getFlag() const {
	return this->flag; //return the flag field
}

//getID method - returns the ID of the button
int MsgBoxButtonData::getID() const {
	return this->id; //return the ID field
}

//getText method - returns the text of the button
const std::string& MsgBoxButtonData::getText() const {
	return this->text; //return the text field
}

//getCallback method - returns the button's callback function
std::function<void()> MsgBoxButtonData::getCallback() const {
	return this->callback; //return the callback field
}

//other methods

//toSDLData method - converts the object to native SDL data
SDL_MessageBoxButtonData MsgBoxButtonData::toSDLData() const {
	SDL_MessageBoxButtonData ret; //the value to return
	ret.flags = this->flag; //assign over the flags
	ret.buttonid = this->id; //assign over the button ID
	ret.text = C_strdup(this->text.c_str()); //duplicate the stored text and assign it over
	return ret; //return the initialized structure
}

//onClick method - called when the button is clicked
void MsgBoxButtonData::onClick() const {
	this->callback(); //execute the callback
}

//end of implementation
