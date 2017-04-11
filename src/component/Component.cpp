/*
 * Component.cpp
 * Implements a class that represents a game component for the Giant's Bane RPG
 * Created by Andrew Davis
 * Created on 3/9/2017
 * All rights reserved
 */

//include header
#include "Component.h"

//constructor
Component::Component(int newXPos, int newYPos, EnumTextureType newTextureType, SDL_Renderer* newRenderer)
	: xPos(newXPos), yPos(newYPos), texture(nullptr), textureType(newTextureType), renderer(nullptr) //init the fields
{
	//decide what kind of texture to create
	if(this->textureType == EnumTextureType::IMG) { //if the component is an image
		this->texture = new ImageTexture(); //init the texture field with an image texture
	} else { //if it's a text graphic
		this->texture = new TextTexture(); //init the texture field with a text texture
	}
	this->renderer = newRenderer; //init the renderer
}

//destructor
Component::~Component() {
	delete this->texture; //deallocate the texture field
	this->texture = nullptr; //and zero it out
}

//copy constructor
Component::Component(const Component& c)
	: xPos(c.xPos), yPos(c.yPos), texture(nullptr), textureType(c.textureType), renderer(nullptr) //copy fields
{	
	if(c.texture) { //if the other texture isn't null
		if(c.textureType == EnumTextureType::IMG) { //if the other component is an image
			ImageTexture* newImg = dynamic_cast<ImageTexture*>(c.texture); //cast the parent texture into an ImageTex
			this->texture = new ImageTexture(*newImg); //then copy the cast ImageTexture
		} else { //if it's text
			TextTexture* newText = dynamic_cast<TextTexture*>(c.texture); //cast the parent texture into a TextTexture
			this->texture = new TextTexture(*newText); //copy the cast text texture
		}
	}
	if(c.renderer) { //if the other renderer isn't null
		this->renderer = c.renderer; //copy it
	}
}

//move constructor
Component::Component(Component&& c)
	: xPos(c.xPos), yPos(c.yPos), texture(nullptr), textureType(c.textureType), renderer(nullptr) //move fields
{
	if(c.texture) { //if the other texture isn't null
		if(c.textureType == EnumTextureType::IMG) { //if the other component is an image
			ImageTexture* newImg = dynamic_cast<ImageTexture*>(c.texture); //cast the parent texture into an ImageTex
			this->texture = new ImageTexture(*newImg); //then move the cast ImageTexture
		} else { //if it's text
			TextTexture* newText = dynamic_cast<TextTexture*>(c.texture); //cast the parent texture into a TextTexture
			this->texture = new TextTexture(*newText); //move the cast text texture
		}
	}
	if(c.renderer) { //if the other renderer isn't null
		this->renderer = c.renderer; //move it
	}
	delete c.texture; //deallocate the temporary's texture field
	c.texture = nullptr; //and zero it out
}

//assignment operator
Component& Component::operator=(const Component& src) {
	this->xPos = src.xPos; //assign the x position
	this->yPos = src.yPos; //assign the y position
	this->textureType = src.textureType; //assign the texture type field
	this->renderer = src.renderer; //assign the renderer field
	if(src.texture) { //if the other texture isn't null
		delete this->texture; //delete this texture
		this->texture = nullptr; //zero it out
		if(src.textureType == EnumTextureType::IMG) { //if the other component is an image
			ImageTexture* newImg = dynamic_cast<ImageTexture*>(src.texture); //cast the parent texture into an ImageTex
			this->texture = new ImageTexture(*newImg); //then assign the cast ImageTexture
		} else { //if it's text
			TextTexture* newText = dynamic_cast<TextTexture*>(src.texture); //cast the parent texture into a TextTex
			this->texture = new TextTexture(*newText); //assign the cast text texture
		}
	}
	return *this; //return the object
}

//move operator
Component& Component::operator=(Component&& src) {
	this->xPos = src.xPos; //move the x position
	this->yPos = src.yPos; //move the y position
	this->textureType = src.textureType; //move the texture type field
	this->renderer = src.renderer; //move the renderer field
	if(src.texture) { //if the other texture isn't null
		delete this->texture; //delete this texture
		this->texture = nullptr; //zero it out
		if(src.textureType == EnumTextureType::IMG) { //if the other component is an image
			ImageTexture* newImg = dynamic_cast<ImageTexture*>(src.texture); //cast the parent texture into an ImageTex
			this->texture = new ImageTexture(*newImg); //then move the cast ImageTexture
		} else { //if it's text
			TextTexture* newText = dynamic_cast<TextTexture*>(src.texture); //cast the parent texture into a TextTex
			this->texture = new TextTexture(*newText); //move the cast text texture
		}
	}
	delete src.texture; //delete the temporary's texture
	src.texture = nullptr; //and zero it out
	return *this; //return the object
}

//getter methods

//getX method - returns the x-coordinate of the Component
int Component::getX() const {
	return this->xPos; //return the x position
}

//getY method - returns the y-coordinate of the Component
int Component::getY() const {
	return this->yPos; //return the y position
}

//getWidth method - returns the width of the Component
int Component::getWidth() const {
	return this->texture->getWidth(); //return the width of the texture
}

//getHeight method - returns the height of the Component
int Component::getHeight() const {
	return this->texture->getHeight(); //return the height of the texture
}

//setter methods

//setX method - sets the X-coordinate of the Component
void Component::setX(int newX) {
	if(newX >= 0 && newX < SCREEN_WIDTH) { //if the x-coordinate is valid
		this->xPos = newX; //then assign the new X position of the Component
	}
}

//setY method - sets the Y-coordinate of the Component
void Component::setY(int newY) {
	if(newY >= 0 && newY < SCREEN_HEIGHT) { //if the y-coordinate is valid
		this->yPos = newY; //then assign the new Y position of the Component
	}
}

//setTextureImage method - sets the texture image of the encapsulated ImageTexture object, that is, if it's an ImageTexture
bool Component::setTextureImage(std::string imagePath) {
	return this->texture->loadFromFile(imagePath, this->renderer); //load the texture image from a file
}

//setTextureText method - sets the texture text of the encapsulated TextTexture object if it's a TextTexture
bool Component::setTextureText(std::string newText, SDL_Color textColor, TTF_Font* textFont) {
	return this->texture->loadFromText(newText, textColor, textFont, this->renderer); //load the texture image from text
}

//texture interface methods

//setColor method - sets the color of the texture
void Component::setColor(uint8_t red, uint8_t green, uint8_t blue) {
	this->texture->setColor(red, green, blue); //set the texture's color
}

//setBlendMode method - sets the blend mode of the texture
void Component::setBlendMode(SDL_BlendMode blending) {
	this->texture->setBlendMode(blending); //set the blend mode
}

//setAlpha method - sets the alpha modulation of the texture
void Component::setAlpha(uint8_t alpha) {
	this->texture->setAlpha(alpha); //set the alpha
}


//other method

//render method - renders the Component
void Component::render(SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip) const {
	this->texture->render(this->xPos, this->yPos, this->renderer, clip, angle, center, flip); //render the texture
}

//end of implementation
