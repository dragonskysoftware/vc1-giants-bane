/*
 * ImageButton.h
 * Declares a class that represents a GUI button with an image on it
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
#include "../component/ImgComponent.h"

//class declaration
class ImageButton {
	//public fields and methods
	public:
		//constructor 1 - constructs from an ImgComponent object and a callback function
		ImageButton(const ImgComponent& newImage, std::function<void()> newCallback);

		//destructor
		virtual ~ImageButton();

		//copy constructor
		ImageButton(const ImageButton& b);

		//move constructor
		ImageButton(ImageButton&& b);

		//assignment operator
		ImageButton& operator=(const ImageButton& src);

		//move operator
		ImageButton& operator=(ImageButton&& src);

		//getter methods
		int getX() const; //returns the x-coordinate of the ImageButton
		int getY() const; //returns the y-coordinate of the ImageButton
		int getWidth() const; //returns the width of the ImageButton
		int getHeight() const; //returns the height of the ImageButton
		
		//setter methods
		void setX(int newX); //sets the x-coordinate of the ImageButton
		void setY(int newY); //sets the y-coordinate of the ImageButton

		//other methods
		void render(SDL_Rect* clip = nullptr, double angle = 0.0, SDL_Point* center = nullptr, SDL_RendererFlip flip = SDL_FLIP_NONE) const; //renders the ImageButton
		void processEvent(SDL_Event* event); //determines whether an event concerns this ImageButton and acts on it

	//protected fields and methods
	protected:
		//private methods
		void onClick(); //executes the action for the ImageButton

		//fields
		ImgComponent image; //the image of the ImageButton
		std::function<void()> callback; //the ImageButton's callback
		int x; //the x-coordinate of the ImageButton
		int y; //the y-coordinate of the ImageButton
		int width; //the width of the ImageButton
		int height; //the height of the ImageButton
};

#endif
