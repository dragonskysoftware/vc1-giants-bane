/*
 * EnumNodeType.h
 * Enumerates types of AST nodes for the EvScript interpreter
 * Created by Andrew Davis
 * Created on 3/16/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef ENUM_NODE_TYPE
#define ENUM_NODE_TYPE

//enum definition
enum class EnumNodeType {
	MATH, //math operators
	COMP, //comparison operator
	NEG, //negation operator
	EXP, //expression
	IF, //if statement
	WHL, //while statement
	REF, //symbol reference
	EQU, //assignment
	SYMS, //symbol list
	GAME, //game call
	FUNC, //built-in function call
	CALL, //user-defined function call
};

#endif
