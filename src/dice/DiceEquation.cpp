/*
 * DiceEquation.cpp
 * Implements a class that represents a modified die roll
 * Created by Andrew Davis
 * Created on 3/13/2017
 * All rights reserved
 */

//include header
#include "DiceEquation.h"

//first constructor - constructs from a char string
DiceEquation::DiceEquation(const char* eqnString)
	: multiplier(0), die(nullptr), add(true), modifier(0), equationString(eqnString) //zero the fields and init the equation
{
	this->parseEquation(this->equationString); //parse the equation string and set the fields accordingly
}

//second constructor - constructs from a std::string object
DiceEquation::DiceEquation(std::string eqnString)
	: DiceEquation(eqnString.c_str()) //call the first constructor
{
	//no code needed
}

//third constructor - constructs from the individual components of a DiceEquation
DiceEquation::DiceEquation(int newMultiplier, Die* newDie, bool newAdd, int newModifier)
	: multiplier(newMultiplier), die(nullptr), add(newAdd), modifier(newModifier), equationString("") //init the fields
{
	this->die = new Die(*newDie); //init the die field
	std::stringstream ss; //buffer for creating the equation string
	char sym = this->add ? '+' : '-'; //get the symbol
	ss << this->multiplier << 'd' << this->die->getSideCount() << sym << this->modifier; //assemble the eqn
	this->equationString = ss.str(); //assign the equation string
}

//destructor
DiceEquation::~DiceEquation() {
	delete this->die; //deallocate the die field
	this->die = nullptr; //and zero it out
}

//copy constructor
DiceEquation::DiceEquation(const DiceEquation& de)
	: multiplier(de.multiplier), die(nullptr), add(de.add), modifier(de.modifier), equationString(de.equationString)
{
	if(de.die != nullptr) { //if the other die field isn't null
		this->die = new Die(*de.die); //then copy it into this die field
	}
}

//move constructor
DiceEquation::DiceEquation(DiceEquation&& de)
	: multiplier(de.multiplier), die(nullptr), add(de.add), modifier(de.modifier), equationString(de.equationString)
{
	if(de.die != nullptr) { //if the other die field isn't null
		this->die = new Die(*de.die); //then copy it into this die field
	}
	delete de.die; //deallocate the temporary's die field
	de.die = nullptr; //and zero it out
}

//assignment operator
DiceEquation& DiceEquation::operator=(const DiceEquation& src) {
	this->multiplier = src.multiplier; //assign the multiplier field
	if(src.die != nullptr) { //if the other die is not null
		*this->die = *src.die; //then assign the die field
	} else { //if it is
		delete this->die; //then deallocate this die
		this->die = nullptr; //and zero it out
	}
	this->add = src.add; //assign the add flag
	this->modifier = src.modifier; //assign the modifier field
	this->equationString = src.equationString; //assign the equation string field
	return *this; //return the object
}

//move operator
DiceEquation& DiceEquation::operator=(DiceEquation&& src) {
	this->multiplier = src.multiplier; //move the multiplier field
	if(src.die != nullptr) { //if the other die is not null
		*this->die = *src.die; //then move the die field
	} else { //if it is
		delete this->die; //then deallocate this die
		this->die = nullptr; //and zero it out
	}
	this->add = src.add; //move the add flag
	this->modifier = src.modifier; //move the modifier field
	this->equationString = src.equationString; //move the equation string field
	delete src.die; //deallocate the temporary's die field
	src.die = nullptr; //and zero it out
	return *this; //return the object
}

//getter methods

//getMultiplier method - returns the multiplier for the equation
int DiceEquation::getMultiplier() const {
	return this->multiplier; //return the multiplier field
}

//getSides method - returns the number of sides on the die referenced in the equation
int DiceEquation::getSides() const {
	return this->die->getSideCount(); //return the side count of the die object
}

//getModifier method - returns the modifier for the equation
int DiceEquation::getModifier() const {
	return this->modifier; //return the modifier field
}

//toString method - returns the equation string for the equation
std::string DiceEquation::toString() const {
	return this->equationString; //return the equation string field
}

//other methods

//evaluate method - evaluates the equation and returns the result
int DiceEquation::evaluate() {
	int accum = 0; //used to calculate the result
	for(int i = 0; i < this->multiplier; i++) { //loop on the multiplier
		this->die->roll(); //roll the die
		accum += this->die->getValue(); //add the value of the die to the accumulator
	}
	if(this->add) { //if we should add
		accum += this->modifier; //add the modifier to the accumulator
	} else { //if we shouldn't
		accum -= this->modifier; //subtract the modifier from the accumulator
	}
	return accum; //return the accumulator
}

//private methods

//parseEquation method - parses a string and derives a dice equation from it
void DiceEquation::parseEquation(std::string eqnToParse) {
	std::regex pattern("[0-9]+d[0-9]+((\\+|-)[0-9]+)?"); //get the pattern for verifying the dice equation string
	if(!std::regex_match(eqnToParse, pattern)) { //if the equation is invalid
		throw InvalidDiceEquationException(eqnToParse.c_str()); //then throw an exception
	}
	//declare variables to hold the extracted equation
	int mult, sides, mod; //the integer parts of the equation
	char sym, sign; //the character parts of the equation
	
	//declare regexes to determine which parts to extract
	std::regex partial("[0-9]+d[0-9]+"); //matches an equation without the modifier
	std::regex full("[0-9]+d[0-9]+(\\+|-)[0-9]+"); //matches an equation with the modifier

	//declare an object for extracting the variables
	std::istringstream iss(eqnToParse);

	//extract the variables
	if(std::regex_match(eqnToParse, partial)) { //if the equation matches the partial form
		iss >> mult; //extract the multiplier
		iss >> sym; //extract the symbol
		iss >> sides; //extract the side count
		if(!validateSideCount(sides)) { //if the side count is invalid
			throw InvalidDiceEquationException(eqnToParse.c_str()); //then throw an exception
		}
		this->multiplier = mult; //init the multiplier
		this->die = new Die(sides); //init the die
		this->add = true; //init the sign
		this->modifier = 0; //zero the modifier
	} else if(std::regex_match(eqnToParse, full)) { //if the equation matches the full form
		iss >> mult; //extract the multiplier
		iss >> sym; //extract the symbol
		iss >> sides; //extract the side count
		iss >> sign; //extract the sign
		iss >> mod; //extract the modifier
		if(!validateSideCount(sides)) { //if the side count is invalid
			throw InvalidDiceEquationException(eqnToParse.c_str()); //then throw an exception
		}
		this->multiplier = mult; //init the multiplier
		this->die = new Die(sides); //init the die
		this->add = (sign == '+' ? true : false); //init the sign
		this->modifier = mod; //zero the modifier
	} else { //if no match is found
		throw InvalidDiceEquationException(eqnToParse.c_str()); //throw an exception
	}
}

//end of implementation
