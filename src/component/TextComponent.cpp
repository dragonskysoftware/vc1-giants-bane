/*
 * TextComponent.cpp
 * Implements a class that acts as a game component that holds text
 * Created by Andrew Davis
 * Created on 3/9/2017
 * All rights reserved
 */

//include header
#include "TextComponent.h"

//constructor 1 - creates a TextComponent with black text and no color but an initialized font
TextComponent::TextComponent(int x, int y, std::string pathToFont, int fontSize, SDL_Renderer* renderer)
	: Component(x, y, EnumTextureType::TEXT, renderer), font(nullptr), color() //call superconstructor and init the fields
{
	this->font = TTF_OpenFont(pathToFont.c_str(), fontSize); //init the font
	this->color = {0, 0, 0}; //init the color
}

//constructor 2 - creates a TextComponent with specified text and specified color
TextComponent::TextComponent(int x, int y, std::string newText, std::string pathToFont, int fontSize, uint8_t r, uint8_t g, uint8_t b, SDL_Renderer* renderer)
	: Component(x, y, EnumTextureType::TEXT, renderer), font(nullptr), color() //call superconstructor and init the fields
{
	this->font = TTF_OpenFont(pathToFont.c_str(), fontSize); //init the font
	this->color = {r, g, b}; //init the color
	this->setTextureText(newText, this->color, this->font); //set the text on the TextComponent's texture
}

//constructor 3 - creates a TextComponent with specified text and specified color using an SDL_Color instance
TextComponent::TextComponent(int x, int y, std::string newText, std::string pathToFont, int fontSize, SDL_Color newColor, SDL_Renderer* renderer) 
	: Component(x, y, EnumTextureType::TEXT, renderer), font(nullptr), color(newColor) //call superconstructor and init fields
{
	this->font = TTF_OpenFont(pathToFont.c_str(), fontSize); //init the font
	this->setTextureText(newText, this->color, this->font); //set the text on the TextComponent's texture
}

//destructor
TextComponent::~TextComponent() {
	TTF_CloseFont(this->font); //deallocate the font
	this->font = nullptr; //and zero it out
}

//copy constructor
TextComponent::TextComponent(const TextComponent& tc)
	: Component(tc), font(nullptr), color(tc.color) //copy the fields
{
	this->font = tc.font; //copy the font
	this->setTextureText(tc.getText(), this->color, this->font); //and set the text
}

//move constructor
TextComponent::TextComponent(TextComponent&& tc)
	: Component(tc), font(nullptr), color(tc.color) //copy the fields
{
	this->font = tc.font; //copy the font
	this->setTextureText(tc.getText(), this->color, this->font); //and set the text
	TTF_CloseFont(tc.font); //deallocate the temporary's font
	tc.font = nullptr; //and zero it out
	//the superclass handles the deallocation of the temporary's texture
}

//assignment operator
TextComponent& TextComponent::operator=(const TextComponent& src) {
	Component::operator=(src); //call the superclass assigment operator
	this->font = src.font; //assign the font
	this->color = src.color; //assign the color
	this->setTextureText(src.getText(), this->color, this->font); //set the texture text
	return *this; //and return the object
}

//move operator
TextComponent& TextComponent::operator=(TextComponent&& src) {
	Component::operator=(src); //call the superclass move operator
	this->font = src.font; //move the font
	this->color = src.color; //move the color
	this->setTextureText(src.getText(), this->color, this->font); //set the texture text
	TTF_CloseFont(src.font); //deallocate the temporary's font
	src.font = nullptr; //and zero it out
	//superclass deallocates the temporary's texture
	return *this; //and return the object
}

//getter method

//getText method - returns the text of the TextComponent
std::string TextComponent::getText() const {
	TextTexture* text = dynamic_cast<TextTexture*>(this->texture); //cast the Texture to a TextTexture
	return text->getText(); //return a call to TextTexture::getText()
}

//other methods

//overridden PV intersects method - returns whether or not the TextComponent intersects with another Component
bool TextComponent::intersects(const Component& other) const {
	return false; //TextComponents never intersect with anything
}

//end of implementation
