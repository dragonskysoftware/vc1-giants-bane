/*
 * TextTexture.cpp
 * Implements a class that represents an SDL texture with text on it
 * Created by Andrew Davis
 * Created on 3/9/2017
 * All rights reserved
 */

//include header
#include "TextTexture.h"

//constructor
TextTexture::TextTexture()
	: Texture(), storedText("") //call superclass constructor and init the text field
{
	//no code needed
}

//destructor
TextTexture::~TextTexture() {
	//no code needed, superclass handles it all
}

//copy constructor
TextTexture::TextTexture(const TextTexture& tt)
	: Texture(tt), storedText(tt.storedText) //call superclass copy constructor and copy the text field
{
	//no code needed
}

//move constructor
TextTexture::TextTexture(TextTexture&& tt)
	: Texture(tt), storedText(tt.storedText) //call superclass move constructor and move the text field
{
	//no code needed, superclass handles it all
}

//assignment operator
TextTexture& TextTexture::operator=(const TextTexture& src) {
	Texture::operator=(src); //call superclass assignment operator
	this->storedText = src.storedText; //assign the text field
	return *this; //return the object
}

//move operator
TextTexture& TextTexture::operator=(TextTexture&& src) {
	Texture::operator=(src); //call superclass move operator
	this->storedText = src.storedText; //move the text field
	return *this; //return the object
}

//other methods

//getText method - returns the text stored in the TextTexture
std::string TextTexture::getText() const {
	return this->storedText; //return the text field
}

//overridden loadFromFile method - prints out an error message and returns false
bool TextTexture::loadFromFile(std::string filePath, SDL_Renderer* renderer) {
	std::cerr << "Warning: This method (TextTexture::loadFromFile()) is not implemented for this type." << std::endl;
	return false; //return with an error
}

//overridden loadFromText method - loads text into the TextTexture
bool TextTexture::loadFromText(std::string text, SDL_Color textColor, TTF_Font* textFont, SDL_Renderer* renderer) {
	this->free(); //delete any existing texture

	//assign the text field
	this->storedText = text;

	//render the text surface
	SDL_Surface* textSurface = TTF_RenderText_Solid(textFont, text.c_str(), textColor); //get the text as a surface
	if(textSurface == nullptr) { //if the rendering failed
		std::cerr << "Unable to render text surface. Error: " << TTF_GetError() << std::endl; //display an error message
	} else {
		this->texture = SDL_CreateTextureFromSurface(renderer, textSurface); //convert the surface to a texture
		if(this->texture == nullptr) { //if the conversion failed
			std::cerr << "Unable to convert surface to texture. Error: " << SDL_GetError() << std::endl;
		} else {
			this->width = textSurface->w; //assign the width field
			this->height = textSurface->h; //assign the height field
		}
		//deallocate the old surface
		SDL_FreeSurface(textSurface); 
	}

	//return a success flag
	return this->texture != nullptr;
}

//end of implementation

