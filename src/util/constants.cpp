/*
 * constants.cpp
 * Defines constants for the Giant's Bane RPG
 * Created by Andrew Davis
 * Created on 3/10/2017 
 * All rights reserved
 */

//include header
#include "constants.h"

//screen size constants
const int SCREEN_WIDTH = 860; //the width of the screen
const int SCREEN_HEIGHT = 700; //the height of the screen

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

//ability score constants
const int SCORE_MIN = 0; //the minimum possible ability score
const int SCORE_MAX = 30; //the maximum possible ability score
const char* N_STR = "Strength"; //the name of the strength stat
const char* N_DEX = "Dexterity"; //the name of the dexterity stat
const char* N_CON = "Constitution"; //the name of the constitution stat
const char* N_TGT = "Thought"; //the name of the thought stat
const char* N_SOC = "Social"; //the name of the social stat
const char* N_ARC = "Arcana"; //the name of the arcana stat

//end of definitions
