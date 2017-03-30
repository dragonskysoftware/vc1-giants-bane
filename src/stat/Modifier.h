/*
 * Modifier.h
 * Declares a class that represents a statistic or skill modifier
 * Created by Andrew Davis
 * Created on 3/14/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef MODIF_H_INC
#define MODIF_H_INC

#include <cmath>
#include <iostream>
#include "../except/InvalidAbilityScoreException.h"
#include "../util/constants.h"

//class declaration
class Modifier {
	//public fields and methods
	public:
		//constructor
		explicit Modifier(int score);

		//destructor
		virtual ~Modifier();

		//copy constructor
		Modifier(const Modifier& m);

		//move constructor
		Modifier(Modifier&& m);

		//assignment operator
		Modifier& operator=(const Modifier& src);

		//move operator
		Modifier& operator=(Modifier&& src);

		//getter methods
		int getValue() const; //returns the value of the Modifier
		bool isPositive() const; //returns the sign of the Modifier

		//other method
		void recalculate(int newScore); //recalculates the Modifier's value based on a new ability score

		//save and load code
		friend std::ostream& operator<<(std::ostream& os, const Modifier& m); //saves the Modifier to a stream
		friend std::istream& operator>>(std::istream& is, Modifier& m); //loads the Modifier from a stream

	//protected fields and methods
	protected:
		//protected method
		void calculateValue(int score); //calculates a modifier value from an ability score
		//fields
		int value; //the modifier itself
};

#endif
