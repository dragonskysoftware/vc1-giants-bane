/*
 * MusicTrack.cpp
 * Implements a class that represents a track of music
 * Created by Andrew Davis
 * Created on 4/11/2017
 * All rights reserved
 */

//include header
#include "MusicTrack.h"

//constructor 1 - constructs from a C string
MusicTrack::MusicTrack(const char* trackName)
	: music(nullptr), name(trackName) //init the fields
{
	this->music = Mix_LoadMUS(trackName); //load the music from the filename
	if(!this->music) { //if the load failed
		throw InvalidSoundException(trackName, Mix_GetError()); //then throw an exception
	}
}

//constructor 2 - constructs from a std::string
MusicTrack::MusicTrack(const std::string& trackName)
	: MusicTrack(trackName.c_str()) //call the other constructor
{
	//no code needed
}

//destructor
MusicTrack::~MusicTrack() {
	this->free(); //deallocate the object
}

//copy constructor
MusicTrack::MusicTrack(const MusicTrack& mt)
	: music(mt.music), name(mt.name) //copy the fields
{
	//no code needed
}

//move constructor
MusicTrack::MusicTrack(MusicTrack&& mt)
	: music(mt.music), name(mt.name) //move the fields
{
	mt.free(); //deallocate the temporary
}

//assignment operator
MusicTrack& MusicTrack::operator=(const MusicTrack& src) {
	this->music = src.music; //assign the music field
	this->name = src.name; //assign the name field
	return *this; //return the object
}

//move operator
MusicTrack& MusicTrack::operator=(MusicTrack&& src) {
	this->music = src.music; //move the music field
	this->name = src.name; //move the name field
	src.free(); //deallocate the temporary
	return *this; //return the object
}

//getter method

//getFileName method - returns the filename of the MusicTrack
const std::string& MusicTrack::getFileName() const {
	return this->name; //return the name field
}

//play/stop/pause/resume methods

//play method - plays the track in a loop
void MusicTrack::play() const {
	Mix_PlayMusic(this->music, -1); //play the music in a loop
}

//stop method - stops playing the track
void MusicTrack::stop() const {
	Mix_HaltMusic(); //stop the music
}

//pause method - pauses the track
void MusicTrack::pause() const {
	Mix_PauseMusic(); //pause the music
}

//resume method - resumes playing the track
void MusicTrack::resume() const {
	Mix_ResumeMusic(); //resume the music
}

//private free method - deallocates the object
void MusicTrack::free() {
	Mix_FreeMusic(this->music); //deallocate the music
	this->music = nullptr; //and zero it out
}

//end of implementation
