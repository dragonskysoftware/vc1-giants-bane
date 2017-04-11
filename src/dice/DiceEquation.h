/*
 * DiceEquation.h
 * Declares a class that represents a modified die roll
 * Created by Andrew Davis
 * Created on 3/13/2017
 * All rights reserved
 */

//disallow reinclusion
#ifndef DIE_EQN_H_INC
#define DIE_EQN_H_INC

//includes
#include <string>
#include <vector>
#include <sstream>
#include <regex>
#include "Die.h"
#include "D100.h"
#include "D20.h"
#include "D12.h"
#include "D10.h"
#include "D8.h"
#include "D6.h"
#include "D4.h"
#include "../util/functions.h"
#include "../except/InvalidDiceEquationException.h"

//class declaration
class DiceEquation final {
	//public fields and methods
	public:
		//first constructor - constructs from a character pointer
		DiceEquation(const char* eqnString);

		//second constructor - constructs from a std::string
		DiceEquation(std::string eqnString);

		//third constructor - constructs from the individual parts of a dice equation
		DiceEquation(int newMultiplier, Die* newDie, bool newAdd, int newModifier);

		//destructor
		~DiceEquation();

		//copy constructor
		DiceEquation(const DiceEquation& de);

		//move constructor
		DiceEquation(DiceEquation&& de);

		//assignment operator
		DiceEquation& operator=(const DiceEquation& src);

		//move operator
		DiceEquation& operator=(DiceEquation&& src);

		//getter methods
		int getMultiplier() const; //returns the equation's multiplier
		int getSides() const; //returns the sides on the equation's Die instance
		int getModifier() const; //returns the modifier, or the value added to the rolls
		std::string toString() const; //returns the equation string corresponding to the equation

		//other methods
		int evaluate(); //evaluates the equation and returns its result

	//private fields and methods
	private:
		//private methods
		void parseEquation(std::string eqnToParse); //parses a dice equation in string form

		//fields
		int multiplier; //the amount of times to roll the die
		Die* die; //a pointer to a Die object that is rolled to evaluate the equation
		bool add; //whether to add or subtract the modifier
		int modifier; //a number to add or subtract to the roll
		std::string equationString; //the actual equation in string form

};

#endif
