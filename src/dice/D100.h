/*
 * D100.h
 * Declares a class that represents a 100-sided die
 * Created by Andrew Davis
 * Created on 3/11/2017
 * All rights reserved
 */

//disallow reinclusion
#ifndef D100_H_INC
#define D100_H_INC

//include
#include "Die.h"

//class declaration
class D100 final : public Die
{
	//public fields and methods
	public:
		//first constructor - creates a D100 with a randomized value
		D100();

		//second constructor - creates a D100 with a set value
		explicit D100(int newValue); 

		//destructor
		~D100();

		//copy constructor
		D100(const D100& doh);

		//move constructor
		D100(D100&& doh);

		//assignment operator
		D100& operator=(const D100& src);

		//move operator
		D100& operator=(D100&& src);
	
	//no private fields
};

#endif
