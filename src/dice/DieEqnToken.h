/*
 * DieEqnToken.h
 * Declares a class that represents a token for parsing die equations
 * Created by Andrew Davis
 * Created on 6/26/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef DIE_EQN_TOKEN_H
#define DIE_EQN_TOKEN_H

//includes
#include <string>
#include "EnumEqnToken.h"

//class declaration
class DieEqnToken final {
	//public fields and methods
	public:
		//constructor
		DieEqnToken(EnumEqnToken newType, const std::string& newValue);

		//destructor
		~DieEqnToken();

		//copy constructor
		DieEqnToken(const DieEqnToken& det);

		//move constructor
		DieEqnToken(DieEqnToken&& det);

		//assignment operator
		DieEqnToken& operator=(const DieEqnToken& src);

		//move operator
		DieEqnToken& operator=(DieEqnToken&& src);

		//getter methods

		EnumEqnToken getType() const; //returns the token's type
		const std::string& getValue() const; //returns its value

	//private fields and methods
	private:
		//fields
		EnumEqnToken type; //the type of the token
		std::string value; //the value of the token

};

#endif
