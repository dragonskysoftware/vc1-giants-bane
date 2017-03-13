/*
 * EventRegulator.cpp
 * Implements a singleton class that polls and passes events
 * Created by Andrew Davis
 * Created on 3/13/2017
 * Open source (GPL license)
 */

//include header
#include "EventRegulator.h"

//private constructor
EventRegulator::EventRegulator()
	: eventHandler(), pending(false) //init the fields
{
	//no code needed
}

//destructor
EventRegulator::~EventRegulator() {
	//no code needed
}

//getter methods

//static getInstance method - returns an instance of the EventRegulator class
EventRegulator& EventRegulator::getInstance() {
	static EventRegulator instance; //create the singleton instance
	return instance; //return the initialized instance
}

//getLastEvent method - returns the last event polled
SDL_Event EventRegulator::getLastEvent() const {
	return this->eventHandler; //return the event handler
}

//hasPendingEvents method - returns whether or not there are still events on the event stack
bool EventRegulator::hasPendingEvents() const {
	return this->pending; //return the pending field
}

//other methods

//nextEvent method - polls the next event on the event stack
void EventRegulator::nextEvent() {
	int more = SDL_PollEvent(&eventHandler); //poll the event and capture the return code
	this->pending = (more == 1 ? true : false); //assign the pending field
	if(this->eventHandler.type == SDL_QUIT) { //if the event handler detects a quit event
		GameDB::getInstance().setInt(OP_KEY, SHUTDOWN); //then set the operation state to shutdown
	}
}

//end of implementation
