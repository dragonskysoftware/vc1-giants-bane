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

//TODO: Add more calls

//end of implementation
