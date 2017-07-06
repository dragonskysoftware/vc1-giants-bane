/*
 * strdup.h
 * Declares functions that duplicates character strings
 * Created by Andrew Davis
 * Created on 3/16/2017
 * All rights reserved
 */

//disallow reinclusion
#ifndef STRDUP_H_INC
#define STRDUP_H_INC

//include
#include <cstring>
#include <cstdlib>
#include <SDL2/SDL.h>

//function declarations
char* strdup(const char* str) noexcept; //duplicates the string using C++
char* C_strdup(const char* str) noexcept; //duplicates the string using C

#endif
