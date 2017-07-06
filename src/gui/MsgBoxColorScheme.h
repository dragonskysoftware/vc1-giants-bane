/*
 * MsgBoxColorScheme.h
 * Declares a class that represents a message box color scheme
 * Created by Andrew Davis
 * Created on 4/13/2017
 * All rights reserved
 */

//disallow reinclusion
#ifndef MSG_BOX_COLOR_H
#define MSG_BOX_COLOR_H

//includes
#include <SDL2/SDL.h>
#include <array>

//RGB struct - holds RGB values
struct RGB {
	int r; //the red component
	int g; //the green component
	int b; //the blue component
};

//class declaration
class MsgBoxColorScheme final {
	//public fields and methods
	public:
		//constructor
		MsgBoxColorScheme(unsigned newBG, unsigned newText, unsigned newBBorder, unsigned newBBG, unsigned newSelect);

		//destructor
		~MsgBoxColorScheme();

		//copy constructor
		MsgBoxColorScheme(const MsgBoxColorScheme& mbcs);

		//move constructor
		MsgBoxColorScheme(MsgBoxColorScheme&& mbcs);

		//assignment operator
		MsgBoxColorScheme& operator=(const MsgBoxColorScheme& src);

		//move operator
		MsgBoxColorScheme& operator=(MsgBoxColorScheme&& src);

		//other method
		SDL_MessageBoxColorScheme toSDLData() const; //converts the color scheme to native SDL data

	//private fields and methods
	private:
		//method
		void convertHex(unsigned hex, int colorIndex); //converts a hex code to RGB and assigns it to a given color index
		//field
		std::array<RGB, 5> colors; //the color scheme data
};

#endif
