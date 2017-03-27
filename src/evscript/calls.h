/*
 * calls.h
 * Declares functions that represent EvScript calls to C++ game functions
 * Created by Andrew Davis
 * Created on 3/16/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef CALLS_H_INC
#define CALLS_H_INC

//includes
#include <SDL2/SDL.h>
#include "../util/constants.h"
#include "../data/GameDB.h"

//function prototypes
void call_shutdownGame(); //shuts down the game when called
void call_sleep(int seconds); //delays the game for a set number of seconds
void call_usleep(int mseconds); //delays the game for a set number of milliseconds

#endif
