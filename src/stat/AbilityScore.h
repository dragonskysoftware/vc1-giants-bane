/*
 * AbilityScore.h
 * Declares a class that represents a player, creature, or NPC ability score
 * Created by Andrew Davis
 * Created on 3/14/2017
 * All rights reserved
 */

//disallow reinclusion
#ifndef SCORE_H_INC
#define SCORE_H_INC

//includes
#include <string>
#include <iostream>
#include "Modifier.h"
#include "EnumAbility.h"
#include "../util/constants.h"
#include "../except/InvalidAbilityScoreException.h"

//class declaration
class AbilityScore {
	//public fields and methods
	public:
		//constructor
		AbilityScore(EnumAbility newAbility, int newRawScore);

		//destructor
		virtual ~AbilityScore();

		//copy constructor
		AbilityScore(const AbilityScore& as);

		//move constructor
		AbilityScore(AbilityScore&& as);

		//assignment operator
		AbilityScore& operator=(const AbilityScore& src);

		//move operator
		AbilityScore& operator=(AbilityScore&& src);

		//getter methods
		EnumAbility getAbilityType() const; //returns the ability type as an enum instance
		int getScore() const; //returns the actual score
		const Modifier& getModifier() const; //returns the stored Modifier object
		std::string getAbilityName() const; //calculates and returns the name of the ability scored by this object

		//setter methods
		void setScore(int newScore); //sets the ability score for the object

		//save and load code 
		friend std::ostream& operator<<(std::ostream& os, const AbilityScore& as); //saves the AbilityScore to a stream
		friend std::istream& operator>>(std::istream& is, AbilityScore& as); //loads the AbilityScore from a stream

	//protected fields and methods
	protected:
		//fields
		EnumAbility abilityType; //the type of Ability this is
		int rawScore; //the actual score for the ability
		Modifier modifier; //the modifier for the ability score

};

#endif
