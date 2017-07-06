/*
 * func.cpp
 * Implements utility functions for Dragons' Peak Cave
 * Created by Andrew Davis
 * Created on 6/26/2017
 * Open source (GPL license)
 */

//include header
#include "func.h"

//function definitions

//fileExistsAtPath(const char*) function - returns whether a file exists
bool fileExistsAtPath(const char* path) {
	FILE* temp = fopen(path, "r"); //get a file handle for the path
	if(temp) { //if the file exists
		fclose(temp); //then close it
		return true; //and return true
	} else { //if the file does not exist
		return false; //then return false
	}
}

//fileExistsAtPath(const std::string&) function - returns if a file exists
bool fileExistsAtPath(const std::string& path) {
	return fileExistsAtPath(path.c_str()); //call the other function
}

//isAlpha function - returns if the argument is a letter
bool isAlpha(char c) {
	bool isLower = (c >= 'a' && c <= 'z'); //check for lowercase
	bool isUpper = (c >= 'A' && c <= 'Z'); //check for uppercase
	return (isLower || isUpper); //OR the two above checks
}

//isDigit function - returns if the argument is a digit
bool isDigit(char c) {
	return (c >= '0' && c <= '9'); //return a check for a digit
}

//isSpace function - returns if the argument is a space
bool isSpace(char c) {
	return c == ' '; //return a check for a space
}

//end of implementation
