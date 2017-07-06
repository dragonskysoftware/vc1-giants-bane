/*
 * DieRoll.h
 * Declares a class that represents a roll of some dice
 * Created by Andrew Davis
 * Created on 6/29/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef DIE_ROLL_H_INC
#define DIE_ROLL_H_INC

//includes
#include <string>
#include "DieEquation.h"
#include "DieEqnLexer.h"
#include "DieEqnParser.h"
#include "DieEqnInterpreter.h"

//class declaration
class DieRoll final {
	//public fields and methods
	public:
		//constructor 1 - constructs from a string
		explicit DieRoll(const std::string& newEquation);

		//constructor 2 - constructs from a C string
		DieRoll(const char* newEquation);

		//constructor 3 - constructs from a die equation object
		explicit DieRoll(const DieEquation& newEquation);

		//destructor
		~DieRoll();

		//copy constructor
		DieRoll(const DieRoll& dr);

		//move constructor
		DieRoll(DieRoll&& dr);

		//assignment operator
		DieRoll& operator=(const DieRoll& src);

		//move operator
		DieRoll& operator=(DieRoll&& src);

		//other methods

		int roll() const; //executes the roll and returns the result

	//private fields and methods
	private:
		//field
		DieEquation equation; //the die equation for the roll
};

#endif
