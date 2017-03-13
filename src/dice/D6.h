/*
 * D6.h
 * Declares a class that represents a 6-sided die
 * Created by Andrew Davis
 * Created on 3/11/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef D6_H_INC
#define D6_H_INC

//include
#include "Die.h"

//class declaration
class D6 final : public Die
{
	//public fields and methods
	public:
		//first constructor - creates a D6 with a randomized value
		D6();

		//second constructor - creates a D6 with a set value
		explicit D6(int newValue); 

		//destructor
		~D6();

		//copy constructor
		D6(const D6& ds);

		//move constructor
		D6(D6&& ds);

		//assignment operator
		D6& operator=(const D6& src);

		//move operator
		D6& operator=(D6&& src);
	
	//no private fields
};

#endif
