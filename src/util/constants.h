/*
 * constants.h
 * Defines constants for the Giant's Bane RPG
 * Created by Andrew Davis
 * Created on 3/9/2017 
 * All rights reserved
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

//ability score constants
extern const int SCORE_MIN; //the minimum possible ability score
extern const int SCORE_MAX; //the maximum possible ability score
extern const char* N_STR; //the name of the strength stat
extern const char* N_DEX; //the name of the dexterity stat
extern const char* N_CON; //the name of the constitution stat
extern const char* N_TGT; //the name of the thought stat
extern const char* N_SOC; //the name of the social stat
extern const char* N_ARC; //the name of the arcana stat

#endif
