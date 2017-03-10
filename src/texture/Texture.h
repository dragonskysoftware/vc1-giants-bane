/*
 * Texture.h
 * Declares a class that acts as a parent class for all other texture subclasses
 * Created by Andrew Davis
 * Created on 3/9/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef SUP_TEXT_H
#define SUP_TEXT_H

//includes
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include "../util/functions.h"
#include <iostream>

//class declaration
class Texture {
	
	//public fields and methods
	public:
		//constructor 1 - initializes the Texture with empty fields
		Texture();

		//constructor 2 - initializes the Texture with an empty texture pointer and given width and height
		Texture(int newWidth, int newHeight);

		//destructor
		virtual ~Texture();

		//copy constructor
		Texture(const Texture& t);

		//move constructor
		Texture(Texture&& t);

		//assignment operator
		Texture& operator=(const Texture& src);

		//move operator
		Texture& operator=(Texture&& src);

		//getter methods

		int getWidth() const; //returns the Texture's width
		int getHeight() const; //returns the Texture's height

		//setter methods

		void setColor(uint8_t red, uint8_t green, uint8_t blue); //sets the color of the texture
		void setBlendMode(SDL_BlendMode blending); //sets the blend mode of the texture
		void setAlpha(uint8_t alpha); //sets the alpha modulation of the texture

		//rendering method
		void render(int xPos, int yPos, SDL_Renderer* renderer, SDL_Rect* clip = nullptr, double angle = 0.0, SDL_Point* center = nullptr, SDL_RendererFlip flip = SDL_FLIP_NONE) const;

		//abstract methods

		//loads a texture from a file
		virtual bool loadFromFile(std::string filePath, SDL_Renderer* renderer) = 0;
		//loads from text
		virtual bool loadFromText(std::string text, SDL_Color textColor, TTF_Font* textFont, SDL_Renderer* renderer) = 0;

	//protected fields and methods
	protected:
		//free method - deallocates the Texture
		void free();

		//fields
		SDL_Texture* texture; //the internal texture field
		int width; //the width of the texture
		int height; //the height of the texture

};

#endif
