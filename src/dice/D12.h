/*
 * D12.h
 * Declares a class that represents a 12-sided die
 * Created by Andrew Davis
 * Created on 3/11/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef D12_H_INC
#define D12_H_INC

//include
#include "Die.h"

//class declaration
class D12 final : public Die
{
	//public fields and methods
	public:
		//first constructor - creates a D12 with a randomized value
		D12();

		//second constructor - creates a D12 with a set value
		explicit D12(int newValue); 

		//destructor
		~D12();

		//copy constructor
		D12(const D12& dtt);

		//move constructor
		D12(D12&& dtt);

		//assignment operator
		D12& operator=(const D12& src);

		//move operator
		D12& operator=(D12&& src);
	
	//no private fields
};

#endif
