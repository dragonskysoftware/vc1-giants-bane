/*
 * D8.h
 * Declares a class that represents a 8-sided die
 * Created by Andrew Davis
 * Created on 3/11/2017
 * All rights reserved
 */

//disallow reinclusion
#ifndef D8_H_INC
#define D8_H_INC

//include
#include "Die.h"

//class declaration
class D8 final : public Die
{
	//public fields and methods
	public:
		//first constructor - creates a D8 with a randomized value
		D8();

		//second constructor - creates a D8 with a set value
		explicit D8(int newValue); 

		//destructor
		~D8();

		//copy constructor
		D8(const D8& de);

		//move constructor
		D8(D8&& de);

		//assignment operator
		D8& operator=(const D8& src);

		//move operator
		D8& operator=(D8&& src);
	
	//no private fields
};

#endif
