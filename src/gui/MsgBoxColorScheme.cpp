/*
 * MsgBoxColorScheme.cpp
 * Implements a class that represents a message box color scheme
 * Created by Andrew Davis
 * Created on 4/13/2017
 * All rights reserved
 */

//include header
#include "MsgBoxColorScheme.h"

//constructor
MsgBoxColorScheme::MsgBoxColorScheme(unsigned newBG, unsigned newText, unsigned newBBorder, unsigned newBBG, unsigned newSelect)
	: colors() //init the field
{
	//convert the arguments into RGB instances
	this->convertHex(newBG, 0); //convert the background
	this->convertHex(newText, 1); //convert the text
	this->convertHex(newBBorder, 2); //convert the button border
	this->convertHex(newBBG, 3); //convert the button background
	this->convertHex(newSelect, 4); //convert the selection
}

//destructor
MsgBoxColorScheme::~MsgBoxColorScheme() {
	//no code needed
}

//copy constructor
MsgBoxColorScheme::MsgBoxColorScheme(const MsgBoxColorScheme& mbcs)
	: colors(mbcs.colors) //copy the colors
{
	//no code needed
}

//move constructor
MsgBoxColorScheme::MsgBoxColorScheme(MsgBoxColorScheme&& mbcs)
	: colors(mbcs.colors) //move the colors
{
	//no code needed
}

//assignment operator
MsgBoxColorScheme& MsgBoxColorScheme::operator=(const MsgBoxColorScheme& src) {
	this->colors = src.colors; //assign the colors
	return *this; //and return the object
}

//move operator
MsgBoxColorScheme& MsgBoxColorScheme::operator=(MsgBoxColorScheme&& src) {
	this->colors = src.colors; //move the colors
	return *this; //and return the object
}

//other methods

//toSDLData method - converts the scheme to native SDL data
SDL_MessageBoxColorScheme MsgBoxColorScheme::toSDLData() const {
	SDL_MessageBoxColorScheme ret; //the return value
	for(int i = 0; i < 5; i++) { //loop through the two schemes
		SDL_MessageBoxColor temp;
		temp.r = this->colors[i].r; //assign the red value
		temp.g = this->colors[i].g; //assign the green value
		temp.b = this->colors[i].b; //assign the blue value
		ret.colors[i] = temp; //assign the completed color
	}
	return ret; //return the SDL data as a pointer
}

//private convertHex method - converts a hex color value to an RGB value
void MsgBoxColorScheme::convertHex(unsigned hex, int colorIndex) {
	RGB color; //the value to be stored in the colors array
	color.r = ((hex >> 16) & 0xff) / 255; //get the red value
	color.g = ((hex >> 8) & 0xff) / 255; //get the green value
	color.b = ((hex) & 0xff) / 255; //get the blue value
	this->colors[colorIndex] = color; //assign in the color
}

//end of implementation
