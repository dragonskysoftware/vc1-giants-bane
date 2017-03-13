/*
 * D4.h
 * Declares a class that represents a 4-sided die
 * Created by Andrew Davis
 * Created on 3/11/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef D4_H_INC
#define D4_H_INC

//include
#include "Die.h"

//class declaration
class D4 final : public Die
{
	//public fields and methods
	public:
		//first constructor - creates a D4 with a randomized value
		D4();

		//second constructor - creates a D4 with a set value
		explicit D4(int newValue); 

		//destructor
		~D4();

		//copy constructor
		D4(const D4& df);

		//move constructor
		D4(D4&& df);

		//assignment operator
		D4& operator=(const D4& src);

		//move operator
		D4& operator=(D4&& src);
	
	//no private fields
};

#endif
