/*
 * functions.h
 * Defines inline functions that support the Giant's Bane RPG
 * Created by Andrew Davis
 * Created on 3/9/2017
 * All rights reserved
 */

//disallow reinclusion
#ifndef FUNC_H_INC
#define FUNC_H_INC

//includes
#include <fstream>
#include <string>
#include "constants.h"
#include "../data/GameDB.h"

//first fileExistsAtPath function - returns whether or not a file exists at a path
inline bool fileExistsAtPath(const char* path) {
	std::ifstream ifs(path); //get a stream to check the path's validity
	return ifs.good(); //return whether the stream is good
}

//second fileExistsAtPath function - returns the same thing as the first
inline bool fileExistsAtPath(std::string path) {
	return fileExistsAtPath(path.c_str()); //call the other fileExistsAtPath function
}

//isNaN function - returns whether a character is not a number
inline bool isNaN(char test) {
	bool inv = (test >= '0' && test <= '9'); //get whether or not the character is a number
	return !inv; //and return the inverse of that calculation
}

//validateSideCount function - returns whether a number is a valid number of sides on a die
inline bool validateSideCount(int sides) {
	if(sides == 100) { //if there are 100 sides (percentile die)
		return true; //then return true (valid side count)
	}
	if(sides == 20) { //if there are 20 sides
		return true; //then return true (valid side count)
	}
	if((sides >= 4 && sides <= 12) && (sides % 2 == 0)) { //if the sides are either 4, 6, 8, 10, or 12
		return true; //then return true (valid side count)
	}
	return false; //invalid sides
}

//shutdownGame function - starts the shutdown process of the game
inline void shutdownGame() {
	GameDB::getInstance().setInt(OP_KEY, SHUTDOWN); //set the operation status field in the database to the shutdown value
}

#endif
