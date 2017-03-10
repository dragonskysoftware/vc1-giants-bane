/*
 * ImageTexture.h
 * Declares a class that stores an image as a texture
 * Created by Andrew Davis
 * Created on 3/9/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef IMAGE_TEX_H
#define IMAGE_TEX_H

//includes
#include "Texture.h" //include parent class
#include <iostream>
#include <string>

//class declaration
class ImageTexture : public Texture
{
	//public fields and methods
	public:
		//constructor
		ImageTexture();

		//destructor
		virtual ~ImageTexture();

		//copy constructor
		ImageTexture(const ImageTexture& it);

		//move constructor
		ImageTexture(ImageTexture&& it);

		//assignment operator
		ImageTexture& operator=(const ImageTexture& src);

		//move operator
		ImageTexture& operator=(ImageTexture&& src);

		//getter method
		std::string getPath() const; //returns the path to the stored image file

		//overridden PV methods

		//this method loads an image from a file into the ImageTexture
		bool loadFromFile(std::string filePath, SDL_Renderer* renderer) override;

		//this method prints an error message and returns false
		bool loadFromText(std::string text, SDL_Color textColor, TTF_Font* textFont, SDL_Renderer* renderer) override;
	
	//protected fields and methods
	protected:
		//field
		std::string path; //the path to the stored image file
};

#endif
