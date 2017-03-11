/*
 * D20.h
 * Declares a class that represents a 20-sided die
 * Created by Andrew Davis
 * Created on 3/11/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef D20_H_INC
#define D20_H_INC

//include
#include "Die.h"

//class declaration
class D20 final : public Die
{
	//public fields and methods
	public:
		//first constructor - creates a D20 with a randomized value
		D20();

		//second constructor - creates a D20 with a set value
		explicit D20(int newValue); 

		//destructor
		~D20();

		//copy constructor
		D20(const D20& dtz);

		//move constructor
		D20(D20&& dtz);

		//assignment operator
		D20& operator=(const D20& src);

		//move operator
		D20& operator=(D20&& src);
	
	//no private fields
};

#endif
