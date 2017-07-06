/*
 * MsgBoxData.h
 * Declares a class that represents GUI message box data
 * Created by Andrew Davis
 * Created on 4/13/2017
 * All rights reserved
 */

//disallow reinclusion
#ifndef MSG_BOX_DATA_H
#define MSG_BOX_DATA_H

//includes
#include <SDL2/SDL.h>
#include <string>
#include <vector>
#include "../core/Game.h"
#include "../util/strdup.h"
#include "MsgBoxButtonData.h"
#include "MsgBoxColorScheme.h"

//class declaration
class MsgBoxData final {
	//public fields and methods
	public:
		//constructor 1 - constructs using various values, including two C strings
		MsgBoxData(int newFlags, const char* newTitle, const char* newMsg, int numbuttons, const MsgBoxButtonData* newButtons, const MsgBoxColorScheme& newScheme);
		
		//constructor 2 - constructs using various values, including two std::strings
		MsgBoxData(int newFlags, const std::string& newTitle, const std::string& newMsg, int numbuttons, const MsgBoxButtonData* newButtons, const MsgBoxColorScheme& newScheme);

		//constructor 3 - constructs using various values, including a C string and an std::string
		MsgBoxData(int newFlags, const char* newTitle, const std::string& newMsg, int numbuttons, const MsgBoxButtonData* newButtons, const MsgBoxColorScheme& newScheme);

		//constructor 4 - constructs using various values, including an std::string and a C string
		MsgBoxData(int newFlags, const std::string& newTitle, const char* newMsg, int numbuttons, const MsgBoxButtonData* newButtons, const MsgBoxColorScheme& newScheme);

		//destructor
		~MsgBoxData();

		//copy constructor
		MsgBoxData(const MsgBoxData& mbd);

		//move constructor
		MsgBoxData(MsgBoxData&& mbd);

		//assignment operator
		MsgBoxData& operator=(const MsgBoxData& src);

		//move operator
		MsgBoxData& operator=(MsgBoxData&& src);

		//getter methods
		int getFlags() const; //returns the flags for the data
		const std::string& getTitle() const; //returns the title of the message box
		const std::string& getMessage() const; //returns the message of the message box
		int getButtonCount() const; //returns the number of buttons in the message box
		const MsgBoxButtonData* getButtonData() const; //returns the actual button data
		const MsgBoxColorScheme& getColorScheme() const; //returns the message box's color scheme

		//other method
		SDL_MessageBoxData toSDLData() const; //converts the object to native SDL data
	
	//private fields and methods
	private:
		//method
		void free(); //deallocates the object
		//fields
		int flags; //the flags for the data
		SDL_Window* window; //the window that the message box is displayed in
		std::string title; //the title of the message box
		std::string message; //the message of the message box
		int buttonCount; //the number of buttons in the message box
		MsgBoxButtonData* buttons; //the buttons for the message box
		MsgBoxColorScheme scheme; //the color scheme for the message box
};

#endif
