/*
 * D10.h
 * Declares a class that represents a 10-sided die
 * Created by Andrew Davis
 * Created on 3/11/1017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef D10_H_INC
#define D10_H_INC

//include
#include "Die.h"

//class declaration
class D10 final : public Die
{
	//public fields and methods
	public:
		//first constructor - creates a D10 with a randomized value
		D10();

		//second constructor - creates a D10 with a set value
		explicit D10(int newValue); 

		//destructor
		~D10();

		//copy constructor
		D10(const D10& dtz);

		//move constructor
		D10(D10&& dtz);

		//assignment operator
		D10& operator=(const D10& src);

		//move operator
		D10& operator=(D10&& src);
	
	//no private fields
};

#endif
