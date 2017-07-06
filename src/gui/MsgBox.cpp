/*
 * MsgBox.cpp
 * Implements a class that represents an SDL message box
 * Created by Andrew Davis
 * Created on 4/19/2017
 * All rights reserved
 */

//include header
#include "MsgBox.h"

//constructor
MsgBox::MsgBox(const MsgBoxData& newData)
	: data(newData) //init the field
{
	//no code needed
}

//destructor
MsgBox::~MsgBox() {
	//no code needed
}

//copy constructor
MsgBox::MsgBox(const MsgBox& mb)
	: data(mb.data) //copy the field
{
	//no code needed
}

//move constructor
MsgBox::MsgBox(MsgBox&& mb)
	: data(mb.data) //move the field
{
	//no code needed
}

//assignment operator
MsgBox& MsgBox::operator=(const MsgBox& src) {
	this->data = src.data; //assign the data field
	return *this; //return the object
}

//move operator
MsgBox& MsgBox::operator=(MsgBox&& src) {
	this->data = src.data; //move the data field
	return *this; //return the object
}

//other method

//show method - brings up the MsgBox and allows input
void MsgBox::show() const {
	int buttonid; //will hold the ID of the clicked button
	SDL_MessageBoxData sdlData = this->data.toSDLData(); //get the data object in SDL form
	if(SDL_ShowMessageBox(&sdlData, &buttonid) < 0) { //if the display failed
		throw MessageBoxException(SDL_GetError()); //then throw an exception
	}
	if(buttonid != -1) { //if a selection was made
		this->data.getButtonData()[buttonid].onClick(); //then execute the respective callback
	}
}

//end of implementation
