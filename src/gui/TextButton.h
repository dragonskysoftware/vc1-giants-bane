/*
 * TextButton.h
 * Declares a class that represents a GUI button with text on it
 * Created by Andrew Davis
 * Created on 4/19/2017
 * All rights reserved
 */

//disallow reinclusion
#ifndef BUTTON_H_INC
#define BUTTON_H_INC

//includes
#include <SDL2/SDL.h>
#include <functional>
#include "../component/TextComponent.h"

//class declaration
class TextButton {
	//public fields and methods
	public:
		//constructor 1 - constructs from an TextComponent object and a callback function
		TextButton(const TextComponent& newText, std::function<void()> newCallback);

		//destructor
		virtual ~TextButton();

		//copy constructor
		TextButton(const TextButton& b);

		//move constructor
		TextButton(TextButton&& b);

		//assignment operator
		TextButton& operator=(const TextButton& src);

		//move operator
		TextButton& operator=(TextButton&& src);

		//getter methods
		int getX() const; //returns the x-coordinate of the TextButton
		int getY() const; //returns the y-coordinate of the TextButton
		int getWidth() const; //returns the width of the TextButton
		int getHeight() const; //returns the height of the TextButton
		
		//setter methods
		void setX(int newX); //sets the x-coordinate of the TextButton
		void setY(int newY); //sets the y-coordinate of the TextButton

		//other methods
		void render(SDL_Rect* clip = nullptr, double angle = 0.0, SDL_Point* center = nullptr, SDL_RendererFlip flip = SDL_FLIP_NONE) const; //renders the TextButton
		void processEvent(SDL_Event* event); //determines whether an event concerns this TextButton and acts on it

	//protected fields and methods
	protected:
		//private methods
		void onClick(); //executes the action for the TextButton

		//fields
		TextComponent text; //the text of the TextButton
		std::function<void()> callback; //the TextButton's callback
		int x; //the x-coordinate of the TextButton
		int y; //the y-coordinate of the TextButton
		int width; //the width of the TextButton
		int height; //the height of the TextButton
};

#endif
