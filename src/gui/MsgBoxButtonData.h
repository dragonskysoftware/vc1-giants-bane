/*
 * MsgBoxButtonData.h
 * Declares a class that represents message box button data
 * Created by Andrew Davis
 * Created on 4/13/2017
 * All rights reserved
 */

//disallow reinclusion
#ifndef MSG_BOX_BUTTON_DATA_H
#define MSG_BOX_BUTTON_DATA_H

//includes
#include <SDL2/SDL.h>
#include <string>
#include <functional>
#include "../util/strdup.h"

//class declaration
class MsgBoxButtonData final {
	//public fields and methods
	public:
		//default constructor
		MsgBoxButtonData();

		//constructor 1 - constructs from an integer, another integer, a C string, and a callback
		MsgBoxButtonData(int newFlag, int newID, const char* newText, std::function<void()> newCallback);

		//constructor 2 - constructs from an integer, another integer, an std::string, and a callback
		MsgBoxButtonData(int newFlag, int newID, const std::string& newText, std::function<void()> newCallback);

		//destructor
		~MsgBoxButtonData();

		//copy constructor
		MsgBoxButtonData(const MsgBoxButtonData& mbbd);

		//move constructor
		MsgBoxButtonData(MsgBoxButtonData&& mbbd);

		//assignment operator
		MsgBoxButtonData& operator=(const MsgBoxButtonData& src);

		//move operator
		MsgBoxButtonData& operator=(MsgBoxButtonData&& src);

		//getter methods
		int getFlag() const; //returns the flag field
		int getID() const; //returns the button ID field
		const std::string& getText() const; //returns the text field
		std::function<void()> getCallback() const; //returns the callback field

		//other methods
		SDL_MessageBoxButtonData toSDLData() const; //converts the object to a native SDL format
		void onClick() const; //called when the button is clicked
	
	//private fields and methods
	private:
		//fields
		int flag; //the button flag
		int id; //the button ID
		std::string text; //the button text
		std::function<void()> callback; //the function that is executed if the button is clicked
};

#endif
