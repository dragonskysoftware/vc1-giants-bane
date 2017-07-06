/*
 * Die.h
 * Declares a class that represents a die with an arbitrary side count
 * Created by Andrew Davis
 * Created on 6/26/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef DIE_H_INC
#define DIE_H_INC

//includes
#include <cstdlib>
#include <ctime>
#include "../except/BadDieException.h"

//class declaration
class Die {
	//public fields and methods
	public:
		//constructor
		explicit Die(int numSides);

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
		
		int getSideCount() const; //returns the number of sides
		int getValue() const; //returns the value last rolled

		//other methods

		void roll(); //rolls the Die

	//protected fields and methods
	protected:
		//method
		void seedRNG(); //seeds the RNG for the Die

		//fields
		int sides; //the number of sides on the Die
		int value; //the value last rolled by the Die
};

#endif
