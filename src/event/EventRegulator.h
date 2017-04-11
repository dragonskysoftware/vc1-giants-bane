/*
 * EventRegulator.h
 * Declares a singleton class that polls and passes events
 * Created by Andrew Davis
 * Created on 3/12/2017
 * All rights reserved
 */

//disallow reinclusion
#ifndef EVNT_REG_H_INC
#define EVNT_REG_H_INC

//includes
#include <SDL2/SDL.h>
#include "../data/GameDB.h"
#include "../util/constants.h"

//class declaration
class EventRegulator final {
	//public fields and methods
	public:
		//constructor is private

		//destructor
		~EventRegulator();

		//delete the copy constructor and other such methods
		EventRegulator(const EventRegulator& er) = delete;
		EventRegulator(EventRegulator&& er) = delete;
		EventRegulator& operator=(const EventRegulator& src) = delete;
		EventRegulator& operator=(EventRegulator&& src) = delete;

		//getter methods
		static EventRegulator& getInstance(); //returns the singleton instance of the EventRegulator class
		SDL_Event getLastEvent() const; //returns the last event polled
		bool hasPendingEvents() const; //returns true if there are pending events on the event stack

		//other method
		void nextEvent(); //polls the next event on the event stack
	
	//private fields and methods
	private:
		//constructor
		EventRegulator();

		//fields
		SDL_Event eventHandler; //the event handler for the event regulator
		bool pending; //are there pending events?

};

#endif
