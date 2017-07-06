/*
 * EnumEqnToken.h
 * Enumerates different die equation tokens
 * Created by Andrew Davis
 * Created on 6/26/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef ENUM_EQN_TOK_H
#define ENUM_EQN_TOK_H

//enum definition
enum class EnumEqnToken {
	NUM, //number
	D, //die operator
	PLUS, //addition operator
	MINUS, //subtraction operator
	EOL //end of line
};

#endif
