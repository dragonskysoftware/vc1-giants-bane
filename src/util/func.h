/*
 * func.h
 * Declares utility functions for Dragons' Peak Cave
 * Created by Andrew Davis
 * Created on 6/26/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef FUNC_H_INC
#define FUNC_H_INC

//includes
#include <cstdio>
#include <string>

//function prototypes

//file functions
bool fileExistsAtPath(const char* path); //checks if a file exists
bool fileExistsAtPath(const std::string& path); //checks if a file exists

//character-checking functions
bool isAlpha(char c); //returns true if the argument is a letter
bool isDigit(char c); //returns true if the argument is a number
bool isSpace(char c); //returns true if the argument is a space

#endif
