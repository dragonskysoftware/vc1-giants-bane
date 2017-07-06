/*
 * GUIGateway.cpp
 * Implements a singleton class that acts as a gateway between GUI elements and the rest of the program
 * Created by Andrew Davis
 * Created on 4/13/2017
 * All rights reserved
 */

//include header
#include "GUIGateway.h"

//private constructor
GUIGateway::GUIGateway()
{
	//no code needed
}

//getInstance method - returns an instance of the class
GUIGateway& GUIGateway::getInstance() {
	static GUIGateway instance; //only initialized once
	return instance; //return the instance
}

//other methods

//playWarningTone method - plays a short warning tone
void GUIGateway::playWarningTone() const {
	SoundEffect* warning = new SoundEffect("../assets/sounds/warning.ogg"); //create the sound effect
	warning->play(); //and play it
	uwait(500); //delay 1/2 second
	delete warning; //deallocate the sound effect
	warning = nullptr; //and zero it out
}

//TODO: Add more methods

//end of implementation
