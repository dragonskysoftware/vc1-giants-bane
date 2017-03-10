/*
 * Component.h
 * Declares a class that represents a game component for the Giant's Bane RPG
 * Created by Andrew Davis
 * Created on 3/9/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef COMP_H_INC
#define COMP_H_INC

//includes
#include "../texture/Texture.h"
#include "../texture/ImageTexture.h"
#include "../texture/TextTexture.h"
#include "../texture/EnumTextureType.h"
#include "../util/constants.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

//class declaration
class Component {
	//public fields and methods
	public:
		//constructor
		Component(int newXPos, int newYPos, EnumTextureType newTextureType, SDL_Renderer* newRenderer);

		//destructor
		virtual ~Component();

		//copy constructor
		Component(const Component& c);

		//move constructor
		Component(Component&& c);

		//assignment operator
		Component& operator=(const Component& src);

		//move operator
		Component& operator=(Component&& src);

		//getter methods
		int getX() const; //returns the X-coordinate of the Component
		int getY() const; //returns the Y-coordinate of the Component
		int getWidth() const; //returns the width of the Component
		int getHeight() const; //returns the height of the Component

		//setter methods

		void setX(int newX); //sets the X-coordinate of the Component
		void setY(int newY); //sets the Y-coordinate of the Component

		//sets the texture image
		bool setTextureImage(std::string imagePath);

		//sets the texture text
		bool setTextureText(std::string newText, SDL_Color textColor, TTF_Font* textFont);

		//other methods

		//renders the Component
		void render(SDL_Rect* clip = nullptr, double angle = 0.0, SDL_Point* center = nullptr, SDL_RendererFlip flip = SDL_FLIP_NONE) const;

		//PV intersects method - returns whether or not the Component intersects another Component
		virtual bool intersects(const Component& other) const = 0;


	//protected fields and methods
	protected:
		//fields
		int xPos; //the x-position of the component
		int yPos; //the y-position of the component
		Texture* texture; //the texture used to render the Component's graphics
		EnumTextureType textureType; //the texture type of the Component
		SDL_Renderer* renderer; //the renderer of the Component
};

#endif
