/*
 * SoundEffect.cpp
 * Implements a class that represents a sound effect
 * Created by Andrew Davis
 * Created on 4/11/2017
 * All rights reserved
 */

//include header
#include "SoundEffect.h"

//constructor 1 - constructs from a C string
SoundEffect::SoundEffect(const char* trackName)
	: effect(nullptr), name(trackName) //init the fields
{
	this->effect = Mix_LoadWAV(trackName); //load the effect from the filename
	if(!this->effect) { //if the load failed
		throw InvalidSoundException(trackName, Mix_GetError()); //then throw an exception
	}
}

//constructor 2 - constructs from a std::string
SoundEffect::SoundEffect(const std::string& trackName)
	: SoundEffect(trackName.c_str()) //call the other constructor
{
	//no code needed
}

//destructor
SoundEffect::~SoundEffect() {
	this->free(); //deallocate the object
}

//copy constructor
SoundEffect::SoundEffect(const SoundEffect& mt)
	: effect(mt.effect), name(mt.name) //copy the fields
{
	//no code needed
}

//move constructor
SoundEffect::SoundEffect(SoundEffect&& mt)
	: effect(mt.effect), name(mt.name) //move the fields
{
	mt.free(); //deallocate the temporary
}

//assignment operator
SoundEffect& SoundEffect::operator=(const SoundEffect& src) {
	this->effect = src.effect; //assign the effect field
	this->name = src.name; //assign the name field
	return *this; //return the object
}

//move operator
SoundEffect& SoundEffect::operator=(SoundEffect&& src) {
	this->effect = src.effect; //move the effect field
	this->name = src.name; //move the name field
	src.free(); //deallocate the temporary
	return *this; //return the object
}

//getter method

//getFileName method - returns the filename of the SoundEffect
const std::string& SoundEffect::getFileName() const {
	return this->name; //return the name field
}

//other methods

//play method - plays the sound effect
void SoundEffect::play(int repeats) const {
	Mix_PlayChannel(-1, this->effect, repeats); //play the sound effect
}

//private free method - deallocates the object
void SoundEffect::free() {
	Mix_FreeChunk(this->effect); //deallocate the effect
	this->effect = nullptr; //and zero it out
}

//end of implementation
