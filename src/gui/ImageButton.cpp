/*
 * ImageButton.cpp
 * Implements a class that represents a GUI button with an image on it
 * Created by Andrew Davis
 * Created on 4/19/2017
 * All rights reserved
 */

//include header
#include "ImageButton.h"

//constructor 1 - constructs from an ImgComponent object and a callback function
ImageButton::ImageButton(const ImgComponent& newImage, std::function<void()> newCallback)
	: image(newImage), callback(newCallback), x(0), y(0), width(0), height(0) //init the fields
{
	this->x = this->image.getX(); //assign the x-coordinate field
	this->y = this->image.getY(); //assign the y-coordinate field
	this->width = this->image.getWidth(); //assign the width field
	this->height = this->image.getHeight(); //assign the height field
}

//destructor
ImageButton::~ImageButton() {
	//no code needed
}

//copy constructor
ImageButton::ImageButton(const ImageButton& b)
	: image(b.image), callback(b.callback), x(b.x), y(b.y), width(b.width), height(b.height) //copy the fields
{
	//no code needed
}

//move constructor
ImageButton::ImageButton(ImageButton&& b)
	: image(b.image), callback(b.callback), x(b.x), y(b.y), width(b.width), height(b.height) //move the fields
{
	//no code needed
}

//assignment operator
ImageButton& ImageButton::operator=(const ImageButton& src) {
	this->image = src.image; //assign the image
	this->callback = src.callback; //assign the callback
	this->x = src.x; //assign the x-coordinate
	this->y = src.y; //assign the y-coordinate
	this->width = src.width; //assign the width
	this->height = src.height; //assign the height
	return *this; //return the object
}

//move operator
ImageButton& ImageButton::operator=(ImageButton&& src) {
	this->image = src.image; //move the image
	this->callback = src.callback; //move the callback
	this->x = src.x; //move the x-coordinate
	this->y = src.y; //move the y-coordinate
	this->width = src.width; //move the width
	this->height = src.height; //move the height
	return *this; //return the object
}

//getter methods

//getX method - returns the X-coordinate of the ImageButton
int ImageButton::getX() const {
	return this->image.getX(); //return the x-coordinate of the ImageButton's image
}

//getY method - returns the Y-coordinate of the ImageButton
int ImageButton::getY() const {
	return this->image.getY(); //return the y-coordinate of the ImageButton's image
}

//getWidth method - returns the width of the ImageButton
int ImageButton::getWidth() const {
	return this->image.getWidth(); //return the width of the ImageButton's image
}

//getHeight method - returns the height of the ImageButton
int ImageButton::getHeight() const {
	return this->image.getHeight(); //return the height of the ImageButton's image
}

//setter methods

//setX method - sets the X-coordinate of the ImageButton
void ImageButton::setX(int newX) {
	this->image.setX(newX); //set the x-coordinate of the ImageButton's image
	this->x = newX; //assign the new x-coordinate field
}

//setY method - sets the Y-coordinate of the ImageButton
void ImageButton::setY(int newY) {
	this->image.setY(newY); //set the y-coordinate of the ImageButton's image
	this->y = newY; //assign the new y-coordinate field
}

//other methods

//render method - renders the ImageButton
void ImageButton::render(SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip) const
{
	this->image.render(clip, angle, center, flip); //render the ImageButton's image
}

//processEvent method - processes an SDL_Event, checks if it pertains to the ImageButton, and if so, executes the ImageButton's callback
void ImageButton::processEvent(SDL_Event* event) {
	//verify the event type
	if(event->type != SDL_MOUSEBUTTONDOWN) { //if the event is the wrong event type
		return; //then exit the method
	}
	
	//get the coordinates of the mouse click
	int cx, cy; //the coordinates of the mouse click
	SDL_GetMouseState(&cx, &cy); //get the click coordinates

	//determine if the click was inside the button
	bool inside = true; //is the mouse inside the button?

	if(cx < this->x) { //if the mouse click was left of the button
		inside = false; //then reset the inside flag
	} else if(cx > (this->x + this->width)) { //if the mouse click was right of the button
		inside = false; //then reset the inside flag
	} else if(cy < this->y) { //if the mouse click was above the button
		inside = false; //then reset the inside flag
	} else if(cy > (this->y + this->height)) { //if the mouse click was below the button
		inside = false; //then reset the inside flag
	}
	
	if(inside) { //if the inside flag is set
		this->onClick(); //then call the click event handler
	}
}

//private onClick method - calls the callback for the ImageButton
void ImageButton::onClick() {
	this->callback(); //execute the callback
}

//end of implementation
