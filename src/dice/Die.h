/*
 * Die.h
 * Declares a class that acts as a superclass for more specific die classes
 * Created by Andrew Davis
 * Created on 3/11/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef DIE_H_INC
#define DIE_H_INC

//includes
#include <ctime>
#include <cstdlib>
#include "../except/InvalidStateException.h"

//class declaration
class Die {
	//public fields and methods
	public:
		//first constructor - initializes the Die with a given number of sides and a random value
		explicit Die(int newSides);

		//second constructor - initializes the Die with a given number of sides and a set value
		Die(int newSides, int newValue);

		//destructor
		virtual ~Die();

		//copy constructor
		Die(const Die& d);

		//move constructor
		Die(Die&& d);

		//assignment operator
		Die& operator=(const Die& src);

		//move operator
		Die& operator=(Die&& src);

		//getter methods
		int getSideCount() const; //returns the number of sides on the Die
		int getValue() const; //returns the value showing on the Die

		//other methods
		void roll(); //rolls the Die
	
	//protected fields and methods
	protected:
		//protected methods
		void seedRandomGenerator() const; //seeds the RNG for the Die

		//fields
		int sides; //the sides on the Die
		int value; //the value showing on the Die
};

#endif
