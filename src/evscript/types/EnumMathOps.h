/*
 * EnumMathOps.h
 * Enumerates math operations for EvScript
 * Created by Andrew Davis
 * Created on 3/21/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef ENUM_MATH_OPS
#define ENUM_MATH_OPS

//enum definition
enum class EnumMathOps {
	ADD, //a+b
	SUB, //a-b
	MPY, //a*b
	DIV, //a/b
	MOD, //a%b
	ABS, //|a|
	NEG //-a
};

#endif
