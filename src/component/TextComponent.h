/*
 * TextComponent.h
 * Declares a class that acts as a game component that holds text
 * Created by Andrew Davis
 * Created on 3/9/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef TEXT_COMP_H_INC
#define TEXT_COMP_H_INC

//includes
#include "../texture/EnumTextureType.h"
#include "Component.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>

//class declaration
class TextComponent : public Component
{
	//public fields and methods
	public:
		//first constructor - creates an empty TextComponent with black color, but an initialized font
		TextComponent(int x, int y, std::string pathToFont, int fontSize, SDL_Renderer* renderer);

		//second constructor - creates a TextComponent with text, font, and color specified by its parts
		TextComponent(int x, int y, std::string newText, std::string pathToFont, int fontSize, uint8_t r, uint8_t g, uint8_t b, SDL_Renderer* renderer);

		//third constructor - creates a TextComponent with text, font, and color specified by a SDL_Color instance
		TextComponent(int x, int y, std::string newText, std::string pathToFont, int fontSize, SDL_Color newColor, SDL_Renderer* renderer);

		//destructor
		virtual ~TextComponent();

		//copy constructor
		TextComponent(const TextComponent& tc);

		//move constructor
		TextComponent(TextComponent&& tc);

		//assignment operator
		TextComponent& operator=(const TextComponent& src);

		//move operator
		TextComponent& operator=(TextComponent&& src);

		//getter method
		std::string getText() const; //returns the string stored in the texture

		//other methods

		//overridden PV method that checks if the TextComponent intersects with another component
		virtual bool intersects(const Component& other) const override; 
	
	//protected fields and methods
	protected:
		//fields
		TTF_Font* font;
		SDL_Color color;

};

#endif
