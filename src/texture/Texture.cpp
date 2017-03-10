/*
 * Texture.cpp
 * Implements a class that acts as a parent class for all other texture subclasses
 * Created by Andrew Davis
 * Created on 3/9/2017
 * Open source (GPL license)
 */

//include header
#include "Texture.h"

//first constructor - initializes the Texture with empty fields
Texture::Texture()
	: texture(nullptr), width(0), height(0) //init the fields with null values
{
	//no code needed
}

//second constructor - initializes the Texture with an empty texture pointer and given width and height
Texture::Texture(int newWidth, int newHeight)
	: texture(nullptr), width(newWidth), height(newHeight) //init the fields
{
	//no code needed
}

//destructor
Texture::~Texture() {
	this->free(); //deallocate the object
}

//copy constructor
Texture::Texture(const Texture& t)
	: texture(nullptr), width(t.width), height(t.height) //copy the size fields and null the texture field
{
	if(t.texture != nullptr) { //if the other texture isn't null
		this->texture = t.texture; //then assign it to this texture
	}
}

//move constructor
Texture::Texture(Texture&& t)
	: texture(nullptr), width(t.width), height(t.height) //move the size fields and null the texture field
{
	if(t.texture != nullptr) { //if the temporary's texture isn't null
		this->texture = t.texture; //then assign it to this texture
	}
	t.free(); //free the temporary object
}

//assignment operator
Texture& Texture::operator=(const Texture& src) {
	this->texture = src.texture; //assign the texture field
	this->width = src.width; //assign the width field
	this->height = src.height; //assign the height field
	return *this; //return the object
}

//move operator
Texture& Texture::operator=(Texture&& src) {
	this->texture = src.texture; //move the texture field
	this->width = src.width; //move the width field
	this->height = src.height; //move the height field
	src.free(); //free the temporary object
	return *this; //return the object
}

//getter methods

//getWidth method - returns the width of the texture
int Texture::getWidth() const {
	return this->width; //return the width field
}

//getHeight method - returns the height of the texture
int Texture::getHeight() const {
	return this->height; //return the height field
}

//setter methods

//setColor method - sets the color of the Texture
void Texture::setColor(uint8_t red, uint8_t green, uint8_t blue) {
	SDL_SetTextureColorMod(this->texture, red, green, blue); //set the texture color modulation
}

//setBlendMode method - sets the blending mode of the Texture
void Texture::setBlendMode(SDL_BlendMode blending) {
	SDL_SetTextureBlendMode(this->texture, blending); //set the texture blend mode
}

//setAlpha method - sets the alpha of the Texture
void Texture::setAlpha(uint8_t alpha) {
	SDL_SetTextureAlphaMod(this->texture, alpha); //set the texture alpha modulation
}

//other methods

//render method - renders the Texture
void Texture::render(int xPos, int yPos, SDL_Renderer* renderer, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip) const {

	//get the rendering rectangle
	SDL_Rect renderRect = { xPos, yPos, this->width, this->height };

	//get the clip information
	if(clip != nullptr) {
		renderRect.w = clip->w; //assign the width
		renderRect.h = clip->h; //assign the height
	}

	//render the texture
	SDL_RenderCopyEx(renderer, this->texture, clip, &renderRect, angle, center, flip);
}

//protected free method - deallocates a Texture
void Texture::free() {
	if(this->texture != nullptr) { //if the texture exists
		SDL_DestroyTexture(this->texture); //destroy it
		this->texture = nullptr; //zero it
		this->width = 0; //zero the width
		this->height = 0; //zero the height
	}
}

//end of implementation
