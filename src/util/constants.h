/*
 * constants.h
 * Defines constants for the Giant's Bane RPG
 * Created by Andrew Davis
 * Created on 3/9/2017 
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef CONST_H_INC
#define CONST_H_INC

//screen size constants
extern const int SCREEN_WIDTH; //the width of the screen
extern const int SCREEN_HEIGHT; //the height of the screen

//the header text for the game window
extern const char* WIN_HEADER;

//the version string for the game
extern const char* VERSION;

//the temporary message displayed during development
extern const char* DEV_MSG;

//operation state constants
extern const int STARTING; //game is starting up
extern const int RUNNING; //game is running
extern const int SHUTDOWN; //game is shutting down
extern const int STOPPED; //game is off

//database key constants
extern const char* OP_KEY; //the key for the operation state DB entry

#endif
