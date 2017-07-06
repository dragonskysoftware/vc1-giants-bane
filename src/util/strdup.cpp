/*
 * strdup.cpp
 * Implements a function that duplicates character strings
 * Created by Andrew Davis
 * Created on 3/16/2017
 * All rights reserved
 */

//include header
#include "strdup.h"

//strdup function implementation - duplicates a character string
char* strdup(const char* str) noexcept {
	size_t len = strlen(str) + 1; //get the length of the supplied string plus one
	char* ret = new char[len]; //allocate a character string with the calculated length
	strcpy(ret, str); //copy in the supplied string
	return ret; //return the duplicated, initialized string
}

//C_strdup function implementation - duplicates a character string
char* C_strdup(const char* str) noexcept {
	size_t len = strlen(str) + 1; //get the length of the supplied string plus 1
	char* ret = (char*)SDL_malloc(len * sizeof(char)); //allocate a character string with the calculated length
	if(ret) { //if the string is valid
		strcpy(ret, str); //copy in the supplied string
	}
	return ret; //return the string
}

//end of implementation
