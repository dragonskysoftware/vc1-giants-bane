/*
 * ImgComponent.cpp
 * Implements a class that represents a component with an image
 * Created by Andrew Davis
 * Created on 3/9/2017
 * Open source (GPL license)
 */

//include header
#include "ImgComponent.h"

//first constructor - creates an ImgComponent with no texture but defined coordinates
ImgComponent::ImgComponent(int newX, int newY, SDL_Renderer* newRenderer)
	: Component(newX, newY, EnumTextureType::IMG, newRenderer) //call the superconstructor
{
	//no code needed
}

//second constructor - creates an ImgComponent with both a texture and coordinates
ImgComponent::ImgComponent(int newX, int newY, std::string pathToImage, SDL_Renderer* newRenderer)
	: Component(newX, newY, EnumTextureType::IMG, newRenderer) //call the superconstructor
{
	this->setTextureImage(pathToImage); //init the texture image
}

//destructor
ImgComponent::~ImgComponent() {
	//no code needed - superclass takes care of it all
}

//copy constructor
ImgComponent::ImgComponent(const ImgComponent& ic)
	: Component(ic) //call the superclass copy constructor
{
	this->setTextureImage(ic.getImagePath()); //set the texture image using the path from the other ImgComponent
}

//move constructor
ImgComponent::ImgComponent(ImgComponent&& ic)
	: Component(ic) //call the superclass move constructor
{
	this->setTextureImage(ic.getImagePath()); //set the texture image using the path from the other ImgComponent
}

//assignment operator
ImgComponent& ImgComponent::operator=(const ImgComponent& src) {
	Component::operator=(src); //call superclass assignment operator
	this->setTextureImage(src.getImagePath()); //set the texture image using the path from the other ImgComponent
	return *this; //return the object
}

//move operator
ImgComponent& ImgComponent::operator=(ImgComponent&& src) {
	Component::operator=(src); //call superclass move operator
	this->setTextureImage(src.getImagePath()); //set the texture image using the path from the other ImgComponent
	return *this; //return the object
}

//getter method

//getImagePath method - returns the path to the image stored in the ImgComponent
std::string ImgComponent::getImagePath() const {
	ImageTexture* tex = dynamic_cast<ImageTexture*>(this->texture); //cast the texture field to an ImageTexture
	return tex->getPath(); //return a call to ImageTexture::getPath()
}

//overridden PV methods

//intersects method - returns whether or not the ImgComponent intersects with another component
bool ImgComponent::intersects(const Component& other) const {
	SDL_Rect thisRect = {this->xPos, this->yPos, this->getWidth(), this->getHeight()}; //init the rectangle for this Component
	SDL_Rect otherRect = {other.getX(), other.getY(), other.getWidth(), other.getHeight()}; //get the rectangle for the other
	SDL_Rect intersect; //will hold the details of the intersection
	SDL_bool result = SDL_IntersectRect(&thisRect, &otherRect, &intersect); //calculate the intersection and return the result
	bool bResult = (result == SDL_TRUE ? true : false); //convert the SDL_bool value to an actual bool value
	return bResult && other.intersects(*this); //return whether or not both objects register an intersection
}

//end of implementation
