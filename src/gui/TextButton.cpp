/*
 * TextButton.cpp
 * Implements a class that represents a GUI button with text on it
 * Created by Andrew Davis
 * Created on 4/19/2017
 * All rights reserved
 */

//include header
#include "TextButton.h"

//constructor 1 - constructs from an TextComponent object and a callback function
TextButton::TextButton(const TextComponent& newText, std::function<void()> newCallback)
	: text(newText), callback(newCallback), x(0), y(0), width(0), height(0) //init the fields
{
	this->x = this->text.getX(); //assign the x-coordinate field
	this->y = this->text.getY(); //assign the y-coordinate field
	this->width = this->text.getWidth(); //assign the width field
	this->height = this->text.getHeight(); //assign the height field
}

//destructor
TextButton::~TextButton() {
	//no code needed
}

//copy constructor
TextButton::TextButton(const TextButton& b)
	: text(b.text), callback(b.callback), x(b.x), y(b.y), width(b.width), height(b.height) //copy the fields
{
	//no code needed
}

//move constructor
TextButton::TextButton(TextButton&& b)
	: text(b.text), callback(b.callback), x(b.x), y(b.y), width(b.width), height(b.height) //move the fields
{
	//no code needed
}

//assignment operator
TextButton& TextButton::operator=(const TextButton& src) {
	this->text = src.text; //assign the text
	this->callback = src.callback; //assign the callback
	this->x = src.x; //assign the x-coordinate
	this->y = src.y; //assign the y-coordinate
	this->width = src.width; //assign the width
	this->height = src.height; //assign the height
	return *this; //return the object
}

//move operator
TextButton& TextButton::operator=(TextButton&& src) {
	this->text = src.text; //move the text
	this->callback = src.callback; //move the callback
	this->x = src.x; //move the x-coordinate
	this->y = src.y; //move the y-coordinate
	this->width = src.width; //move the width
	this->height = src.height; //move the height
	return *this; //return the object
}

//getter methods

//getX method - returns the X-coordinate of the TextButton
int TextButton::getX() const {
	return this->text.getX(); //return the x-coordinate of the TextButton's text
}

//getY method - returns the Y-coordinate of the TextButton
int TextButton::getY() const {
	return this->text.getY(); //return the y-coordinate of the TextButton's text
}

//getWidth method - returns the width of the TextButton
int TextButton::getWidth() const {
	return this->text.getWidth(); //return the width of the TextButton's text
}

//getHeight method - returns the height of the TextButton
int TextButton::getHeight() const {
	return this->text.getHeight(); //return the height of the TextButton's text
}

//setter methods

//setX method - sets the X-coordinate of the TextButton
void TextButton::setX(int newX) {
	this->text.setX(newX); //set the x-coordinate of the TextButton's text
	this->x = newX; //assign the new x-coordinate field
}

//setY method - sets the Y-coordinate of the TextButton
void TextButton::setY(int newY) {
	this->text.setY(newY); //set the y-coordinate of the TextButton's text
	this->y = newY; //assign the new y-coordinate field
}

//other methods

//render method - renders the TextButton
void TextButton::render(SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip) const
{
	this->text.render(clip, angle, center, flip); //render the TextButton's text
}

//processEvent method - processes an SDL_Event, checks if it pertains to the TextButton, and if so, executes the TextButton's callback
void TextButton::processEvent(SDL_Event* event) {
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

//private onClick method - calls the callback for the TextButton
void TextButton::onClick() {
	this->callback(); //execute the callback
}

//end of implementation
