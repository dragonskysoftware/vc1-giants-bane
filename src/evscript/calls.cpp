/*
 * calls.cpp
 * Implements functions that represent EvScript calls to C++ game functions
 * Created by Andrew Davis
 * Created on 3/16/2017
 * Open source (GPL license)
 */

//include header
#include "calls.h"

//function implementations

//shutdownGame call - shuts down the game by writing to the operation state database entry
void call_shutdownGame() {
	GameDB::getInstance().setInt(OP_KEY, SHUTDOWN); //write a shutdown value to the operation state entry in the database
}

//sleep call - delays the game for a set number of seconds
void call_sleep(int seconds) {
	call_usleep(seconds * 1000); //call the other sleep function
}

//usleep call - delays the game for a set number of milliseconds
void call_usleep(int mseconds) {
	SDL_Delay(mseconds); //delay the given time
}

//end of implementation
