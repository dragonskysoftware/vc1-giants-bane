/*
 * AbilityScore.cpp
 * Implements a class that represents a player, creature, or NPC ability score
 * Created by Andrew Davis
 * Created on 3/14/2017
 * Open source (GPL license)
 */

//include header
#include "AbilityScore.h"

//constructor
AbilityScore::AbilityScore(EnumAbility newAbility, int newRawScore)
	: abilityType(newAbility), rawScore(newRawScore), modifier(newRawScore) //init the fields
{
	if(this->rawScore < SCORE_MIN || this->rawScore > SCORE_MAX) { //if the score is invalid
		throw InvalidAbilityScoreException(this->rawScore); //then throw an exception
	}
}

//destructor
AbilityScore::~AbilityScore() {
	//no code needed
}

//copy constructor
AbilityScore::AbilityScore(const AbilityScore& as)
	: abilityType(as.abilityType), rawScore(as.rawScore), modifier(as.modifier) //copy the fields
{
	//no code needed
}

//move constructor
AbilityScore::AbilityScore(AbilityScore&& as)
	: abilityType(as.abilityType), rawScore(as.rawScore), modifier(as.modifier) //move the fields
{
	//no code needed
}

//assignment operator
AbilityScore& AbilityScore::operator=(const AbilityScore& src) {
	this->abilityType = src.abilityType; //assign the ability type
	this->rawScore = src.rawScore; //assign the raw score
	this->modifier = src.modifier; //assign the modifier
	return *this; //return the object
}

//move operator
AbilityScore& AbilityScore::operator=(AbilityScore&& src) {
	this->abilityType = src.abilityType; //move the ability type
	this->rawScore = src.rawScore; //move the raw score
	this->modifier = src.modifier; //move the modifier
	return *this; //return the object
}

//getter methods

//getAbilityType method - returns the type of the AbilityScore as an EnumAbility instance
EnumAbility AbilityScore::getAbilityType() const {
	return this->abilityType; //return the ability type field
}

//getScore method - returns the internal score value of the AbilityScore
int AbilityScore::getScore() const {
	return this->rawScore; //return the score field
}

//getModifier method - returns the modifier field of the AbilityScore
const Modifier& AbilityScore::getModifier() const {
	return this->modifier; //return the modifier field
}

//getAbilityName method - calculates and returns a string representation of the AbilityScore's ability's name
std::string AbilityScore::getAbilityName() const {
	switch(this->abilityType) {
		case EnumAbility::STR: //strength
			{
				return std::string(N_STR); //return the global Strength string
			}
		case EnumAbility::DEX: //dexterity
			{
				return std::string(N_DEX); //return the global Dexterity string
			}
		case EnumAbility::CON: //constitution
			{
				return std::string(N_CON); //return the global Constitution string
			}
		case EnumAbility::TGT: //thought
			{
				return std::string(N_TGT); //return the global Thought string
			}
		case EnumAbility::SOC: //social
			{
				return std::string(N_SOC); //return the global Social string
			}
		case EnumAbility::ARC: //arcana
			{
				return std::string(N_ARC); //return the global Arcana string
			}
		default:
			{
				return std::string("ERROR NO ABILITY"); //return an error
			}
	}
}

//setter method

//setScore method - sets the score field of the AbilityScore
void AbilityScore::setScore(int newScore) {
	if(newScore < SCORE_MIN || newScore > SCORE_MAX) { //if the new score is out of range
		throw InvalidAbilityScoreException(newScore); //then throw an exception
	}
	this->rawScore = newScore; //assign the new score to the score field
	this->modifier.recalculate(this->rawScore); //and recalculate the modifier's value based on the new score
}

//end of implementation
