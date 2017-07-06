/*
 * SimpleMsgBox.h
 * Declares a class that represents a simple message box (one with no callbacks)
 * Created by Andrew Davis
 * Created on 4/19/2017
 * All rights reserved
 */

//disallow reinclusion
#ifndef SIMP_MSG_BOX_H
#define SIMP_MSG_BOX_H

//includes
#include <SDL2/SDL.h>
#include <string>
#include "../except/MessageBoxException.h" 
#include "../core/Game.h"
#include "../audio/SoundEffect.h"

//class declaration
class SimpleMsgBox final {
	//public fields and methods
	public:
		//constructor
		SimpleMsgBox(int newFlags, const std::string& newTitle, const std::string& newMessage);

		//destructor
		~SimpleMsgBox();

		//copy constructor
		SimpleMsgBox(const SimpleMsgBox& smb);

		//move operator
		SimpleMsgBox(SimpleMsgBox&& smb);

		//assignment operator
		SimpleMsgBox& operator=(const SimpleMsgBox& src);

		//move operator
		SimpleMsgBox& operator=(SimpleMsgBox&& src);

		//other method
		void show() const; //brings up the SimpleMsgBox and allows input
	
	//private fields and methods
	private:
		//fields
		int flags; //the message box type flags
		std::string title; //the title of the message box
		std::string message; //the message of the message box
		SDL_Window* window; //the parent window of the message box
};

#endif
