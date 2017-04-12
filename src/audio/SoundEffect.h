/*
 * SoundEffect.h
 * Declares a class that represents a sound effect
 * Created by Andrew Davis
 * Created on 4/11/2017
 * All rights reserved
 */

//disallow reinclusion
#ifndef MUS_TRACK_H
#define MUS_TRACK_H

//includes
#include <string>
#include <SDL/SDL_mixer.h>

//class declaration
class SoundEffect final {
	//public fields and methods
	public:
		//constructor 1 - constructs from a C string
		explicit SoundEffect(const char* effectName);

		//constructor 2 - constructs from a std::string
		explicit SoundEffect(const std::string& effectName);

		//destructor
		~SoundEffect();

		//copy constructor
		SoundEffect(const SoundEffect& mt);

		//move constructor
		SoundEffect(SoundEffect&& mt);

		//assignment operator
		SoundEffect& operator=(const SoundEffect& src);

		//move operator
		SoundEffect& operator=(SoundEffect&& src);

		//getter method
		const std::string& getFileName() const; //returns the filename of the music track

		//other method
		void play(int repeats = 0) const; //plays the effect

	//private fields and methods
	private:
		//method
		void free(); //deallocates the object

		//fields
		Mix_Chunk* effect; //the effect stored in the SoundEffect
		std::string name; //the filename of the music
};

#endif
