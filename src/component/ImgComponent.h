/*
 * ImgComponent.h
 * Declares a class that represents a component with an image
 * Created by Andrew Davis
 * Created on 3/9/2017
 * All rights reserved
 */

//disallow reinclusion
#ifndef IMG_COMP_H_INC
#define IMG_COMP_H_INC

//includes
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <string>
#include "Component.h"
#include "../texture/Texture.h"
#include "../texture/ImageTexture.h"
#include "../texture/EnumTextureType.h"

//class declaration
class ImgComponent : public Component
{
	//public fields and methods
	public:
		//first constructor - initializes the ImgComponent with an empty texture
		ImgComponent(int newX, int newY, SDL_Renderer* newRenderer);

		//second constructor - initializes the ImgComponent with a defined texture
		ImgComponent(int newX, int newY, std::string pathToImage, SDL_Renderer* newRenderer);

		//destructor
		virtual ~ImgComponent();

		//copy constructor
		ImgComponent(const ImgComponent& ic);

		//move constructor
		ImgComponent(ImgComponent&& ic);

		//assignment operator
		ImgComponent& operator=(const ImgComponent& src);

		//move operator
		ImgComponent& operator=(ImgComponent&& src);

		//getter method
		std::string getImagePath() const; //returns the path to the image stored in the ImgComponent's texture

		//overridden PV method
		virtual bool intersects(const Component& other) const override;
	
	//no protected fields or methods
};

#endif
