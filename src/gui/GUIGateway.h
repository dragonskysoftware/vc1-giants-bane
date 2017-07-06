/*
 * GUIGateway.h
 * Declares a singleton class that acts as a gateway between GUI elements and the rest of the program
 * Created by Andrew Davis
 * Created on 4/13/2017
 * All rights reserved
 */

//disallow reinclusion
#ifndef GUI_GATEWAY_H
#define GUI_GATEWAY_H

//includes
#include "../audio/SoundEffect.h"
#include "../util/functions.h"

//class declaration
class GUIGateway final {
	//public fields and methods
	public:
		//delete the copy constructor, move constructor, assignment operator, and move operator
		GUIGateway(const GUIGateway& gg) = delete;
		GUIGateway(GUIGateway&& gg) = delete;
		GUIGateway& operator=(const GUIGateway& src) = delete;
		GUIGateway& operator=(GUIGateway&& src) = delete;

		//getInstance method - returns an instance of the class
		static GUIGateway& getInstance();

		//other methods
		void playWarningTone() const; //plays a short warning tone
		//TODO: Declare more methods

	//private fields and methods
	private:
		GUIGateway(); //constructor

};

#endif
