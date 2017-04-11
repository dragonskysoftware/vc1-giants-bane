/*
 * TextTexture.h
 * Declares a class that represents an SDL texture with text on it
 * Created by Andrew Davis
 * Created on 3/9/2017
 * All rights reserved
 */

//disallow reinclusion
#ifndef TEXT_TEXTURE_H
#define TEXT_TEXTURE_H

//includes
#include "Texture.h" //include parent class
#include <iostream>
#include <string>

//class declaration
class TextTexture : public Texture 
{
	//public fields and methods
	public:
		//constructor
		TextTexture();

		//destructor
		virtual ~TextTexture();

		//copy constructor
		TextTexture(const TextTexture& tt);

		//move constructor
		TextTexture(TextTexture&& tt);

		//assignment operator
		TextTexture& operator=(const TextTexture& src);

		//move operator
		TextTexture& operator=(TextTexture&& src);

		//getter method
		std::string getText() const; //returns the text on the TextTexture

		//overridden PV methods
		//prints an error message and returns false
		bool loadFromFile(std::string filePath, SDL_Renderer* renderer) override; 
		//loads text into the TextTexture
		bool loadFromText(std::string text, SDL_Color textColor, TTF_Font* textFont, SDL_Renderer* renderer) override;

	//protected fields and methods
	protected:
		//fields
		std::string storedText; //the text stored on the TextTexture
};

#endif
