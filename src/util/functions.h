/*
 * functions.h
 * Defines inline functions that support the Giant's Bane RPG
 * Created by Andrew Davis
 * Created on 3/9/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef FUNC_H_INC
#define FUNC_H_INC

//includes
#include <fstream>
#include <string>

//first fileExistsAtPath function - returns whether or not a file exists at a path
inline bool fileExistsAtPath(const char* path) {
	std::ifstream ifs(path); //get a stream to check the path's validity
	return ifs.good(); //return whether the stream is good
}

//second fileExistsAtPath function - returns the same thing as the first
inline bool fileExistsAtPath(std::string path) {
	return fileExistsAtPath(path.c_str()); //call the other fileExistsAtPath function
}

#endif
