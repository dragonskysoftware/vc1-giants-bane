/*
 * constants.cpp
 * Defines constants for the Giant's Bane RPG
 * Created by Andrew Davis
 * Created on 3/10/2017 
 * Open source (GPL license)
 */

//include header
#include "constants.h"

//screen size constants
const int SCREEN_WIDTH = 640; //the width of the screen
const int SCREEN_HEIGHT = 480; //the height of the screen

//the header text for the game window
const char* WIN_HEADER = "Validian Chronicles I: Giant's Bane";

//the version string for the game
const char* VERSION = "0.1.0 alpha";

//the temporary message displayed during development
const char* DEV_MSG = "Giant's Bane is currently in development.";

//operation state constants
const int STARTING = 2; //the game is starting up
const int RUNNING = 1; //the game is running
const int SHUTDOWN = 0; //the game is shutting down
const int STOPPED = -1; //the game is stopped

//database key constants
const char* OP_KEY = "Operation"; //the database key for the operation state

//end of definitions
