/*
 * ImageTexture.cpp
 * Implements a class that stores an image as a texture
 * Created by Andrew Davis
 * Created on 3/9/2017
 * Open source (GPL license)
 */

//include header
#include "ImageTexture.h"

//constructor
ImageTexture::ImageTexture()
	: Texture(), path("") //call superclass constructor and init the path field
{
	//no code needed
}

//destructor
ImageTexture::~ImageTexture() {
	//no code needed - superclass handles it all
}

//copy constructor
ImageTexture::ImageTexture(const ImageTexture& it)
	: Texture(it), path(it.path) //call the superclass copy constructor and copy the path field
{
	//no code needed
}

//move constructor
ImageTexture::ImageTexture(ImageTexture&& it)
	: Texture(it), path(it.path) //call the superclass move constructor and move the path field
{
	//no code needed - superclass handles it all
}

//assignment operator
ImageTexture& ImageTexture::operator=(const ImageTexture& src) {
	Texture::operator=(src); //call superclass assignment operator
	this->path = src.path; //assign the path field
	return *this; //and return the object
}

//move operator
ImageTexture& ImageTexture::operator=(ImageTexture&& src) {
	Texture::operator=(src); //call superclass move operator
	this->path = src.path; //move the path field
	return *this; //and return the object
}

//getPath method - returns the path to the image stored in the ImageTexture
std::string ImageTexture::getPath() const {
	return this->path; //return the path field
}

//overridden PV methods

//loadFromFile method - loads an image from a file into the ImageTexture
bool ImageTexture::loadFromFile(std::string filePath, SDL_Renderer* renderer) {
	this->free(); //delete any pre-existing texture

	//assign the path field
	this->path = filePath;

	//declare the final texture
	SDL_Texture* finalTexture = nullptr;

	//get a surface from the file
	SDL_Surface* loadedSurface = IMG_Load(filePath.c_str()); //load the image from the file

	//verify the surface
	if(loadedSurface == nullptr) { //if the image was loaded improperly
		std::cerr << "Unable to load image " << filePath << ". Error: " << IMG_GetError() << std::endl; //error message
	} else {
		//color key the surface
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0xff, 0xff, 0xff));
		//get the texture from the surface
		finalTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface); //render the texture
		//verify the texture
		if(finalTexture == nullptr) { //if the texture was rendered improperly
			//then display an error message
			std::cerr << "Unable to render texture " << filePath << ". Error: " << SDL_GetError() << std::endl;
		} else {
			//assign the dimensions of the ImageTexture
			this->width = loadedSurface->w; //assign the width field
			this->height = loadedSurface->h; //assign the height field
		}
		//Get rid of the loaded surface
		SDL_FreeSurface(loadedSurface);
	}
	this->texture = finalTexture; //assign the texture field
	return this->texture != nullptr; //return a success flag
}

//loadFromText method - prints out an error message and returns false
bool ImageTexture::loadFromText(std::string text, SDL_Color textColor, TTF_Font* textFont, SDL_Renderer* renderer) {
	//print an error message
	std::cerr << "Warning: This method (ImageTexture::loadFromText()) is not implemented for this type." << std::endl;
	//and return false
	return false;
}

//end of implementation
