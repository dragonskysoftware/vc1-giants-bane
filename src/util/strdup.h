/*
 * strdup.h
 * Declares a function that duplicates character strings
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

//function declaration
char* strdup(const char* str) noexcept;

#endif
