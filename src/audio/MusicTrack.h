/*
 * MusicTrack.h
 * Declares a class that represents a track of music
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
class MusicTrack final {
	//public fields and methods
	public:
		//constructor 1 - constructs from a C string
		explicit MusicTrack(const char* trackName);

		//constructor 2 - constructs from a std::string
		explicit MusicTrack(const std::string& trackName);

		//destructor
		~MusicTrack();

		//copy constructor
		MusicTrack(const MusicTrack& mt);

		//move constructor
		MusicTrack(MusicTrack&& mt);

		//assignment operator
		MusicTrack& operator=(const MusicTrack& src);

		//move operator
		MusicTrack& operator=(MusicTrack&& src);

		//getter method
		const std::string& getFileName() const; //returns the filename of the music track

		//play/stop/pause methods
		void play() const; //plays the track in a loop
		void stop() const; //stops the track
		void pause() const; //pauses the track
		void resume() const; //resumes playing the track

	//private fields and methods
	private:
		//method
		void free(); //deallocates the object

		//fields
		Mix_Music* music; //the music stored in the MusicTrack
		std::string name; //the filename of the music
};

#endif
